#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 2000020
using namespace std;

long long a[N], b[N];
char o[N];

int main(void)
{
    int n;
    int i;
    bool r;
    long long c;

    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
        scanf("%I64d", &a[i]);
    for(i = 1; i <= n; i ++)
        scanf("%I64d", &b[i]);

    if(n == 1)
    {
        printf("%s\n", a[1] == b[1] ? "SMALL\n0" : "IMPOSSIBLE");

        return 0;
    }

    for(c = 0, r = false; true; )
    {
        for(i = 1; i <= n; i ++)
            if(a[i] != b[i])
                break;
        if(i > n)
            break;
        reverse(b + 1, b + n + 1);
        for(i = 1; i <= n; i ++)
            if(a[i] != b[i])
                break;
        if(i > n)
        {
            if(c <= 2000000)
                o[c ++] = 'R';
            break;
        }
        reverse(b + 1, b + n + 1);

        // if(c>2000000){
        // for(i=1;i<=n;i++)cout<<b[i]<<' ';cout<<endl;//}
        for(i = 2; i <= n; i ++)
            if(b[i] - b[i - 1] < 0)
                break;
        if(i <= n)
        {
            if(c <= 2000000)
                o[c ++] = 'R';
            r ^= 1;
            reverse(b + 1, b + n + 1);
        }

        for(i = 2; i <= n; i ++)
            if(b[i] - b[i - 1] < 0)
            {
                printf("IMPOSSIBLE\n");

                return 0;
            }

        if(c > 2000000)
        {
            // for(i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
            for(i = 1; i <= n; i ++)
                if(b[i])
                    break;
            if(i == n)
            {
                printf("IMPOSSIBLE\n");

                return 0;
            }
            else if(i == n - 1)
            {
                if(b[n - 1] == a[2] && !((b[n] - a[1]) % b[n - 1]))
                {
                    c += (b[n] - a[1]) / b[n - 1];
                    break;
                }
                else if(b[n - 1] == a[n - 1] && !((b[n] - a[n]) % b[n - 1]))
                {
                    c += (b[n] - a[n]) / b[n - 1];
                    break;
                }
                else
                {
                    c += b[n] / b[n - 1];
                    b[n] %= b[n - 1];
                }
            }
            else
                throw;
        }
        else
        {
            if(c <= 2000000)
                o[c ++] = 'P';
            else
                c ++;
            for(i = n; i >= 2; i --)
                b[i] -= b[i - 1];
        }
    }

    if(c > 200000)
    {
        for(i = 0; i < N; i ++)
            c -= o[i] == 'R';
        printf("BIG\n%I64d\n", c);
    }
    else
    {
        reverse(o, o + c);
        printf("SMALL\n%I64d\n%s\n", c, o);
    }

    return 0;
}