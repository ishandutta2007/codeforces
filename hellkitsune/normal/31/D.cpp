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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

bool hor[105][105] = {}, ver[105][105] = {};
int w, h, n;
vector<int> ans;
bool used[105][105] = {};

int dfs(int y, int x) {
    int ret = 1;
    used[y][x] = true;
    if (y > 0 && !hor[y][x] && !used[y - 1][x]) ret += dfs(y - 1, x);
    if (y < h - 1 && !hor[y + 1][x] && !used[y + 1][x]) ret += dfs(y + 1, x);
    if (x > 0 && !ver[y][x] && !used[y][x - 1]) ret += dfs(y, x - 1);
    if (x < w - 1 && !ver[y][x + 1] && !used[y][x + 1]) ret += dfs(y, x + 1);
    return ret;
}

int main() {
    scanf("%d%d%d", &w, &h, &n);
    REP(i, n) {
        int x, y, xx, yy;
        scanf("%d%d%d%d", &x, &y, &xx, &yy);
        if (x == xx) {
            if (y > yy) swap(y, yy);
            for (int j = y; j < yy; ++j)
                ver[j][x] = true;
        } else {
            if (x > xx) swap(x, xx);
            for (int j = x; j < xx; ++j)
                hor[y][j] = true;
        }
    }
    REP(i, h) REP(j, w) if (!used[i][j]) ans.pb(dfs(i, j));
    sort(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}