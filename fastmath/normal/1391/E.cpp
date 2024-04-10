#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
void dfs(int u, vector <vector <int> > &g, vector <bool> &used, vector <int> &par, vector <int> &h) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) {
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v, g, used, par, h);
        }   
    }   
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > g(n + 1);
    vector <bool> used(n + 1);
    vector <int> par(n + 1), h(n + 1), out(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    dfs(1, g, used, par, h);
    for (int i = 2; i <= n; ++i)
        out[par[i]]++;
    for (int i = 1; i <= n; ++i) {
        if (h[i] + 1 >= (n + 1) / 2) {
            cout << "PATH" << endl;
            cout << h[i] + 1 << endl;
            int u = i;
            while (u) {
                cout << u << ' ';
                u = par[u];
            }
            cout << endl;
            return;
        }   
    }   
    queue <int> q;
    for (int i = 1; i <= n; ++i) {
        if (!out[i])
            q.push(i);
    }   
    cout << "PAIRING" << endl;
    int ha = (n+1)/2;
    cout << (ha+1)/2 << endl;
    for (int i = 0; i < (ha+1)/2; ++i) {
        assert(q.size() > 1);
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        cout << a << ' ' << b << endl;
        for (int u : {a, b}) {
            out[par[u]]--;
            if (out[par[u]] == 0) 
                q.push(par[u]);
        }
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}