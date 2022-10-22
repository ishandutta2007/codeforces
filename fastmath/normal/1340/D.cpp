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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7;
int n;
vector <int> g[N], tree[N];
void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            tree[u].app(v);
            dfs(v, u);
        }   
    }   
}   
int T = -1;
vector <ii> ans;
void solve(int u, int t) {
    int want = t - 1;
    int son = tree[u].size();
    ans.app(mp(u, t));
    for (int v : tree[u]) {
        if (t == T) {
            t = want - son;
            ans.app(mp(u, t));
        }                       
        solve(v, t + 1);
        ++t;
        ans.app(mp(u, t));
        --son;
    }   
    if (u != 1 && t > want) 
        ans.app(mp(u, want));
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    for (int i = 1; i <= n; ++i)
        T = max(T, (int)g[i].size());
    dfs(1, 1);
    solve(1, 0);
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.f << ' ' << e.s << endl;
}