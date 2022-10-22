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

const int N = 1e6+7, INF = 1e18;
int dp[N][2];
int f[N], ff[N], a[N], suff[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];    

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j)
            dp[i][j] = INF;
        f[i] = ff[i] = INF;
    }   

    auto rel = [&] (int &a, int b) {
        a = min(a, b);
    };  

    dp[1][0] = r1 * a[1] + r3;
    dp[1][1] = min(r1 * (a[1] + 2), r2 + r1) + 2 * d;
    f[1] = 0;
    for (int i = 1; i < n; ++i) {
        rel(dp[i + 1][0], (dp[i][0] + d) + r1 * a[i + 1] + r3);
        rel(dp[i + 1][1], (dp[i][0] + d) + min(r1 * (a[i + 1] + 2), r2 + r1) + 2 * d);
            
        rel(dp[i + 1][0], (dp[i][1] + d) + r1 * a[i + 1] + r3);
        rel(dp[i + 1][0], (dp[i][1] + d) + min(r1 * (a[i + 1] + 2), r2 + r1));        
        rel(dp[i + 1][1], (dp[i][1] + d) + min(r1 * (a[i + 1] + 2), r2 + r1) + 2 * d);        

        rel(f[i + 1], min(dp[i][0], dp[i][1]) + d);
        rel(ff[i + 1], dp[i][1] + d);
    }   

    suff[n] = min({r1 * (a[n] + 2) + 2 * d, r1 * a[n] + r3, r2 + r1 + 2 * d});
    for (int i = n - 1; i; --i) {
        suff[i] = suff[i + 1] + min({r1 * (a[i] + 2), r1 * a[i] + r3, r2 + r1});
    }

    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int r = n - i;
        rel(ans, f[i] + suff[i] + r * d * 2);
        rel(ans, ff[i] + suff[i + 1] + r * d * 2 + min({r1 * (a[i] + 2), r1 * a[i] + r3, r2 + r1}));
        //cout << i << ' ' << f[i] + suff[i] + r * d * 2 << endl;
    }   
    cout << ans << endl;
}