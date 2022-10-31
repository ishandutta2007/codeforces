#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 100020
#pragma GCC optimize("O3")
using namespace std;

long long a[N];

int main(void)
{
    long long n, k;
    int m;
    int i, j, o, s;

    scanf("%I64d %d %I64d", &n, &m, &k);
    for(i = 0; i < m; i ++)
    {
        scanf("%I64d", &a[i]);
        a[i] --;
    }

    sort(a, a + m);
    for(o = s = i = 0; i < m; i = j)
    {
        for(j = i; j < m && (a[j] - s) / k == (a[i] - s) / k; j ++)
            ;
        // printf("at %d-%d\n",i,j);
        o ++;
        s += j - i;
    }
    printf("%d\n", o);

    return 0;
}