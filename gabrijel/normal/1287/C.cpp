#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 110;
const int inf = 1e9 + 100;
const int mod = 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
    return a;
}

int mult(int a, int b)
{
    return (long long) a * b % mod;
}

int pot(int a, int b)
{
    int ret = 1;
    while(b)
    {
        if(b & 1) ret = mult(ret, a);
        b >>= 1;
        a = mult(a, a);
    }
    return ret;
}

int n;

int a[maxn];

int dp[maxn][maxn][2];

int br_nep, br_par;

int fali;

int main()
{
    REP(i, 0, maxn) REP(j, 0, maxn) REP(k, 0, 2) dp[i][j][k] = inf;
    cin >> n;
    REP(i, 0, n)
    {
        cin >> a[i];
        if(a[i] != 0)
        {
            if(a[i] % 2) br_nep++;
            else br_par++;
        }
        else fali++;
    }
    br_nep = n / 2 + n % 2 - br_nep;
    if(n <= 2)
    {
        cout << n - 1 << endl;
        return 0;
    }
    if(a[0])
    {
        if(a[0] % 2) dp[0][0][1] = 0;
        else dp[0][0][0] = 0;
    }
    else
    {
        dp[0][0][0] = 0;
        dp[0][1][1] = 0;
    }
    REP(i, 1, n)
    {
        if(a[i] != 0)
        {
            if(a[i] % 2)
            {
                REP(j, 0, br_nep + 1)
                {
                    dp[i][j][1] = min(dp[i - 1][j][0] + 1, dp[i - 1][j][1]);
                }
            }
            else
            {
                REP(j, 0, br_nep + 1)
                {
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
                }
            }
            continue;
        }
        REP(j, 0, br_nep + 1)
        {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
            if(j != 0)
            {
                dp[i][j][1] = min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][0] + 1);
            }
        }
    }
    cout << min(dp[n - 1][br_nep][0], dp[n - 1][br_nep][1]) << endl;
    /*REP(i, 0, n)
    {
        REP(j, 0, br_nep + 1)
        {
            cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }*/
    return 0;
}