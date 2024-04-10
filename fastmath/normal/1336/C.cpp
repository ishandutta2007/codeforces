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
const int N = 3007, MOD = 998244353;
void add(int &a, int b) { a = (a + b) % MOD; }
int dp[N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < N; ++i)
        dp[i][i] = 2 * (i >= t.size() || t[i] == s[0]);
    for (int l = N - 1; l >= 0; --l) {
        for (int r = l; r < N; ++r) {
            if (r - l + 1 < s.size()) {
                if (r + 1 >= t.size() || s[r - l + 1] == t[r + 1])
                    add(dp[l][r + 1], dp[l][r]);
                if (l && (l - 1 >= t.size() || s[r - l + 1] == t[l - 1]))
                    add(dp[l - 1][r], dp[l][r]);
            }
        }   
    }   
    int ans = 0;
    for (int i = t.size() - 1; i < N; ++i)
        add(ans, dp[0][i]);
    cout << ans << endl;
}