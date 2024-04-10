#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int mod = 1000000007;

ll binpow(ll x, ll deg) {
    ll ans = 1;
    while (deg > 0) {
        if (deg & 1LL)
            (ans *= x) %= mod;
        deg >>= 1;
        (x *= x) %= mod;
    }
    return ans;
}

ll fibonacci[105];
ll deg2[105];
int dp[105][105][105];
int n, k;
string s;

int main() {
    fibonacci[0] = fibonacci[1] = 1;
    for (int i = 2; i < 105; ++i)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % (mod - 1);
    for (int i = 0; i < 105; ++i)
        deg2[i] = binpow(2, fibonacci[i]);

    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    for (int L = 0; L < n; ++L)
        dp[0][L][L] = (s[L] == '0'), dp[1][L][L] = (s[L] == '1');
    for (int fib = 2; fib <= k; ++fib) {
        for (int L = 0; L < n; ++L) {
            for (int R = L; R < n; ++R) {
                ll cur = (dp[fib - 1][L][R] * (R == n - 1 ? deg2[fib - 2] : 1) + dp[fib - 2][L][R] * (L == 0 ? deg2[fib - 1] : 1)) % mod;
                int cntr = 0;
                for (int j = L; j < R; ++j) {
                    cur += dp[fib - 1][L][j] * (ll)dp[fib - 2][j + 1][R];
                    ++cntr;
                    if (cntr >= 9) {
                        cntr = 0;
                        cur %= mod;
                    }
                }
                dp[fib][L][R] = cur % mod;
            }
        }
    }
    cout << dp[k][0][n - 1] << endl;
}