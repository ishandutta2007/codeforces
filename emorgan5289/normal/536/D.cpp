#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

template<typename T>
vector<T> dijkstra(vector<vector<pair<T, int>>> adj, int s) {

    const static T inf_T = numeric_limits<T>::max();
    int n = adj.size();
    vector<bool> vis(n, 0);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> heap;
    heap.push({0, s});
    vector<T> out(n, inf_T);

    while (!heap.empty()) {
        auto [c, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        out[i] = c;
        for (auto& [w, j] : adj[i])
            if (!vis[j])
                heap.push({c+w, j});
    }
    return out;
}

template<typename it1, typename it2, typename cmp = less<>>
void compress(it1 first, it1 last, it2 result, cmp ord = less<>()) {
    using T = typename iterator_traits<it1>::value_type;
    map<T, vector<it2>, cmp> m(ord);
    for (it1 i = first; i != last; i++)
        m[*i].push_back(result+(i-first));
    int t = 0;
    for (auto& [_, v] : m) {
        for (auto& i : v) *i = t;
        t++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    ll s, t; cin >> s >> t; s--, t--;
    vector<vector<pair<ll, int>>> adj(n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        adj[x].pb({w, y}), adj[y].pb({w, x});
    }

    auto cs = dijkstra(adj, s);
    auto ct = dijkstra(adj, t);
    compress(all(cs), cs.begin());
    compress(all(ct), ct.begin());

    vector<vector<int>> loc(n+1, vector<int>(n+1, 0));
    vector<vector<ll>> val(n+1, vector<ll>(n+1, 0));

    for (int i = 0; i < n; i++) {
        loc[cs[i]][ct[i]] = 1;
        val[cs[i]][ct[i]] += a[i];
    }

    for (auto& row : loc) debug(row);
    debug();
    for (auto& row : val) debug(row);
    debug();

    vector<vector<int>> has_row(loc), has_col(loc);
    vector<vector<ll>> val_row(val), val_col(val);
    vector<vector<ll>> dp_s(n+1, vector<ll>(n+1, -inf_ll));
    vector<vector<ll>> dp_t(n+1, vector<ll>(n+1, -inf_ll));
    for (int i = 0; i < n+1; i++)
        dp_s[i][n] = dp_s[n][i] = dp_t[i][n] = dp_t[n][i] = 0;

    for (int i = n-1; i >= 0; i--)
        for (int j = n-1; j >= 0; j--) {
            has_row[i][j] |= has_row[i][j+1];
            has_col[i][j] |= has_col[i+1][j];
            val_row[i][j] += val_row[i][j+1];
            val_col[i][j] += val_col[i+1][j];

            if (!has_row[i][j]) {
                dp_s[i][j] = dp_s[i+1][j];
                dp_t[i][j] = dp_t[i+1][j];
                continue;
            }
            if (!has_col[i][j]) {
                dp_s[i][j] = dp_s[i][j+1];
                dp_t[i][j] = dp_t[i][j+1];
                continue;
            }

            dp_s[i][j] = val_row[i][j]+max(-dp_t[i+1][j], dp_s[i+1][j]);
            dp_t[i][j] = val_col[i][j]+max(-dp_s[i][j+1], dp_t[i][j+1]);
        }

    for (auto& row : dp_s) debug(row);
    debug();
    for (auto& row : dp_t) debug(row);
    debug();

    debug(dp_s[0][0]);
    if (dp_s[0][0] > 0)
        cout << "Break a heart\n";
    if (dp_s[0][0] < 0)
        cout << "Cry\n";
    if (dp_s[0][0] == 0)
        cout << "Flowers\n";
}