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
const int N = 5e5 + 7;
int n;
int L, R;
vector <ii> g[N];
int cnt[N];
void dfs(int u, int p) {
    cnt[u] = 1;
    for (auto e : g[u]) {
        if (e.f != p) {
            dfs(e.f, u);
            cnt[u] += cnt[e.f];
            L += (cnt[e.f] & 1) * e.s;
            R += min(cnt[e.f], 2 * n - cnt[e.f]) * e.s;
        }   
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2 * n; ++i)
            g[i].clear();
        for (int i = 0; i < 2 * n - 1; ++i) {
            int u, v, c; 
            cin >> u >> v >> c;
            g[u].app(mp(v, c));
            g[v].app(mp(u, c));
        }   
        L = R = 0;
        dfs(1, 1);
        cout << L << ' ' << R << '\n';
    }   
}