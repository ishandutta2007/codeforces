#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int N = 101;
const int mod = 1e9 + 7;
int n, m, sum_0, right_sum_0;
int x[N];
long long a[N], b[N][N], c[N][N];
long long calc(long long x,long long y)
{
    long long z = 1;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y /= 2;
    }
    return z;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n  ; i ++)
    {
        scanf("%d", &x[i]);
        sum_0 += (x[i] == 0);
    }
    for (int i = 1; i <= sum_0; i ++)
        right_sum_0 += (!x[i]);
    a[right_sum_0] = 1;
    for (int i = 0; i <= sum_0; i ++)
    {
        int sum_1 =  n - sum_0;
        int right_sum_0 = i;
        int n_right_sum_0 = sum_0 - right_sum_0;
        int n_right_sum_1  = sum_0 - right_sum_0;
        int right_sum_1 = n - sum_0 - n_right_sum_1;
        b[i][i + 1] += n_right_sum_0 * n_right_sum_1;
        b[i][i - 1] += right_sum_0 * right_sum_1;
        b[i][i] += sum_0 * max(sum_0 - 1, 0) / 2 + sum_1 * max(sum_1 - 1, 0) / 2 + right_sum_0 * n_right_sum_1 + right_sum_1 * n_right_sum_0;
    }
    int mm = m;
    while (m)
    {
        if (m & 1)
        {
            for (int i = 0; i <= n  ; i ++)
                for (int j = 0; j <= n ; j ++)
                    (c[0][j] += a[i] * b[i][j]) %= mod;
            for (int i = 0; i <= n ; i ++)
                a[i] = c[0][i], c[0][i] = 0;
        }
        for (int i = 0; i <= n ; i ++)
            for (int j = 0; j <= n ; j++)
                for (int k = 0;k  <= n ; k ++)
                    (c[i][k] += b[i][j] * b[j][k] ) %= mod;
        for (int i = 0; i <= n ; i ++)
            for (int j = 0; j <= n ; j ++)
                b[i][j] = c[i][j], c[i][j] = 0;
        m /= 2;
    }
    printf("%lld\n", a[sum_0] * calc(calc(n * (n - 1) / 2, mm), mod - 2) % mod);
    return 0;
}