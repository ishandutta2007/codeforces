#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;
const int Inf = 1e18;

vector <pair <int, int>> g[N];
vector <int> num[N];

int d[N];

vector <int> kek;

void dijkstra() {
    for (int i = 0; i < N; ++i) d[i] = Inf;
    d[0] = 0;
    set <pair <int, int>> q;
    q.insert({0, 0});
    while (!q.empty()) {
        auto p = *q.begin();
        int u = p.second;
        q.erase(q.begin());
        for (int i = 0; i < g[u].size(); ++i) {
            auto p = g[u][i];
            int v = p.first;
            int w = p.second;
            if (d[v] > d[u] + w) {
                q.erase({d[v], v});
                d[v] = d[u] + w;
                q.insert({d[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        num[u].push_back(i);
        num[v].push_back(i);
    }
    dijkstra();
    vector <int> id;
    for (int i = 0; i < n; ++i) id.push_back(i);
    sort(id.begin(), id.end(), [&] (int i, int j) {
        return d[i] < d[j];
    });
    vector <bool> mark(n);
    mark[0] = 1;
    for (auto u : id) {
        if (!mark[u]) continue;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].first;
            int w = g[u][i].second;
            if (!mark[v] && d[v] == d[u] + w && kek.size() < k) {
                mark[v] = 1;
                kek.push_back(num[u][i]);
            }
        }
    }
    cout << kek.size() << '\n';
    for (auto x : kek) {
        cout << x + 1 << ' ';
    }
}