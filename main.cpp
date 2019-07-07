#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

// https://leetcode.com/problems/pascals-triangle-ii/

// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int level = 1;
        vector<int> evenRow(rowIndex + 1, 1);
        vector<int> oddRow(rowIndex + 1, 1);
        while (level < rowIndex) {
            for (int i = 1; i < level + 1; ++i) {
                // alternate btw odd and even row construction
                if (level % 2)
                    oddRow[i] = evenRow[i - 1] + evenRow[i];
                else
                    evenRow[i] = oddRow[i - 1] + oddRow[i];
            }
            ++level;
        }
        return rowIndex % 2 ? evenRow : oddRow;
    }
};

void test1() {
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    cout << "[1] ? " << Solution().getRow(0) << endl;
    cout << "[1,1] ? " << Solution().getRow(1) << endl;
    cout << "[1,3,3,1] ? " << Solution().getRow(3) << endl;
    cout << "[1,4,6,4,1] ? " << Solution().getRow(4) << endl;
}

void test2() {

}

void test3() {

}