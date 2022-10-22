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
const int N = 2e5 + 7;
vector <int> g[N];
int n;
int down[N], cnt[N], sum[N];
void dfs1(int u, int p) {
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v != p) {
            dfs1(v, u);
            cnt[u] += cnt[v];
            down[u] += down[v] + cnt[v];
        }   
    }   
}   
void dfs2(int u, int p, int up) {
    sum[u] = up + down[u];
    int add = 0;
    for (int v : g[u]) {
        if (v != p) {
            add += down[v] + cnt[v];
        }   
    }   
    for (int v : g[u]) {
        if (v != p) {
            dfs2(v, u, up + (add - down[v] - cnt[v]) + (n - cnt[v]));
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
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    dfs1(1, 1);
    dfs2(1, 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, sum[i]);
    cout << ans + n << endl;
}