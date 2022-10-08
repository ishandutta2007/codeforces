#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long llong;

int t;
llong L, R;

llong solve(llong X)
{
    if (X < 1)
        return 0LL;

    llong sq = round(sqrt((long double)X));
    while(sq*sq <= X)
        sq++;
    while(sq*sq > X)
        sq--;

    llong ans = 3LL * (sq - 1LL);

    ans++;
    if (sq * sq + sq <= X)
        ans++;
    if (sq * sq + sq + sq <= X)
        ans++;

    return ans;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%lld %lld", &L, &R);

        printf("%lld\n", solve(R) - solve(L-1));
    }

    return 0;
}