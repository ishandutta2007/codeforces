#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 100020
using namespace std;

long long a[N];
char b[N];

int main(void)
{
    int n;
    long double l[3], t, o;
    int i;
    bool x;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%lld", &a[i]);
    scanf("%s", b);

    l[0] = l[1] = l[2] = o = 0;
    x = false;

    for(i = 0; i < n; i ++)
        if(b[i] == 'G')
        {
            t = a[i];
            if(l[1] >= t / 2)
            {
                l[1] -= t / 2;
                o += (3 - 1) * (t / 2);

                l[0] += t;
                o += t;
            }
            else
            {
                t -= l[1] * 2;
                o += (3 - 1) * l[1];

                l[0] += l[1] * 2;
                o += l[1] * 2;
                l[1] = 0;

                // if(x)
                // {
                //     o += 4 * t;
                //     l[0] += t;
                // }
                // else
                // {
                    o += (5 + 1) * (t / 2);
                    l[0] += t / 2;
                // }
            }
        }
        else if(b[i] == 'W')
        {
            x = true;
            t = a[i];
            o += (3 + 1) * (t / 2);
            l[1] += t / 2;
        }
        else
        {
            t = a[i];
            if(l[1] >= t / 2)
            {
                l[1] -= t / 2;
                o += (3 - 1) * (t / 2);

                l[2] += t;
                o += t;
            }
            else
            {
                t -= l[1] * 2;
                o += (3 - 1) * l[1];

                l[2] += l[1] * 2;
                o += l[1] * 2;
                l[1] = 0;

                if(l[0] >= t / 2)
                {
                    l[0] -= t / 2;
                    o += (5 - 1) * (t / 2);

                    l[2] += t;
                    o += t;
                }
                else
                {
                    t -= l[0] * 2;
                    o += (5 - 1) * l[0];

                    l[2] += l[0] * 2;
                    o += l[0] * 2;
                    l[0] = 0;

                    l[2] += t;
                    o += x ? 3 * t : 5 * t;
                    o += t;
                }
            }
        }
    printf("%lld\n", (long long)o);

    return 0;
}