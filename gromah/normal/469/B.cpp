#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int p, q, l, r, cnt, A[N][2];
bool F[N];

int main()
{
    scanf("%d%d%d%d", &p, &q, &l, &r);
    for (int i = 1; i <= p; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int j = a; j <= b; j ++)
            F[j] = 1;
    }
    for (int i = 1; i <= q; i ++)
        scanf("%d%d", A[i], A[i] + 1);
    for (int i = l; i <= r; i ++)
    {
        bool ok = 0;
        for (int j = 1; ((j <= q) && !ok); j ++)
            for (int k = A[j][0] + i; ((k <= A[j][1] + i) && !ok); k ++)
                if (F[k]) ok = 1;
        cnt += ok;
    }
    printf("%d\n", cnt);
    return 0;
}