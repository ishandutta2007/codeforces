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

const ll N = 1e5+5;

vector<pair<ll, ll>> adj[N];
ll c[N], n, m, k;

bool vis[N];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> heap;

void relax_weights() {
    fill(vis, vis+n, 0);
    for (ll i = 0; i < n; i++)
        heap.push({c[i], i});
    while (!heap.empty()) {
        auto [x, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1, c[i] = x;
        for (auto& [w, j] : adj[i])
            if (!vis[j])
                heap.push({x+w, j});
    }
}

vector<ll> p;
ll c_tmp[N];

ll inter(ll i, ll j) {
    return (i*i - j*j + c[i] - c[j]) / (2*i - 2*j);
}

void relax_flights() {
    p.clear();
    for (ll i = 0; i < n; i++) {
        while (p.size() > 1 && inter(p.back(), i) <= inter(p[p.size()-2], p.back()))
            p.pop_back();
        p.push_back(i);
        debug(p);
    }
    for (ll i = 0; i < p.size(); i++) {
        ll l = i == 0 ? 0 : max(0ll, inter(p[i-1], p[i])+1);
        ll r = i+1 == p.size() ? n-1 : min(n-1, inter(p[i], p[i+1]));
        for (ll j = l; j <= r; j++)
            c_tmp[j] = c[p[i]] + (j-p[i])*(j-p[i]);
        debug(i, l, r);
    }
    copy(c_tmp, c_tmp+n, c);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        ll w; cin >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    for (int i = 1; i < n; i++)
        c[i] = inf_ll;
    relax_weights();
    for (int i = 0; i < k; i++) {
        relax_flights();
        relax_weights();
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << " \n"[i == n-1];
}