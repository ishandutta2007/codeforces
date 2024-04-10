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
const int N = 2e5+7, INF = 1e12;
vector <int> g[N];
int cost[N], h[N], dp[N][2];
//0 - in, 1 - out
void rel(int &a, int b) { a = min(a, b); }
void dfs(int u, int p) {
    vector <int> a;
    int sum = 0, shin = 0, shout = 0;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            if (h[u] < h[v]) {
                sum += dp[v][0];
                shout++;
            }   
            else if (h[u] > h[v]) {
                sum += dp[v][1];
                shin++;
            }   
            else {
                sum += dp[v][1];
                a.app(dp[v][0] - dp[v][1]);
            }   
        }   
    }   
    int sz = a.size();
    sort(all(a));
    vector <int> pref(sz+1);
    for (int i = 0; i < sz; ++i)
        pref[i + 1] = pref[i] + a[i];
    if (u > 1) {
        vector <int> can(2);
        can[0] = h[u] >= h[p];
        can[1] = h[u] <= h[p];
        for (int t = 0; t < 2; ++t) {
            if (can[t]) {
                for (int c1 = 0; c1 <= sz; ++c1) {
                    int in = sz - c1 + (t == 0) + shin;
                    int out = c1 + (t == 1) + shout;
                    rel(dp[u][t], sum + pref[c1] + max(in, out) * cost[u]);
                }   
            }
        }   
    }
    else {
        int ans = INF;
        for (int c1 = 0; c1 <= sz; ++c1) {
            int in = sz - c1 + shin;
            int out = c1 + shout;
            rel(ans, sum + pref[c1] + max(in, out) * cost[u]);            
        }   
        cout << ans << endl;
        exit(0);
    }   
    #ifdef HOME
    cout << u << " : " << dp[u][0] << ' ' << dp[u][1] << endl;
    #endif
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 2; ++j)
            dp[i][j] = INF;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> cost[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }
    dfs(1, 1);        
}