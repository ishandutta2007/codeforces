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
const int N = 107;
int a[N];
int dp[N][N][2];

void upd(int &a, int b) {
    a = min(a, b);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < 2; ++k)
                dp[i][j][k] = N;

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }   

    if (a[1]) {
        dp[1][a[1] & 1][a[1] & 1] = 0;
    }           
    else {
        dp[1][0][0] = dp[1][1][1] = 0;
    }   
    
    for (int i = 2; i <= n; ++i) {
        if (a[i]) {
            for (int pw = 0; pw <= n; ++pw) {
                for (int p = 0; p < 2; ++p) {
                    upd(dp[i][pw + (a[i] & 1)][a[i] & 1], dp[i - 1][pw][p] + ((p ^ a[i]) & 1));
                }   
            }
        }   
        else {
            for (int add = 0; add < 2; ++add) {
                for (int pw = 0; pw <= n; ++pw) {
                    for (int p = 0; p < 2; ++p) {
                        upd(dp[i][pw + add][add], dp[i - 1][pw][p] + (p ^ add));
                    }   
                }
            }   
        }   
    }

    int w = (n + 1) / 2;
    cout << min(dp[n][w][0], dp[n][w][1]) << '\n';
}