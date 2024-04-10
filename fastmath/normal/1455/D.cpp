#include<bits/stdc++.h>
using namespace std;
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

const int N = 503, INF = 1e9+7;
int dp[N][N][N];
int a[N];

// (i, x, last)

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }   

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 0; k < N; ++k)
                    dp[i][j][k] = INF;

        auto rel = [&] (int &a, int b) {
            a = min(a, b);
        };  

        dp[0][x][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int x = 0; x <= 500; ++x) {
                for (int last = 0; last <= 500; ++last) {
                    if (dp[i][x][last] == INF)
                        continue;
                    if (last <= a[i])
                        rel(dp[i + 1][x][a[i]], dp[i][x][last]);
                    if (last <= x && x < a[i]) 
                        rel(dp[i + 1][a[i]][x], dp[i][x][last]+1);
                }   
            }   
        }   
        int ans = INF;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                rel(ans, dp[n][i][j]);
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;                                
    }   

}