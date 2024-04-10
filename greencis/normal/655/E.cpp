#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int MOD = 1000000007;
int n, k, m, dp[2][2001005], extra[999], cnt[999], last[999];
char s[2001005];

int main()
{
    for (int i = 0; i < 26; ++i)
        last[i] = -1;

    cin >> n >> k >> s + 1;
    m = strlen(s + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= m + n; ++i) {
        if (i > m) {
            int mn = 2e9, mni = -1;
            for (int j = 0; j < k; ++j)
                if (last[j] < mn) mn = last[j], mni = j;
            s[i] = mni + 'a';
        }
        dp[0][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = ((dp[1][i] - extra[s[i] - 'a']) % MOD + MOD) % MOD;
        (extra[s[i] - 'a'] += dp[1][i]) %= MOD;
        ++cnt[s[i] - 'a'];
        last[s[i] - 'a'] = i;
    }
    cout << (dp[0][n+m] + dp[1][n+m]) % MOD;

    return 0;
}