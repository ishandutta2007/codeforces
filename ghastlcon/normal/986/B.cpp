#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1000020
using namespace std;

int n, a[N];
int f[N];

int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p)
{
    for(;p <= n;p += Lowbit(p))
        f[p] ++;

    return;
}

int SumFenwick(int p)
{
    int o;

    for(o = 0;p;p -= Lowbit(p))
        o += f[p];

    return o;
}

int main(void)
{
    int i;
    long long o;

    scanf("%d", &n);
    for(i = o = 0;i < n;i ++)
    {
        scanf("%d", &a[i]);
        o += SumFenwick(n) - SumFenwick(a[i]);
        AddFenwick(a[i]);
    }
    puts((n % 2) == (o % 2) ? "Petr" : "Um_nik");

    return 0;
}