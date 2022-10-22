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
const int N = 1e5 + 7;
int n, m;
set <int> un, g[N];
void dfs(int u) {
    un.erase(u);
    int v = -1;
    while (1) {
        auto t = un.upper_bound(v);
        if (t == un.end()) break;
        v = *t;
        if (g[u].find(v) == g[u].end()) dfs(v);
    }       
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].insert(v); g[v].insert(u);
    }   
    for (int i = 1; i <= n; ++i) un.insert(i);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (un.find(i) != un.end()) {
            ++ans;
            dfs(i);
        }   
    }   
    cout << ans - 1 << '\n';
}