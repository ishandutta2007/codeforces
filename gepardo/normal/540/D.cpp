#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

long double dp[130][130][130][3];

int main()
{
    int a, b, c; cin >> a >> b >> c;

    for (int i = 1; i < 130; i++)
        dp[i][0][0][0] = 1,
        dp[0][i][0][1] = 1,
        dp[0][0][i][2] = 1;

    for (int sum = 2; sum < 400; sum++)
        for (int i = 0; i <= min(sum, 128); i++)
            for (int j = 0; i + j <= min(sum, i + 128); j++)
            {
                int k = sum - i - j;
                if (k > 128) continue;
                if ((i == 0 && j == 0) || (i == 0 && k == 0) ||
                    (j == 0 && k == 0)) continue;
                for (int l = 0; l < 3; l++)
                {
                    int cur = 0;
                    long double sum = 0;

                    if (i != 0 && j != 0) cur += i * j, sum += i * j * dp[i][j - 1][k][l];
                    if (j != 0 && k != 0) cur += j * k, sum += j * k * dp[i][j][k - 1][l];
                    if (k != 0 && i != 0) cur += k * i, sum += k * i * dp[i - 1][j][k][l];

                    dp[i][j][k][l] = sum / cur;
                }
            }
    for (int i = 0; i < 3; i++) cout << setprecision(12) << dp[a][b][c][i] << " ";
}