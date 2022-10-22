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
const int N = 1e6 + 7;
vector <pair <int, char> > g[N];
int cnt[N], dp[N];
bool in[N];
void dfs(int u, int cur) {
    if (in[u])
        dp[u] = min(dp[u], cur + 1);
    cnt[u] = in[u];    
    for (auto e : g[u]) {
        int v = e.f;
        dp[v] = dp[u] + 1;
        dfs(v, min(cur, dp[u]) + cnt[u]);
        cnt[u] += cnt[v];
    }   
}   
bool comp(pair <int, char> a, pair <int, char> b) { return a.s < b.s; }   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int p; char c;
        cin >> p >> c;
        g[p].app(mp(i, c));
    }   
    for (int i = 0; i <= n; ++i)
        sort(all(g[i]), comp);
    int k;
    cin >> k;
    vector <int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        in[a[i]] = 1;
    }   
    dfs(0, N);
    for (int i = 0; i < k; ++i)
        cout << dp[a[i]] << ' ';
    cout << endl;
}