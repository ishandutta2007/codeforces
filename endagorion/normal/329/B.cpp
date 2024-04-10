#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

char f[1001][1001];
int d[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int R, C;
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; ++i) {
        scanf("%s", f[i]);
    }
    int ex, ey, sx, sy;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            d[i][j] = 1e9;
            if (f[i][j] == 'E') {
                ex = i;
                ey = j;
            }
            if (f[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    vector< pair<int, int> > q;
    q.pb(mp(ex, ey));
    d[ex][ey] = 0;
    int cur = 0;
    while (cur < q.size()) {
        int x = q[cur].first, y = q[cur].second;
        ++cur;
        for (int dd = 0; dd < 4; ++dd) {
            int xx = x + dx[dd], yy = y + dy[dd];
            if (xx < 0 || xx >= R || yy < 0 || yy >= C || f[xx][yy] == 'T' || d[xx][yy] < 1e9) {
                continue;
            }
            d[xx][yy] = d[x][y] + 1;
            q.pb(mp(xx, yy));
        }
    }

    int ans = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (d[i][j] <= d[sx][sy] && f[i][j] >= '0' && f[i][j] <= '9') {
                ans += f[i][j] - '0';
            }
        }
    }
    cout << ans << '\n';

	return 0;
}