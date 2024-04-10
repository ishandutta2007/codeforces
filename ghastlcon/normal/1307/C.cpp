#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 100020
#define S 26
using namespace std;

char a[N];
int f[S][N];

int main(void)
{
    int n;
    int i, j, k;
    long long o, c;

    scanf("%s", a + 1);
    n = strlen(a + 1);
    for(i = n; i >= 1; i --)
    {
        for(j = 0; j < S; j ++)
            f[j][i] = f[j][i + 1];
        f[a[i] - 97][i] ++;
    }

    for(i = o = 0; i < S; i ++)
    {
        for(j = 0; j < S; j ++)
        {
            for(k = 1, c = 0; k <= n; k ++)
                if(a[k] - 97 == i)
                    c += f[j][k + 1];
            o = max(o, c);
        }
        o = max(o, (long long)f[i][1]);
    }
    printf("%I64d\n", o);
    return 0;
}