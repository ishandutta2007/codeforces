#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1000020
using namespace std;

int a[N];

int main(void)
{
    int n, m;
    int i, p, v;
    long long s;

    scanf("%d %d", &n, &m);
    for(i = s = 0; i < (1 << n); i ++)
    {
        scanf("%d", &a[i]);
        s += a[i];
    }
    printf("%.6f\n", s / (double)(1 << n));

    while(m --)
    {
        scanf("%d %d", &p, &v);
        s -= a[p];
        s += v;
        a[p] = v;
        printf("%.6f\n", s / (double)(1 << n));
    }

    return 0;
}