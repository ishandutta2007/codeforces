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
#define Time (double)clock()/CLOCKS_PER_SEC

const int INF = 1e13 + 7, N = 207;
int dp[N][N];
int r[N];

void add(int &a, int b) {
    a = min(INF, a + b);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i < N; ++i)
        r[i] = -1;

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            add(dp[i + 1][j], dp[i][j]);
        int c = s[i] - 'a';
        for (int j = 0; j < n; ++j) {

            if (r[c] == -1) 
                add(dp[i + 1][j + 1], dp[i][j]);
            else 
                add(dp[i + 1][j + 1], dp[i][j] - dp[r[c]][j]);

        }   
        r[c] = i;
    }   
    /*
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << dp[i][j] << ' ';
        cout << endl;                                                
    }   
    */    

    int ans = 0, cnt = 0;
    for (int len = n; len >= 0; --len) {
        int cur = n - len;
        if (dp[n][len] >= k) {
            ans += k * cur;
            k = 0;
            break;
        }   
        ans += dp[n][len] * cur;
        k -= dp[n][len];
    }   
    if (k)
        cout << -1 << endl;
    else
        cout << ans << endl;
}