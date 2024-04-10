#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
const int N = 5;
const int phi_mod = 1e9 + 6;
long long a[N], b[N][N], c[N][N];
int f1, f2, f3, C;
long long n, ans;
void work(long long n, long long mod){
    while (n)
    {
        if (n & 1)
        {
            for (int i = 0; i < N; i ++)
                for (int j = 0; j < N; j ++)
                    (c[0][j] += b[i][j] * a[i]) %= mod;
            for (int i = 0; i < N;  i++)
                a[i] = c[0][i], c[0][i] = 0;
        }
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < N; j ++)
                for (int k = 0; k < N; k  ++)
                    (c[i][k] += b[i][j] * b[j][k] ) %= mod;
        for (int i = 0;i < N; i ++)
            for (int j = 0; j < N; j ++)
                b[i][j] = c[i][j], c[i][j] = 0;
         n /= 2;
    }
}
long long calc(long long x, long long y, long long mod)
{
    long long z = 1;
    x %= mod;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y /= 2;
    }
    return z;
}
int main()
{
    scanf("%lld %d %d %d %d", &n, &f1, &f2, &f3, &C);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    b[0][1] = 1;
    b[1][2] = 1;
    b[3][3] = 1;
    b[4][4] = 1;
    b[4][3] = 2;
    b[0][0] = 1;
    b[1][0] = 1;
    b[2][0] = 1;
    b[3][0] = 1;
    a[4] = 1;
    a[3] = 2;
    work(n - 3, phi_mod);
    ans = calc(C, a[0], mod);

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    b[0][1] = 1;
    b[1][2] = 1;
    b[0][0] = 1;
    b[1][0] = 1;
    b[2][0] = 1;
    a[2] = 1;
    work(n - 3, phi_mod);
    ans = ans * calc(f1, a[0], mod) % mod;


    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    b[0][1] = 1;
    b[1][2] = 1;
    b[0][0] = 1;
    b[1][0] = 1;
    b[2][0] = 1;
    a[1] = 1;
    work(n - 3, phi_mod);
    ans = ans * calc(f2, a[0], mod) % mod;

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    b[0][1] = 1;
    b[1][2] = 1;
    b[0][0] = 1;
    b[1][0] = 1;
    b[2][0] = 1;
    a[0] = 1;
    work(n - 3, phi_mod);
    ans = ans * calc(f3, a[0], mod) % mod;
    printf("%d\n", ans);

    return 0;
}