#include <cmath> 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 500 + 5
int n, m, sumv, sume, A[N];
double ans;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    for (int i = 1; i <= m; i ++)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        if (!sume || sume * (A[u] + A[v]) > sumv * c)
            sume = c, sumv = A[u] + A[v];
    }
    if (sume)
        ans = (double) sumv / (double) sume;
    else ans = 0;
    printf("%.12lf\n", ans);
    return 0;
}