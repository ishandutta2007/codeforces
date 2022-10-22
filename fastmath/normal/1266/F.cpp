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
const int N = 1e6 + 7;
int n, ans[N];
vector <int> g[N];
ii diam(int u, int p) {
    ii ans = mp(0, u);
    for (int v : g[u]) {
        if (v != p) {
            auto t = diam(v, u);
            ++t.f;
            ans = max(ans, t);
        }   
    }   
    return ans;
}   
int down[N], up[N];
void dfs1(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            dfs1(v, u);
            down[u] = max(down[u], down[v] + 1);
        }   
    }   
}   
int par[N];
void dfs2(int u, int p) {
    par[u] = p;

    vector <int> a;
    for (int v : g[u]) 
        if (v != p)
            a.app(down[v]);
    sort(all(a));
    reverse(all(a));
    for (int v : g[u]) {
        if (v != p) {
            if (a.size() == 1)
                up[v] = up[u] + 1;
            else
                up[v] = max(up[u] + 1, a[a[0] == down[v]] + 2);
            dfs2(v, u);
        }   
    }   
}   
void upd(int &a, int b) {
    a = max(a, b);
}   
vector <int> a[N];
int get(vector <int> &a, int x) {
    return a.size() - (lb(all(a), x) - a.begin());
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
        g[v].app(u);
    }   
    for (int i = 1; i <= n; ++i)
        ans[i] = 1;
    for (int i = 1; i <= n; ++i)
        ans[1] = max(ans[1], (int)g[i].size() + 1);
    auto t = diam(1, 1);
    int d = diam(t.s, t.s).f;
    for (int i = 1; i <= d; ++i)
        ans[i] = max(ans[i], 2);
    dfs1(1, 1);
    dfs2(1, 1);
    for (int u = 1; u <= n; ++u) {
        vector <int> a;
        a.app(up[u]);
        for (int v : g[u]) 
            if (v != par[u])
                a.app(down[v] + 1);
        sort(all(a));
        reverse(all(a));
        for (int i = 2; i < a.size(); ++i) {
            upd(ans[2 * a[i]], i + 1);
            upd(ans[2 * a[i] - 1], i + 1);
        }   
        for (int i = 2; i < a.size(); ++i) {
            if (a[i - 1] > a[i]) {
                upd(ans[2 * (a[i] + 1) - 1], i + 1);
            }   
        }   
    }   
    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) 
            if (v != par[u])
                a[u].app(down[v] + 1);
        sort(all(a[u]));
    }   
    for (int u = 2; u <= n; ++u) {
        int mx2 = 0;
        if (a[u].size() > 1)
            mx2 = a[u][(int)a[u].size() - 2];
        for (int len = 1; len <= mx2; ++len) {
            upd(ans[2 * len], get(a[u], len) + get(a[par[u]], len) - (down[u] + 1 >= len) + (up[par[u]] >= len));
        }   
    }
    for (int i = n; i; --i) 
        ans[i] = max(ans[i], ans[i + 2]);
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}