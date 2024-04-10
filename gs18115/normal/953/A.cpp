#include <bits/stdc++.h>
using namespace std;

long long ii, jj, a, b, i, j, cnt;

int main()
{
    scanf ("%lld%lld", &a, &b);
    ii = jj = 1;
    for (i = 0; i < 32; i ++)
    {
        for (j = 0; j < 20; j ++)
        {
            if (ii * jj >= a && ii * jj <= b) cnt ++;
            jj = jj * 3;
        }
        ii = ii * 2;
        jj = 1;
    }
    printf ("%lld", cnt);
    return 0;
}