#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, m, k, ans, A[N];

inline bool Judge(int u, int v)
{
    int dif = 0;
    for (; u || v; u >>= 1, v >>= 1)
        if ((u & 1) ^ (v & 1))
            dif ++;
    return dif <= k;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    m ++;
    for (int i = 1; i <= m; i ++)
        scanf("%d", A + i);
    for (int i = 1; i < m; i ++)
        if (Judge(A[i], A[m])) ans ++;
    printf("%d\n", ans);
    return 0;
}