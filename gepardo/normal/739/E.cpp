#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int max_n = 2016;

const long double fixedpoint = 1000000;
long double dva[max_n], dvb[max_n], dvc[max_n];
int va[max_n], vb[max_n], vc[max_n];
int dp[max_n][max_n];

int main()
{
    int n, a, b; cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> dva[i];
    for (int i = 0; i < n; i++) cin >> dvb[i];
    for (int i = 0; i < n; i++) dvc[i] = 1 - (1 - dva[i]) * (1 - dvb[i]);
    for (int i = 0; i < n; i++)
    {
        va[i] = round(dva[i] * fixedpoint);
        vb[i] = round(dvb[i] * fixedpoint);
        vc[i] = round(dvc[i] * fixedpoint);
    }
    for (int k = 0; k < n; k++)
    {
        register int kva = va[k], kvb = vb[k], kvc = vc[k],
                     fi = min(k+1, a), fj = min(k+1, b),
                     li = max(0, a - n + k - 1), lj = max(0, b - n + k - 1);
        for (int i = fi; i > li; i--)
            for (int j = fj; j > lj; j--)
                dp[i][j] = max(max(dp[i][j], dp[i-1][j] + kva),
                               max(dp[i][j-1] + kvb, dp[i-1][j-1] + kvc));
        for (int i = fi, j = lj; i > li; i--)
            dp[i][j] = max(dp[i][j], dp[i-1][j] + kva);
        for (int i = li, j = fj; j > lj; j--)
            dp[i][j] = max(dp[i][j], dp[i][j-1] + kvb);
    }
    cout << setprecision(10) << dp[a][b] / fixedpoint << endl;
    return 0;
}