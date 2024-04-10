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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a;
        cin >> a;

        const int INF = 1e18;
        string t = "LR";
        int ans = INF;
        for (int f = 0; f < 2; ++f) {
            for (int s = 0; s < 2; ++s) {
                vector <vector <vector <int> > > dp(n);
                for (int i = 0; i < n; ++i) {
                    dp[i].assign(2, vector <int> (2, INF));
                }                                                  
                dp[1][f][s] = (a[0] != t[f]) + (a[1] != t[s]);
                auto rel = [&] (int &a, int b) { a = min(a, b); };
                for (int i = 1; i + 1 < n; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        for (int k = 0; k < 2; ++k) {
                            /* 
                            if (dp[i][j][k] != INF) {
                                cout << "LOL " << i << ' ' << j << ' ' << k << " : " << dp[i][j][k] << endl;
                            }   
                            */
                            for (int r = 0; r < 2; ++r) {
                                if (j == k && j == r)
                                    continue;
                                rel(dp[i + 1][k][r], dp[i][j][k]+(a[i + 1] != t[r]));
                            }   
                            
                        }   
                    }   
                }   
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        if (i == j && i == f) {
                            continue;
                        }   
                        if (j == f && j == s)
                            continue;
                        /*
                        if (dp[n - 1][i][j] != INF) {
                            cout << "L " << i << ' ' << j << " : " << dp[n - 1][i][j] << endl;
                        }   
                        */
                        rel(ans, dp[n - 1][i][j]);
                    }   
                }
            }   
        }
        cout << ans << endl;   

    }   
}