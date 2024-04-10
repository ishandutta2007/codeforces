#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

bool vis[205][205] = {};
string s;

int main() {
    int x = 102, y = 102;
    vis[x][y] = true;
    cin >> s;
    REP(i, s.length()) {
        int oldx = x, oldy = y;
        if (s[i] == 'L') --x;
        else if (s[i] == 'R') ++x;
        else if (s[i] == 'U') --y;
        else ++y;
        if (vis[x][y]) {
            cout << "BUG" << endl;
            return 0;
        }
        vis[oldx - 1][oldy] = true;
        vis[oldx + 1][oldy] = true;
        vis[oldx][oldy - 1] = true;
        vis[oldx][oldy + 1] = true;
    }
    cout << "OK" << endl;
    return 0;
}