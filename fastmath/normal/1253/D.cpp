#include<bits/stdc++.h>
using namespace std;
#define int long long 
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
int c[N];
vector <int> g[N];
bool used[N];
vector <int> comp;
void dfs(int u, int cl) {
    comp.app(u);
    used[u] = 1;
    c[u] = cl;
    for (int v : g[u]) {
        if (!used[v]) {
            dfs(v, cl);
        }   
    }   
}   
int add[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    int ptr = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            comp.clear();
            dfs(i, ptr++);
            int r = -1;
            for (int e : comp) r = max(r, e);
            add[i]++;
            add[r]--;
        }   
    }   
    int ans = 0;
    set <int> colors;
    for (int i = 1; i <= n; ++i) {
        colors.insert(c[i]);
        add[i] += add[i - 1];
        if (add[i] == 0) {
            ans += (int)colors.size() - 1;
            colors.clear();
        }   
    }   
    cout << ans << '\n';
}