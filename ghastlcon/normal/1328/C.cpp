#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 50020
using namespace std;

char a[N], x[N], y[N];

int main(void)
{
    int t, n;
    int i;
    bool v;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %s", &n, a);
        if(a[0] == '0')
        {
            x[0] = '1';
            y[0] = '2';
            v = true;
        }
        else if(a[0] == '1')
        {
            x[0] = '2';
            y[0] = '2';
            v = false;
        }
        else
        {
            x[0] = '1';
            y[0] = '1';
            v = false;
        }

        for(i = 1; i < n; i ++)
            if(a[i] == '0')
                x[i] = y[i] = '0';
            else if(a[i] == '1')
            {
                if(v)
                {
                    x[i] = '1';
                    y[i] = '0';
                }
                else
                {
                    x[i] = '0';
                    y[i] = '1';
                    v = true;
                }
            }
            else
            {
                if(v)
                {
                    x[i] = '2';
                    y[i] = '0';
                }
                else
                {
                    x[i] = '1';
                    y[i] = '1';
                }
            }

        // for(i=0;i<n;i++)putchar(x[i]);putchar('\n');
        x[n] = y[n] = 0;
        printf("%s\n%s\n", x, y);
    }

    return 0;
}