#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 500020
using namespace std;

int a[N];
double f[N], o;
int g[N];

void Insert(int x)
{
    static int c;

    a[c] = x;
    if(!c)
    {
        f[0] = 0;
        g[0] = 0;
    }
    else if(c == 1)
    {
        f[1] = (double)(a[0] + a[1]) / 2;
        g[1] = 0;
        o = a[1] - f[1];
    }
    else
    {
        f[c] = (f[c - 1] * (g[c - 1] + 2) - a[c - 1] + a[c]) / (g[c - 1] + 2);
        g[c] = g[c - 1];
        while(g[c] < c - 1 && (f[c] * (g[c] + 2) + a[g[c] + 1]) / (g[c] + 3) < f[c])
        {
            f[c] = (f[c] * (g[c] + 2) + a[g[c] + 1]) / (g[c] + 3);
            g[c] ++;
        }
        o = max(o, a[c] - f[c]);
    }
    c ++;

    return;
}

int main(void)
{
    int q, a, b;

    scanf("%d", &q);
    while(q --)
    {
        scanf("%d", &a);
        if(a == 1)
        {
            scanf("%d", &b);
            Insert(b);
        }
        else
            printf("%.10f\n", o);
    }

    return 0;
}