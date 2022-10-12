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

const int maxn = 200005;
vector<int> adj[maxn], out;
int dp[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++)
            adj[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v; u--, v--;
            debug(u, v);
            adj[u].pb(v);
        }
        out.clear();
        fill(dp, dp+n, 0);
        for (int i = 0; i < n; i++) {
            if (dp[i] == 2)
                out.pb(i);
            else
                for (auto& j : adj[i])
                    dp[j] = max(dp[j], dp[i]+1);
        }
        cout << out.size() << "\n";
        for (auto& x : out)
            cout << x+1 << " ";
        cout << "\n";
    }
}