#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 407;
const int Inf = 1e9;

int d[N][N];
double cnt[N];
double mx[N];
bool us[N];

vector <int> g[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = Inf;
        }
    }
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[u][v] = d[v][u] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        vector <vector <int>> who(n);
        for (int k = 0; k < n; ++k) {
            who[d[i][k]].push_back(k);
        }
        double P = 0;
        for (auto v : who) {
            if (v.empty()) continue;
            for (int i = 0; i < n; ++i) us[i] = 0;

            double best = (double)1 / (int)v.size();
            vector <int> intr;

            for (int x : v) {
                for (int y : g[x]) {
                    cnt[y] += 1.0 / v.size() / g[x].size();
                    if (!us[y]) {
                        intr.push_back(y);
                        us[y] = 1;
                    }
                }
            }

            for (int j = 0; j < n; ++j) {
                double cur = 0;
                for (int u : intr) {
                    mx[d[u][j]] = max(mx[d[u][j]], cnt[u]);
                }
                for (int u : intr) {
                    cur += mx[d[u][j]];
                    mx[d[u][j]] = 0;
                }
                best = max(best, cur);
            }

            for (int x : v) {
                for (int y : g[x]) {
                    cnt[y] = 0;
                }
            }

            P += (best * v.size()) / n;
        }
        ans = max(ans, P);
    }
    cout << ans << '\n';
}