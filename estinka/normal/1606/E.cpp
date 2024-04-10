#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

const int m = 505, mod = 998244353;
int dp[m][m], pw[m][m], p[m][m]; // pw[i][j] = i^j
void upd(int &a, int b) { a = (a + b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % ((ll)mod); }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    p[0][0] = 1;
    for (int i = 1; i < m; i++)
    {
        pw[i][0] = 1;
        for (int j = 1; j <= m; j++) pw[i][j] = mul(pw[i][j - 1], i);
        p[i][0] = p[i][i] = 1;
        for (int j = 1; j < i; j++) p[i][j] = add(p[i - 1][j - 1], p[i - 1][j]);
    }
    int n, x;
    cin >> n >> x;
    dp[n][x] = 1;
    int ans = 0;
    for (int i = n; i > 1; i--)
    {
        for (int j = x; j >= 1; j--) if (dp[i][j])
        {
            if ((i - 1) >= j)
            {
                upd(dp[0][0], mul(dp[i][j], pw[j][i]));
                continue;
            }
            for (int r = i; r >= 0; r--)
            {
                upd(dp[r][j - (i - 1)], mul(dp[i][j], mul(pw[i - 1][i - r], p[i][r])));
            }
        }
    }
    for (int j = 0; j <= x; j++) upd(ans, dp[0][j]);
    cout << ans << "\n";
    return 0;
}