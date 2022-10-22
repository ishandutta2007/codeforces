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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
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
        vector <vector <int> > g(n + 1);
        int loop = 0;
        int cyc = 0;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            if (u != v) {
                g[u].app(v);
                g[v].app(u);
            }
            else {
                loop++;
            }   
        }   
        vector <bool> used(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (!used[i] && g[i].size() == 1) {
                int u = i;
                while (!used[u]) {
                    used[u] = 1;
                    int v = -1;
                    for (int k : g[u])
                        if (!used[k])
                            v = k;
                     if (v == -1)
                        break;
                     u = v;
                }   
            }
        }   

        for (int i = 1; i <= n; ++i) {
            if (!used[i] && g[i].size() == 2) {
                cyc++;
                int u = i;
                while (!used[u]) {
                    used[u] = 1;
                    int v = -1;
                    for (int k : g[u])
                        if (!used[k])
                            v = k;
                     if (v == -1)
                        break;
                     u = v;
                }   
            }
        }   

        cout << m - loop + cyc << endl;
    }   
    
}