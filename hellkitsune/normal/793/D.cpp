#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n, k, m;
int dist[80][80];
int d[80][80], e[80][80], nd[80][80], ne[80][80];

int main() {
    scanf("%d%d%d", &n, &k, &m);
    forn(i, n) forn(j, n) {
        dist[i][j] = INF;
    }
    forn(i, m) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        dist[from][to] = min(dist[from][to], w);
    }
    forn(i, n) forn(j, n) {
        d[i][j] = e[i][j] = INF;
    }
    forn(i, n) {
        d[i][n - 1] = 0;
        e[i][0] = 0;
    }
    forn(_, k - 1) {
        forn(i, n) forn(j, n) {
            nd[i][j] = ne[i][j] = INF;
        }
        forn(i, n) forn(j, n) {
            if (d[i][j] == INF) continue;
            for (int k = i + 1; k <= j; ++k) {
                nd[k][j] = min(nd[k][j], d[i][j] + dist[i][k]);
                ne[k][i + 1] = min(ne[k][i + 1], d[i][j] + dist[i][k]);
            }
        }
        forn(i, n) forn(j, n) {
            if (e[i][j] == INF) continue;
            for (int k = i - 1; k >= j; --k) {
                nd[k][i - 1] = min(nd[k][i - 1], e[i][j] + dist[i][k]);
                ne[k][j] = min(ne[k][j], e[i][j] + dist[i][k]);
            }
        }
        memcpy(d, nd, sizeof d);
        memcpy(e, ne, sizeof e);
    }
    int ans = INF;
    forn(i, n) forn(j, n) {
        ans = min(ans, d[i][j]);
        ans = min(ans, e[i][j]);
    }
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}