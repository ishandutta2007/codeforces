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
        const int INF = 1e9;
            
        int n;
        cin >> n;

        vector <int> p(2 * n);
        for (int i = 0; i < 2 * n; ++i)
            cin >> p[i];

        vector <vector <int> > dp (n + 1, vector <int> (n + 1, INF));

        auto relax = [] (int &a, int b) {
            a = min(a, b);
        };  

        dp[0][0] = 1;
        for (int sum = 0; sum < 2 * n; ++sum) {
            for (int i = 0; i <= n && i <= sum; ++i) {
                
                int j = sum - i;

                if (j <= n && dp[i][j] != INF) {

                    //cout << i << ' ' << j << " : " << dp[i][j] << endl;

                    int add = p[i + j];
                    if (i < n) {
                        relax(dp[i + 1][j], max(add + 1, dp[i][j]));
                    }   
                    if (j < n && add >= dp[i][j]) {
                        relax(dp[j + 1][i], add + 1);
                    }   
                    
                }   
                
            }   
        }   

        if (dp[n][n] != INF)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;                
    }   

}