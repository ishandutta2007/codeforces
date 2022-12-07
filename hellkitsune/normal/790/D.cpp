#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[2][300005];
int nx[3][300005];
int tr[3][20][300005];
map<LL, int> last;
int d[300005] = {};

inline void upd(int &x, int y) {
    x = max(x, y);
}

PII ma[300005][2];

int main() {
    scanf("%d", &n);
    forn(i, 2) forn(j, n) {
        scanf("%d", a[i] + j);
    }
    forn(i, 3) {
        int mask = i + 1;
        forn(j, n + 2) {
            nx[i][j] = n + 1;
        }
        last.clear();
        last[0] = n;
        LL cur = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (mask & 1) {
                cur += a[0][j];
            }
            if (mask & 2) {
                cur += a[1][j];
            }
            auto it = last.find(cur);
            if (it == last.end()) {
                last[cur] = j;
            } else {
                nx[i][j] = it->second;
                it->second = j;
            }
        }
    }
    forn(i, 3) for (int j = n - 1; j >= 0; --j) {
        nx[i][j] = min(nx[i][j], nx[i][j + 1]);
    }
    forn(i, 3) {
        forn(j, n + 2) tr[i][0][j] = nx[i][j];
        forn(p, 19) {
            forn(j, n + 2) {
                tr[i][p + 1][j] = tr[i][p][tr[i][p][j]];
            }
        }
    }
    memset(ma, -1, sizeof ma);
    int ans = 0;
    forn(i, n) {
        forn(j, 3) if (nx[j][i] <= n) {
            upd(d[nx[j][i]], d[i] + 1);
            upd(ans, d[i] + 1);
        }
        upd(d[i + 1], d[i]);
        if (nx[0][i] <= n) {
            if (ma[i][0].second < d[i] + 1 || (ma[i][0].second == d[i] + 1 && ma[i][0].first > nx[0][i])) {
                ma[i][0] = mp(nx[0][i], d[i] + 1);
            }
            upd(ans, d[i] + 1);
        }
        if (nx[1][i] <= n) {
            if (ma[i][1].second < d[i] + 1 || (ma[i][1].second == d[i] + 1 && ma[i][1].first > nx[1][i])) {
                ma[i][1] = mp(nx[1][i], d[i] + 1);
            }
            upd(ans, d[i] + 1);
        }
        forn(z, 2) {
            int y = z ^ 1;
            if (ma[i][z].first != -1) {
                PII p = ma[i][z];
                int pos = i;
                int res = p.second;
                for (int lg = 19; lg >= 0; --lg) {
                    if (tr[y][lg][pos] <= p.first) {
                        res += 1 << lg;
                        pos = tr[y][lg][pos];
                    }
                }
                upd(d[p.first], res);
                upd(ans, res);
                if (pos != p.first && nx[y][pos] <= n) {
                    int ind = nx[y][pos];
                    int val = res + 1;
                    if (val > ma[p.first][y].second || (val == ma[p.first][y].second && ind < ma[p.first][y].first)) {
                        ma[p.first][y] = mp(ind, val);
                    }
                    upd(ans, val);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}