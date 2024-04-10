#include <bits/stdc++.h>
using namespace std;

#define inf 100000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1005;
const int maxk = 45;
int a[maxn][maxn], c[maxn][maxn][maxk], e[maxk][maxk];
int cost[maxk];

#define inrange(i, j) (i >= 0 && j >= 0 && i < n && j < m)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j]; a[i][j]--;
        }

    for (int t = 0; t < k; t++) {
        for (int i = 0; i < k; i++)
            e[t][i] = inf;
        deque<pair<int, int>> d;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == t) {
                    c[i][j][t] = 0;
                    d.pb({i, j});
                } else {
                    c[i][j][t] = inf;
                }
            }
        while (!d.empty()) {
            int i, j; tie(i, j) = d.front(); d.pop_front();
            if (inrange(i+1, j) && c[i+1][j][t] == inf) {
                c[i+1][j][t] = c[i][j][t]+1;
                d.pb({i+1, j});
            }
            if (inrange(i-1, j) && c[i-1][j][t] == inf) {
                c[i-1][j][t] = c[i][j][t]+1;
                d.pb({i-1, j});
            }
            if (inrange(i, j+1) && c[i][j+1][t] == inf) {
                c[i][j+1][t] = c[i][j][t]+1;
                d.pb({i, j+1});
            }
            if (inrange(i, j-1) && c[i][j-1][t] == inf) {
                c[i][j-1][t] = c[i][j][t]+1;
                d.pb({i, j-1});
            }
            e[t][a[i][j]] = min(e[t][a[i][j]], c[i][j][t]+2);
        }
    }
    for (int i = 0; i < k; i++)
        e[i][i] = 1;

    for (int t = 0; t < k; t++)
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                e[i][j] = min(e[i][j], e[i][t]+e[t][j]-1);

    // for (int i = 0; i < k; i++)
    //     for (int j = 0; j < k; j++)
    //         if (e[i][j] < inf) debug(i, j, e[i][j]);

    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int out = abs(x1-x2)+abs(y1-y2);
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                out = min(out, e[i][j]+c[x1-1][y1-1][i]+c[x2-1][y2-1][j]);
        cout << out << "\n";
    }
}