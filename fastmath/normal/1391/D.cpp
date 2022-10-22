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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;

    assert(n <= m);

    if (n >= 4) {
        cout << -1 << endl;
        exit(0);
    }   

    vector <string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const int INF = 1e18;
    vector <vector <int> > dp(m + 1, vector <int> (1 << n, INF) );
    dp[0][0] = 0;

    vector <vector <int> > can(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int add = 0; add < (1 << n); ++add) {
            bool good = 1;
            for (int s = 0; s < n - 1; ++s) {
                int sum = 0;
                for (int i = 0; i < 2; ++i) {
                    sum += (mask >> (s + i)) & 1;
                    sum += (add >> (s + i)) & 1;   
                }   
                good &= sum & 1;
            }   
            if (good)
                can[mask].app(add);
        }   
    }   

    for (int i = 0; i < m; ++i) {
        //calc cost
        vector <int> cost(1 << n);
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int r = 0; r < n; ++r) {
                if (((mask >> r) & 1) != (a[r][i]-'0')) {
                    cost[mask]++;
                }   
            }   
        }   

        for (int mask = 0; mask < (1 << n); ++mask) {
            if (i == 0) {
                for (int add = 0; add < (1 << n); ++add) {
                    dp[i + 1][add] = min(dp[i + 1][add], dp[i][mask] + cost[add]);
                }
            }
            else {
                for (int add : can[mask]) {
                    dp[i + 1][add] = min(dp[i + 1][add], dp[i][mask] + cost[add]);
                }   
            }
        }   
    }   
    int ans = INF;
    for (int mask = 0; mask < (1 << n); ++mask)
        ans = min(ans, dp[m][mask]);
    cout << ans << endl;
}