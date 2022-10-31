#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 100020
using namespace std;

double a[N];
double f[N], g[N];

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%lf", &a[i]);

    for(i = 1; i <= n; i ++)
    {
        f[i] = f[i - 1] + (g[i - 1] * 2 + 1) * a[i];
        g[i] = (g[i - 1] + 1) * a[i];
    }
    printf("%.10f\n", f[n]);

    return 0;
}