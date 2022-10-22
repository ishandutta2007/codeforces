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

void dfs(int u, int p, vector <vector <int> > &g, vector <int> &sum, vector <vector <int> > &tree, vector <int> &top) {
    for (int v : g[u]) {
        if (v != p) {
            tree[u].app(v);
            dfs(v, u, g, sum, tree, top);
            sum[u] += sum[v];
        }   
    }   
    top.app(u);
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
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector <int> p(n + 1);
        for (int i = 1; i <= n; ++i)    
            cin >> p[i];

        vector <int> h(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> h[i];
        }   

        vector <vector <int> > g(n + 1), tree(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].app(v);
            g[v].app(u);
        }   

        vector <int> sum(n + 1);
        vector <int> top;
        for (int i = 1; i <= n; ++i)
            sum[i] = p[i];
        dfs(1, 1, g, sum, tree, top);

        string ans = "YES";

        vector <int> bad(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (sum[i] % 2 != abs(h[i]) % 2) {
                ans = "NO";
            }   
            if (sum[i] < h[i]) {
                ans = "NO";
            }   
            bad[i] = (sum[i] - h[i]) / 2;
            if (bad[i] > sum[i]) {
                ans = "NO";
            }   
        }   
        for (int u : top) {
            int ch = 0;
            for (int v : tree[u]) {
                ch += bad[v];
            }   
            if (ch < bad[u] - p[u]) {
                ans = "NO";
            }   
        }   

        cout << ans << endl;
    }   

}