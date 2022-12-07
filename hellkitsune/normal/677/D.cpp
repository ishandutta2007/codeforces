#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, p;
int a[300][300];
int S;
vector<PII> v[90000];
vector<int> d[90000];
const int INF = 1e9;
queue<PII> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<PII> qq[2222];

int main() {
    scanf("%d%d%d", &n, &m, &p);
    REP(i, n) REP(j, m) {
        int x;
        scanf("%d", &x), --x;
        v[x].pb(mp(i, j));
    }
    S = n * m;
    REP(i, p) {
        d[i].resize(v[i].size(), INF);
    }
    REP(i, v[0].size()) {
        d[0][i] = v[0][i].first + v[0][i].second;
    }
    REP(z, p - 1) {
        int sz = v[z].size() * v[z + 1].size();
        if (sz <= S) {
            REP(i, v[z].size()) REP(j, v[z + 1].size()) {
                d[z + 1][j] = min(d[z + 1][j], d[z][i] +
                    abs(v[z][i].first - v[z + 1][j].first) + abs(v[z][i].second - v[z + 1][j].second));
            }
        } else {
            REP(i, n) REP(j, m) a[i][j] = INF;
            int mn = INF;
            for (int x : d[z]) mn = min(mn, x);
            REP(i, d[z].size()) if (d[z][i] == mn) {
                a[v[z][i].first][v[z][i].second] = mn;
                q.push(v[z][i]);
            } else {
                qq[d[z][i] - mn].pb(v[z][i]);
            }
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for (PII p : qq[a[y][x] - mn + 1]) {
                    int yy = p.first;
                    int xx = p.second;
                    if (a[yy][xx] == INF) {
                        a[yy][xx] = a[y][x] + 1;
                        q.push(mp(yy, xx));
                    }
                }
                REP(i, 4) {
                    int yy = y + dy[i];
                    if (yy < 0 || yy >= n) continue;
                    int xx = x + dx[i];
                    if (xx < 0 || xx >= m || a[yy][xx] != INF) continue;
                    a[yy][xx] = a[y][x] + 1;
                    q.push(mp(yy, xx));
                }
            }
            REP(i, v[z + 1].size()) {
                d[z + 1][i] = a[v[z + 1][i].first][v[z + 1][i].second];
            }
            REP(i, d[z].size()) if (d[z][i] != mn) {
                qq[d[z][i] - mn].clear();
            }
        }
    }
    printf("%d\n", d[p - 1][0]);
    return 0;
}