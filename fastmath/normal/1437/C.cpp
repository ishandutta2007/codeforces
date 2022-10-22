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

const int N = 407, INF = 1e18;
int dp[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(all(a));

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dp[i][j] = INF;
        
        dp[0][1] = 0;
        for (int i = 0; i < n; ++i) {
            for (int t = 0; t + 1 < N; ++t) {
                dp[i][t + 1] = min(dp[i][t + 1], dp[i][t]);
                dp[i + 1][t + 1] = min(dp[i + 1][t + 1], dp[i][t] + abs(t - a[i]));
            }   
        }   

        int ans = INF;
        for (int i = 1; i < N; ++i)
            ans = min(ans, dp[n][i]);
        cout << ans << endl;
    }   
}