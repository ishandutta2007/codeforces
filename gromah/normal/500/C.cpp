#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1500 + 5

int n, m, ans, A[N], B[N], Ord[N];
bool Flag[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    for (int i = 1; i <= m; i ++)
    {
        scanf("%d", B + i);
        if (!Flag[B[i]]) Ord[++ Ord[0]] = B[i];
        Flag[B[i]] = 1;
    }
    for (int i = 1; i <= m; i ++)
    {
        int j = 1;
        for (; Ord[j] != B[i]; j ++) ans += A[Ord[j]];
        for (; j > 1; j --) swap(Ord[j], Ord[j - 1]);
    }
    printf("%d\n", ans);
    
    return 0;
}