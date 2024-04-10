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

const int N = 1007;
int dp[N][3][3];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    vector <int> a = {0, 1, 0};
    vector <int> b = {1, 0, 1};

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)                
                    dp[i][j][k] = 1e9;

        dp[0][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            int have = s[i] - '0';
            for (int pa = 0; pa < 3; ++pa) {
                for (int pb = 0; pb < 3; ++pb) {
                    for (int add = 0; add < 2; ++add) {
                        if (pa == 2 && add == a[pa])
                            continue;
                        if (pb == 2 && add == b[pb])
                            continue;

                        int pa1 = pa + (add == a[pa]);
                        int pb1 = pb + (add == b[pb]);
                        dp[i + 1][pa1][pb1] = min(dp[i + 1][pa1][pb1], dp[i][pa][pb] + (add ^ have));
                    }   
                }   
            }   
        }   

        int ans = 1e9;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                ans = min(ans, dp[n][i][j]);
        cout << ans << endl;
    }   

}