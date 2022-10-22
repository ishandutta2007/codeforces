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

const int N = 2e5 + 7;
int dp[N][3][3];
ii pr[N][3][3];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {   
        string s; cin >> s;
        int n = s.size();
        for (int i = 0; i <= n; ++i) 
            for (int j = 0; j < 3; ++j) 
                for (int k = 0; k < 3; ++k)
                    dp[i][j][k] = N;
        dp[0][0][0] = 0;

        string sa = "one";
        string sb = "two";

        for (int i = 0; i < n; ++i) {
            for (int a = 0; a < 3; ++a) {
                for (int b = 0; b < 3; ++b) {
                    int a1;
                    if (s[i] == sa[a])
                        a1 = a + 1;
                    else
                        a1 = s[i] == sa[0];

                    int b1;
                    if (s[i] == sb[b]) 
                        b1 = b + 1;
                    else 
                        b1 = s[i] == sb[0];

                    if (a1 < 3 && b1 < 3 && dp[i][a][b] < dp[i + 1][a1][b1]) {
                         dp[i + 1][a1][b1] = dp[i][a][b];
                         pr[i + 1][a1][b1] = mp(a, b);
                    }   
                    if (dp[i][a][b] + 1 < dp[i + 1][a][b]) {
                        dp[i + 1][a][b] = dp[i][a][b] + 1;
                        pr[i + 1][a][b] = mp(a, b);
                    }   

                }   
            }   
        }   

        int ans = N;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                ans = min(ans, dp[n][i][j]);

        int a = 0, b = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (dp[n][i][j] == ans) {
                    a = i; b = j;
                }   

        vector <int> del;
        for (int i = n; i; --i) {
            int a1, b1;
            tie(a1, b1) = pr[i][a][b];
            if (dp[i - 1][a1][b1] < dp[i][a][b]) {
                del.app(i);
            }   
            a = a1;
            b = b1;
        }   

        cout << ans << '\n';
        for (int e : del)
            cout << e << ' ';
        cout << '\n';                
    }   
}