#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 1e5+5;
const int inf = 0x3f3f3f3f;

int dp[ms][2];
vector<int> g[ms];
int lo[ms][2];

int solve(int u, int last, int par) {
    int &ans = dp[u][last];
    if(dp[u][last] != -1) return ans;
    ans = 0;
    for(int go = 0; go < 2; go++) {
        int temp = 0;
        if(par != -1) temp = abs(lo[u][go] - lo[par][last]);
        for(int v : g[u]) {
            if(v == par) continue;
            temp += solve(v, go, u);
        }
        ans = max(ans, temp);
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> lo[i][0] >> lo[i][1];
            g[i].clear();
            dp[i][0] = dp[i][1] = -1;
        }
        for(int i = 1; i< n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v); g[v].emplace_back(u);
        }
        cout << solve(1, 0, -1) << '\n';
    }
    return 0;
}