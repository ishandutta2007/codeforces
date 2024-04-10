#include <iostream>

using namespace std;

const int max_k = 2500;
const int max_t = 110;
const int max_val = max_k * max_t;
const int mod = (int)1e9 + 7;

int dp[max_t][max_val] = {};

inline int sub_mod(int a, int b)
{
    int res = a + mod - b;
    if (res >= mod) res -= mod;
    return res;
}

inline int add_mod(int a, int b)
{
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

inline int mul_mod(int a, int b)
{
    long long res = (long long)a * (long long)b;
    return res % mod;
}

int main()
{
    int a, b, k, t; cin >> a >> b >> k >> t;
    k = 2 * k + 1;
    dp[0][0] = 1; dp[0][1] = sub_mod(0, 1);
    for (int i = 0; i < t; i++)
        for (int j = i, q = 0; j <= i*k; j++)
        {
            q = add_mod(q, dp[i][j]);
            dp[i+1][j+1]   = add_mod(dp[i+1][j+1], q);
            dp[i+1][j+k+1] = sub_mod(dp[i+1][j+k+1], q);
        }
    for (int i = 0, q = 0; i <= t; i++)
        for (int j = i; j <= i*k + 1; j++)
        {
            q = add_mod(q, dp[i][j]);
            dp[i][j] = q;
        }
    int ans = 0;
    for (int i = k*t, lim_i = i-1+a-b, q = 0; lim_i >= t; i--, lim_i--)
    {
        if (i >= t) q = add_mod(q, dp[t][i]);
        ans = add_mod(ans, mul_mod(q, dp[t][lim_i]));
    }
    cout << ans << endl;
}