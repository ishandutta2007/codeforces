#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007LL;

int n,m,sti;
char s[100105],st[100105];
ll ans,dp[2005][5005];

int main()
{
    cin >> n >> m >> s;
    int mn = 0, balance = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(') ++balance;
        else --balance;
        if (s[i] == ')' && sti > 0 && st[sti-1] == '(') --sti;
        else st[sti++] = s[i];
    }
    while (sti > 0 && st[sti-1] == '(') sti--;

    dp[0][0] = 1;
    for (int i = 1; i < 2005; ++i) {
        for (int j = 0; j < 2005; ++j) {
            if (j >= 1)
                (dp[i][j] += dp[i-1][j-1]) %= MOD;
            if (j < 2004)
                (dp[i][j] += dp[i-1][j+1]) %= MOD;
        }
    }

    for (int i = 0; i <= n - m; ++i) {
        for (int j = sti; j < 2005; ++j) {
            if (j + balance >= 0)
                (ans += (dp[i][j] * dp[n - m - i][min(2004, j + balance)]) % MOD) %= MOD;
        }
    }
    cout << (ans % MOD + MOD) % MOD;

    return 0;
}