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
const int N = 1e5 + 7;
int n, m, q;
vector <int> g[N];
int v[N], a[N];
int in[N], out[N];
vector <int> gout[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    cin >> q;
    for (int i = 0; i < q; ++i) cin >> v[i];
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int v : g[i]) {
            if (v < i) {
                in[i]++;
            }
            else {
                out[i]++;
                gout[i].app(v);
            }
        }   
        ans += (ll)in[i] * out[i];
        a[i] = i;
    }
    cout << ans << '\n';   
    for (int i = 0; i < q; ++i) {
        int u = v[i];
        ans -= (ll)in[u] * out[u];
        in[u] = g[u].size(); out[u] = 0;
        for (int v : gout[u]) {
            ans += (int)g[v].size() - 2 * out[v] - 1;
            gout[v].app(u);
            --in[v]; ++out[v];
        }   
        gout[u].clear();
        a[u] = n + i + 1;
        cout << ans << '\n';
    }
}