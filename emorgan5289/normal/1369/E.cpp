#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 200005;
int w[N];
bool vis[N], chk[N];
vector<pair<int, int>> adj[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb({v, i}); adj[v].pb({u, i});
        w[u]--, w[v]--;
    }
    vector<int> stk, o;
    for (int i = 0; i < n; i++)
        if (w[i] >= 0) 
            stk.pb(i), chk[i] = 1;
    for (int t = 0; t < n; t++) {
        if (stk.empty())
            return cout << "DEAD\n", 0;
        int i = stk.back(); stk.pop_back();
        for (auto& [j, e] : adj[i])
            if (!vis[e]) {
                vis[e] = 1;
                o.pb(e);
                w[j]++;
                if (w[j] >= 0 && !chk[j])
                    stk.pb(j), chk[j] = 1;
            }
    }
    reverse(all(o));
    cout << "ALIVE\n";
    for (auto& x : o)
        cout << x+1 << " ";
}