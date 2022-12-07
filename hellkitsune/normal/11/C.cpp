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

int t, n, m;
char s[256][256];
bool vis[256][256];
vector<PII> v;
int minx, maxx, miny, maxy;

const int INF = 1e9;

void dfs(int x, int y) {
    vis[x][y] = true;
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
    v.pb(mp(x, y));
    for (int i = -1; i < 2; ++i) for (int j = -1; j < 2; ++j)
        if (s[x + i][y + j] == '1' && !vis[x + i][y + j])
            dfs(x + i, y + j);
}

int ans;

int main() {
    scanf("%d", &t);
    REP(test, t) {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
        REP(i, n + 2) s[i][0] = s[i][m + 1] = '0';
        REP(i, m + 2) s[0][i] = s[n + 1][i] = '0';
        REP(i, n + 2) REP(j, m + 2)
            vis[i][j] = false;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '1' && !vis[i][j]) {
                minx = miny = INF;
                maxx = maxy = -INF;
                v.clear();
                dfs(i, j);
                if (maxx != minx && maxx - minx == maxy - miny) {
                    if ((int)v.size() == (maxx - minx) * 4) {
                        bool flag = true;
                        REP(i, v.size()) {
                            if (v[i].first != minx && v[i].first != maxx && v[i].second != miny && v[i].second != maxy) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) ++ans;
                    }
                    if ((maxx - minx) % 2 == 0 && (int)v.size() == (maxx - minx) * 2) {
                        int midx = (maxx + minx) >> 1;
                        int midy = (maxy + miny) >> 1;
                        bool flag = true;
                        REP(i, v.size()) {
                            if (abs(v[i].first - midx) + abs(v[i].second - midy) != midx - minx) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) ++ans;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}