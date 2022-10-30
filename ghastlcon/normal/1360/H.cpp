#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 120
using namespace std;

long long a[N];
char s[N];

int Compare(long long a, long long b, int k)
{
    int i;

    for(i = 0; i <= k; i ++)
        if((a >> i) & 1 && !((b >> i) & 1))
            return 1;
        else if((b >> i) & 1 && !((a >> i) & 1))
            return -1;

    return 0;
}

int main()
{
    int t, n, m;
    int i, j;
    long long o, s, c, k;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i ++)
        {
            scanf("%s", ::s);
            for(j = a[i] = 0; j < m; j ++)
                if(::s[j] == '1')
                    a[i] |= 1LL << j;
        }

        k = ((1LL << m) - n - 1) / 2;
        o = s = 0;
        for(i = 0; i < m; i ++)
        {
            o |= 1LL << i;
            s ++;
            c = s * (1LL << (m - i - 1));

            for(j = 0; j < n; j ++)
                if(Compare(o, a[j], i) == 1)
                    c --;

            if(c > k)
            {
                s --;
                o ^= 1LL << i;
            }
            s *= 2;
        }

        for(i = 0; i < m; i ++)
            printf("%d", (int)((o >> i) & 1));
        printf("\n");
    }

    return 0;
}