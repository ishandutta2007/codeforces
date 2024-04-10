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

const int N = 150;
vector<bitset<N>> adj(N);
bitset<N> cur;
ll n, m;

// O(n^2)
ll bfs() {
    vector<ll> c(n, inf_ll);
    queue<int> q;
    for (int i = 0; i < N; i++)
        if (cur[i])
            c[i] = 0, q.push(i);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (i == n-1) return c[i];
        for (int j = 0; j < N; j++)
            if (adj[i][j] && c[j] == inf_ll)
                c[j] = c[i]+1, q.push(j);
    }
    return inf_ll;
}

// O(n^3/32)
auto mul(vector<bitset<N>> a, vector<bitset<N>> b) {
    debug(a, b);
    vector<bitset<N>> c(N), d(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            c[i][j] = b[j][i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            d[i][j] = (a[i]&c[j]).any();
    debug(d);
    return d;
}

// O(n^3/32 * logk)
auto exp(vector<bitset<N>> a, ll k) {
    vector<bitset<N>> b(N);
    for (int i = 0; i < N; i++)
        b[i][i] = 1;
    for (ll i = 1; i <= k; i <<= 1) {
        if (k&i) b = mul(b, a);
        a = mul(a, a);
    }
    return b;
}

auto apply(vector<bitset<N>> a, bitset<N> x) {
    debug(a, x);
    bitset<N> y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[i][j] && x[i]) y[j] = 1;
    return y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<array<ll, 3>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
        e[i][1]--, e[i][2]--;
    }
    cur[0] = 1;
    sort(all(e));
    ll ans = inf_ll;
    ll pd = 0;
    for (auto& [d, x, y] : e) {
        debug(d, x, y);
        cur = apply(exp(adj, d-pd), cur);
        debug(cur);
        pd = d;
        adj[x][y] = 1;
        cmin(ans, d+bfs());
    }
    if (ans == inf_ll)
        cout << "Impossible\n";
    else
        cout << ans << "\n";
}