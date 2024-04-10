#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 4020
using namespace std;

char a[N], b[N];
int f[N], g[N];

int main(void)
{
    int n;
    int i, j, p;
    long long o;

    cin >> a;
    n = strlen(a);

    for(i = 0; i < n; i ++)
    {
        b[i * 2 + 1] = a[i];
        b[i * 2] = '#';
    }
    b[n * 2] = '#';
    // cout<<b<<endl;

    f[0] = 1;
    for(i = 1, p = 0; i < n * 2 + 1; i ++)
    {
        f[i] = p + f[p] > i ? min(p + f[p] - i, f[p * 2 - i]) : 1;
        // if(p+f[p]>i)
            // printf("at %d(%d), fetch %d\n",i,p*2-i);
        for(; i - f[i] > -1 && i + f[i] < n * 2 + 1 && b[i - f[i]] == b[i + f[i]]; f[i] ++)
            ;
        if(i + f[i] > p + f[p])
            p = i;
    }

    // for(i=0;i<n*2+1;i++)cout<<b[i]<<' ';cout<<endl;
    // for(i=0;i<n*2+1;i++)cout<<f[i]<<' ';cout<<endl;

    for(i = 0; i < n * 2 + 1; i ++)
    {
        g[i >> 1] ++;
        g[(i >> 1) + (f[i] >> 1)] --;
    }
    for(i = 1; i < n; i ++)
        g[i] += g[i - 1];
    for(i = 1; i < n; i ++)
        g[i] += g[i - 1];
    // for(i=0;i<n;i++)cout<<g[i]<<' ';cout<<endl;

    for(i = o = 0; i < n * 2 + 1; i ++)
        if(i & 1)
        {
            // o=0;
            for(j = 1; j <= f[i]; j += 2)
                if((i >> 1) - ((j + 1) >> 1) > -1)
                    o += g[(i >> 1) - ((j + 1) >> 1)];
            // printf("at %d, ans %lld\n", i,o);
        }
        else
        {
            // o=0;
            for(j = 2; j <= f[i]; j += 2)
                if((i >> 1) - (j >> 1) - 1 > -1)
                    o += g[(i >> 1) - (j >> 1) - 1];
            // printf("at %d, ans %lld\n", i,o);
        }
    cout << o << endl;

    return 0;
}