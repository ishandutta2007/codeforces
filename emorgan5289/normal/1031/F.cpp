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

const int N = 1e6+5, K = 300;
int sp[N];
vector<vector<int>> d, adj;
vector<int> v;
map<vector<int>, int> m;
vector<int> r;

void dfs(int p, int x) {
    if (p*x >= K) return;
    r.pb(x);
    m[r] = d.size();
    d.pb(r), v.pb(p*x);
    dfs(p*x, x);
    r.pop_back();
    dfs(p, x+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = N-1; i > 1; i--)
        for (int j = i; j < N; j += i)
            sp[j] = i;

    d.pb({}), v.pb(1);
    dfs(1, 2);
    int n = d.size();
    adj.resize(n);
    for (int j = 0; j < n; j++) {
        r = d[j];
        for (int i = 0; i < r.size(); i++) {
            if (i != 0 && r[i] == r[i-1]) continue;
            if (r[i] == 2) {
                r.erase(r.begin());
                adj[j].pb(m[r]);
                adj[m[r]].pb(j);
                r.insert(r.begin(), 2);
            } else {
                r[i]--;
                adj[j].pb(m[r]);
                adj[m[r]].pb(j);
                r[i]++;
            }
        }
    }

    vector<vector<int>> g(n, vector<int>(n, inf));
    vector<vector<int>> c(n, vector<int>(K, inf));
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
        queue<int> q({i});
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int j : adj[x])
                if (g[i][j] == inf)
                    g[i][j] = g[i][x]+1, q.push(j);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cmin(c[i][v[j]], g[i][j]);

    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        map<int, int> f1, f2;
        while (a > 1) f1[sp[a]]++, a /= sp[a];
        while (b > 1) f2[sp[b]]++, b /= sp[b];
        vector<int> p1, p2;
        for (auto& [_, x] : f1) p1.pb(x+1);
        for (auto& [_, x] : f2) p2.pb(x+1);
        sort(all(p1)), sort(all(p2));
        int i = m[p1], j = m[p2];
        int ans = inf;
        for (int k = 0; k < K; k++)
            cmin(ans, c[i][k]+c[j][k]);
        cout << ans << "\n";
    }
}