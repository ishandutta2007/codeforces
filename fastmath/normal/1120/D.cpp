#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int c[N];
bool can_get[N], del[N], one[N];
int val[N];
vector <int> g[N];
int ans[N], mx[N];
bool mem[N];
void dfs1(int u, int p) {
    bool lief = 1;
    one[u] = 1;
    val[u] = -1;
    for (int v : g[u]) {
        if (v != p) {
            dfs1(v, u);
            lief = 0;
            ans[u] += ans[v];
            if (val[u] < mx[v]) {
                val[u] = mx[v];
                one[u] = 1;
            }   
            else if (val[u] == mx[v]) {
                one[u] = 0;
            }   
        }   
    }   
    if (lief) {
        can_get[u] = 1;
        ans[u] = mx[u] = c[u];
    }   
    else {
        can_get[u] = c[u] <= val[u];
        if (c[u] < val[u]) {
            del[u] = 1;
            ans[u] += c[u] - val[u];
            mx[u] = c[u];
        }   
        else {
            mx[u] = val[u];
        }   
    }   
    mem[u] = !one[u];
}   
vector <int> vv;
void dfs2(int u, int p, int last, bool t) {
    if ((t || last == -1 || !one[last] || val[last] != c[u]) && can_get[u]) vv.push_back(u);
    if (del[u]) {
        last = u;
        t = 0;
    }
    t |= mem[u];
    for (int v : g[u]) {
        if (v != p) {
            dfs2(v, u, last, t);
        }   
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }   
    dfs1(1, 1);
    dfs2(1, 1, -1, 0);
    cout << ans[1] << ' ' << vv.size() << '\n';
    sort(vv.begin(), vv.end());
    for (int e : vv) cout << e << ' ';
    cout << '\n';
}