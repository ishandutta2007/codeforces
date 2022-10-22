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
const int N = 507;
string a[N];
int dp[N][N];
int cost[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    const int INF = 1e9 + 7;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = INF;
    dp[0][0] = 0;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        vector <int> p;
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '1')
                p.app(j);

        cost[p.size()] = 0;                
        for (int t = 0; t < p.size(); ++t)
            cost[t] = INF;
        for (int l = 0; l < p.size(); ++l) {
            for (int r = l; r < p.size(); ++r) {
                int d = l + p.size() - r - 1;
                cost[d] = min(cost[d], p[r] - p[l] + 1);
            }   
        }

        for (int j = 0; j <= k; ++j)
            for (int add = 0; j + add <= k; ++add)
                dp[i + 1][j + add] = min(dp[i + 1][j + add], dp[i][j] + cost[add]);                
    }    
    int ans = INF;
    for (int i = 0; i <= k; ++i)
        ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}