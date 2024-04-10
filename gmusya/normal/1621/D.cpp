#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
const ll INF = 1e18;

int n;

int f(int x, int y) {
    return 2 * n * x + y;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> mx = {1, 0, -1, 0};
    vector<int> my = {0, 1, 0, -1};
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<ll>> a(2 * n, vector<ll>(2 * n));
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < 2 * n; ++j) {
                cin >> a[i][j];
            }
        }
        ll ans = 0;
        for (int i = n; i < 2 * n; ++i) {
            for (int j = n; j < 2 * n; ++j) {
                ans += a[i][j];
            }
        }
        vector<vector<pair<int, ll>>> g(4 * n * n);
        for (int x = 0; x < 2 * n; ++x) {
            for (int y = 0; y < 2 * n; ++y) {
                for (int j = 0; j < 4; ++j) {
                    int new_x = x + mx[j];
                    int new_y = y + my[j];
                    if (new_x == -1) {
                        new_x += 2 * n;
                    }
                    if (new_y == -1) {
                        new_y += 2 * n;
                    }
                    if (new_x == 2 * n) {
                        new_x -= 2 * n;
                    }
                    if (new_y == 2 * n) {
                        new_y -= 2 * n;
                    }
                    g[f(x, y)].emplace_back(f(new_x, new_y), a[new_x][new_y]);
                }
            }
        }
        vector<ll> d(4 * n * n, INF);
        d[0] = 0;
        set<pair<ll, int>> s;
        for (int v = 0; v < 4 * n * n; ++v) {
            s.insert({d[v], v});
        }
        while (!s.empty()) {
            int v = s.begin()->second;
            s.erase(s.begin());
            for (auto& now : g[v]) {
                int u = now.first;
                ll w = now.second;
                if (d[v] + w < d[u]) {
                    s.erase({d[u], u});
                    d[u] = d[v] + w;
                    s.insert({d[u], u});
                }
            }
        }
        ll cur = min({a[n - 1][n], a[n][n - 1], a[n - 1][2 * n - 1], a[2 * n - 1][n - 1], a[n][0], a[0][n], a[0][2 * n - 1], a[2 * n - 1][0]});
        cout << ans + cur << '\n';
    }
    return 0;
}

/*
1
2
0 0 4 2
0 0 2 4
4 2 4 2
2 4 2 4

 */