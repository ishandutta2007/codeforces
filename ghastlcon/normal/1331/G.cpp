#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int a[11];

int main(void)
{
    int i;
    double o;

    for(i = 0; i <= 10; i ++)
        scanf("%d", &a[i]);
    for(i = 10; i > -1; i --)
    {
        o = sqrt(abs(a[i])) + a[i] * a[i] * a[i] * 5;
        if(600 < o)
            printf("f(%d) = MAGNA NIMIS!\n", a[i]);
        else
            printf("f(%d) = %.2f\n", a[i], o);
    }

    return 0;
}