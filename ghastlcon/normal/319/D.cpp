#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 50020
using namespace std;

char a[N];

bool Same(int l, int r, int p, int q)
{
    int i;

    for(i = l; i <= r; i ++)
        if(a[i] != a[p + i - l])
            return false;

    return true;
}

void Erase(int l, int r, int &n)
{
    int i, j;

    for(i = l, j = r + 1; j < n; i ++, j ++)
        a[i] = a[j];
    a[n - (r - l + 1)] = 0;
    n -= r - l + 1;

    return;
}

int main(void)
{
    int n, c;
    int i, j;

    for(n = 0; (c = getchar()) >= 'a' && c <= 'z'; )
        if(!n || c != a[n - 1])
            a[n ++] = c;

    for(i = 2; i <= (n >> 1); i ++)
        for(j = 0; j < n - (i << 1) + 1; j ++)
            if(Same(j, j + i - 1, j + i, j + (i << 1) - 1))
            {
                // printf("found %d %d\n",j,i);
                Erase(j, j + i - 1, n);
                j --;
            }
    printf("%s\n", a);

    return 0;
}