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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n;
vector <int> g[N], tree[N], top;
void dfs(int u, int p) {
    for (int v : g[u])
        if (v != p) {
            tree[u].app(v);
            dfs(v, u);
        }    
    top.app(u);
}   
int dp[N];
int solve(int k) {
    int ans = 0;
    for (int u : top) {
        int mx1 = 0, mx2 = 0;
        for (int v : tree[u]) {
            if (dp[v] > mx2)
                mx2 = dp[v];
            if (mx2 > mx1)
                swap(mx1, mx2);
        }   
        if (mx1 + mx2 + 1 >= k) {
            dp[u] = 0;
            ++ans;
        }   
        else
            dp[u] = mx1 + 1;
    }   
    return ans;
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
    dfs(1, 1);
    int ptr = 1;
    while (ptr <= n) {
        int l = ptr, r = n + 1;
        int mem = solve(l);
        while (l < r - 1) {
            int m = (l + r) >> 1;
            if (solve(m) == mem)
                l = m;
            else
                r = m;
        }   
        for (int i = ptr; i <= l; ++i)
            cout << mem << endl;
        ptr = r;
    }   
}