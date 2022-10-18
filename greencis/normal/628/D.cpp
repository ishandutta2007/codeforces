#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const ll MOD = 1000000007ll;

int m,d;
ll dp[2][2005][2005];

ll solve(string s) {
    if (s[0] == '0') return 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2005; ++j)
            for (int k = 0; k < 2005; ++k)
                dp[i][j][k] = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (!i) {
            for (int j = 1; j < s[i] - 48; ++j)
                if (j != d)
                    dp[0][i][j % m] += 1;
            if (s[i] - 48 != d)
                dp[1][i][(s[i] - 48) % m] += 1;
        } else {
            if (i % 2 == 1) {
                for (int j = 0; j < m; ++j) {
                    if (d == s[i] - 48)
                        (dp[1][i][(j*10+d)%m] += dp[1][i-1][j]) %= MOD;
                    (dp[0][i][(j*10+d)%m] += dp[0][i-1][j] + (d < s[i] - 48 ? dp[1][i-1][j] : 0)) %= MOD;
                }
            } else {
                for (int z = 0; z < 10; ++z) {
                    if (z == d) continue;
                    for (int j = 0; j < m; ++j) {
                        if (z == s[i] - 48)
                            (dp[1][i][(j*10+z)%m] += dp[1][i-1][j]) %= MOD;
                        (dp[0][i][(j*10+z)%m] += dp[0][i-1][j] + (z < s[i] - 48 ? dp[1][i-1][j] : 0)) %= MOD;
                    }
                }
            }
        }
    }
    return (dp[0][s.size() - 1][0] + dp[1][s.size() - 1][0]) % MOD;
}

int main()
{
    string a,b;
    cin >> m >> d >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] == '0') a[i] = '9';
        else {
            --a[i];
            break;
        }
    }
    cout << ((solve(b) - solve(a)) % MOD + MOD) % MOD;

    return 0;
}