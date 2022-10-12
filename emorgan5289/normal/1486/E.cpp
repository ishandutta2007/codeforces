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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2e5+5, K = 50;
vector<array<ll, 2>> adj[N];
ll cc[N][K+1];
bool v[N][K+1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        ll x, y, w; cin >> x >> y >> w; x--, y--;
        adj[x].pb({w, y}), adj[y].pb({w, x});
    }
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> q;
    q.push({0, 0, 0});
    for (int i = 0; i < N; i++)
        fill(cc[i], cc[i]+K+1, inf_ll);
    cc[0][0] = 0;
    while (!q.empty()) {
        auto [c, i, x] = q.top(); q.pop();
        debug(c, i, x, cc[i][x]);
        if (c != cc[i][x]) continue;
        for (auto& [w, j] : adj[i]) {
            if (x == 0 && c < cc[j][w]) {
                cc[j][w] = c;
                q.push({cc[j][w], j, w});
            }
            if (x != 0 && c+(w+x)*(w+x) < cc[j][0]) {
                cc[j][0] = c+(w+x)*(w+x);
                q.push({cc[j][0], j, 0});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << (cc[i][0] == inf_ll ? -1 : cc[i][0]) << " \n"[i == n-1];
}