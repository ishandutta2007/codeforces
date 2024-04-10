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

const int N = 1001;
bool dp[N][2];

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
        int n, k;
        cin >> n >> k;
        
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int t = 0; t < n; ++t) {
            int x;
            cin >> x;
            x &= 1;
            for (int i = t; i >= 0; --i) {
                for (int j = 0; j < 2; ++j) {
                    dp[i + 1][j ^ x] |= dp[i][j];
                }
            }   
        }   

        if (dp[k][1]) {
            cout << "Yes" << endl;
        }   
        else {
            cout << "No" << endl;
        }   
    }   
}