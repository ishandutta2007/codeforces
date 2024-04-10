#include <bits/stdc++.h>

const int M = 100000;
const int MOD = (int)1e9 + 7;
const int INV = (int)5e8 + 4;

int n, m[2], prev[2][2][M], sum[2][2][M + 1];
std::pair<int, int> itvs[2][M];

int add(int x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}

int pow(int a, int n)
{
    int result = 1;
    while (n) {
        if (n & 1) {
            result = 1LL * result * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return result;
}

int main()
{
    scanf("%d%d%d", &n, m, m + 1);
    for (int k = 0; k < 2; ++ k) {
        for (int i = 0, r; i < m[k]; ++ i) {
            scanf("%d%d", &itvs[k][i].first, &r);
            itvs[k][i].second = -r - 1;
        }
        std::sort(itvs[k], itvs[k] + m[k]);
        int sz = 0;
        for (int i = 0; i < m[k]; ++ i) {
            while (sz && -itvs[k][i].second <= itvs[k][sz - 1].second) {
                sz --;
            }
            itvs[k][sz] = itvs[k][i];
            itvs[k][sz ++].second *= -1;
        }
        m[k] = sz;
    }
    for (int k = 0; k < 2; ++ k) {
        for (int t = 0; t < 2; ++ t) {
            int j = -1;
            for (int i = 0; i < m[k]; ++ i) {
                while (j + 1 < m[t] && itvs[t][j + 1].second <= itvs[k][i].first) {
                    j ++;
                }
                prev[k][t][i] = j + 1;
            }
        }
    }
    sum[0][0][0] = 1;
    int ptr[] = {0, 0};
    while (ptr[0] < m[0] || ptr[1] < m[1]) {
        int k = ptr[0] == m[0] || (ptr[1] < m[1] && itvs[0][ptr[0]].second > itvs[1][ptr[1]].second);
        int& i = ptr[k];
        int dp = add(1LL * (MOD - pow(INV, itvs[k][i].second - itvs[k][i].first)) * (sum[0][k ^ 1][prev[k][k ^ 1][i]] + sum[0][k][prev[k][k][i]]) % MOD,
            1LL * (MOD - pow(INV, itvs[k][i].second)) * (sum[1][k][i] + MOD - sum[1][k][prev[k][k][i]]) % MOD);
        sum[0][k][i + 1] = add(sum[0][k][i], dp);
        sum[1][k][i + 1] = add(sum[1][k][i], 1LL * dp * pow(2, itvs[k][i].second) % MOD);
        i ++;
    }
    printf("%d\n", static_cast<int>(1LL * pow(2, n) * add(sum[0][0][m[0]], sum[0][1][m[1]]) % MOD));
}