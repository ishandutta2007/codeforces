#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2e5 + 7;
unordered_set <int> d[N];
int n;
vector <int> g[N];
int c[N];
int ptr[N];
void dfs(int u, int p) {
    for (int i = ptr[p]; ; ++i) 
        if (d[p].find(i) == d[p].end()) {
            c[u] = i;
            break;
        }
    if (u != 1) {
        ptr[p] = c[u] + 1;
        d[p].insert(c[u]);
    }
    d[u].insert(c[u]);
    d[u].insert(c[p]);
    for (int v : g[u]) 
        if (v != p) 
            dfs(v, u);
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u , v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    int ans = 0;
    for (int i = 1; i <= n; ++i) 
        ans = max(ans, (int)g[i].size() + 1);
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) 
        ptr[i] = 1;
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) cout << c[i] << ' ';
    cout << '\n';
}