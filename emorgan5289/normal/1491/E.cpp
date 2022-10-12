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

const int N = 2e5+5;
int f[N], v[N], s[N];
vector<array<int, 2>> adj[N];

void dfs(int i, int k, int n, vector<array<int, 3>>& c) {
    s[i] = 1;
    for (auto& [t, j] : adj[i])
        if (!v[t] && t != k)
            dfs(j, t, n, c), s[i] += s[j];
    if (s[i] == f[f[n]] || s[i] == f[n])
        c.pb({k, i, s[i]});
}

bool solve(int i, int n) {
    if (n <= 3) return 1;
    vector<array<int, 3>> c;
    dfs(i, -1, n, c);
    if (c.size() == 0) return 0;
    else {
        v[c[0][0]] = 1;
        bool r = solve(i, n-c[0][2]) && solve(c[0][1], c[0][2]);
        v[c[0][0]] = 0;
        return r;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb({i, y}), adj[y].pb({i, x});
    }
    int a = 1, b = 1;
    while (b < N)
        f[b] = a, b += a, a = b-a;
    cout << (f[n] && solve(0, n) ? "YES" : "NO") << "\n";
}