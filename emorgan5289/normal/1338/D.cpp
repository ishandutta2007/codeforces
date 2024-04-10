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

const int N = 100005;
int dp[N][2], out;
vector<int> adj[N];

void dfs(int i, int p) {
    int c = adj[i].size()-(i == 0 ? 0 : 1);
    dp[i][0] = 0; dp[i][1] = 1;
    vector<int> b[2];
    for (auto& j : adj[i])
        if (j != p) {
            dfs(j, i);
            dp[i][0] = max(dp[i][0], dp[j][1]+c-1);
            dp[i][1] = max(dp[i][1], dp[j][0]+1);
            b[0].pb(dp[j][0]), b[1].pb(dp[j][1]);
        }
    dp[i][1] = max(dp[i][1], dp[i][0]);
    sort(all(b[0]), greater<>()), sort(all(b[1]), greater<>());
    out = max(out, dp[i][1]);
    if (c > 1) {
        out = max(out, b[0][0]+b[0][1]+1);
        out = max(out, b[1][0]+b[1][1]+(i == 0 ? 0 : 1)+c-2);
    }
    // debug(i, b[0], b[1]);
    // debug(i, dp[i][0], dp[i][1]);
    // debug(i, out);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(0, 0);
    cout << out << "\n";
}