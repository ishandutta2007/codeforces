#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#define N 4020
using namespace std;

int a[N], b[N], c[N];
int f[N][N];

int main(void)
{
    int n, m;
    int i, j, k;

    cin >> n >> m;
    m += n;
    for(i = 1; i <= n; i ++)
        cin >> a[i];
    for(i = 1; i <= n; i ++)
        cin >> b[i];
    for(i = 1; i <= m; i ++)
        cin >> c[i];

    for(i = 0; i < N; i ++)
        fill(f[i] + 1, f[i] + N, INT_MIN >> 2);
    for(i = n; i >= 1; i --)
    {
        for(j = n; j >= 1; j --)
            f[a[i]][j] = max(f[a[i]][j], f[a[i]][j - 1] - b[i] + c[a[i]]);
        for(j = a[i]; j <= m; j ++)
            for(k = 0; k <= (n >> (j - a[i])); k ++)
                f[j + 1][k >> 1] = max(f[j + 1][k >> 1], f[j][k] + c[j + 1] * (k >> 1));
    }
    cout << f[m][0] << endl;

    return 0;
}