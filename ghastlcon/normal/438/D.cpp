#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 100020
using namespace std;

int n, a[N];
long long f[N << 1];
int g[N << 1], p[N << 1];

void InitSegwin(void)
{
    int i;

    for(i = 0; i < n; i ++)
    {
        f[i + n] = g[i + n] = a[i];
        p[i + n] = i;
    }
    for(i = n - 1; i > 0; i --)
    {
        f[i] = f[i << 1] + f[i << 1 | 1];
        g[i] = max(g[i << 1], g[i << 1 | 1]);
        p[i] = g[i << 1] > g[i << 1 | 1] ? p[i << 1] : p[i << 1 | 1];
    }

    return;
}

void SetSegwin(int p, int v)
{
    p += n;
    for(f[p] = g[p] = v; p >>= 1; )
    {
        f[p] = f[p << 1] + f[p << 1 | 1];
        g[p] = max(g[p << 1], g[p << 1 | 1]);
        ::p[p] = g[p << 1] > g[p << 1 | 1] ? ::p[p << 1] : ::p[p << 1 | 1];
    }

    return;
}

long long SumSegwin(int l, int r)
{
    long long o;

    for(o = 0, l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            o += f[l ++];
        if(r & 1)
            o += f[-- r];
    }

    return o;
}

pair<int, int> MaxSegwin(int l, int r)
{
    pair<int, int> o;

    for(o = make_pair(-1, -1), l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
        {
            o = max(o, make_pair(g[l], p[l]));
            l ++;
        }
        if(r & 1)
        {
            r --;
            o = max(o, make_pair(g[r], p[r]));
        }
    }

    return o;
}

int main(void)
{
    int m, t, l, r, x;
    int i;
    pair<int, int> k;

    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    InitSegwin();
    // while(1){cin>>l>>r;cout<<SumSegwin(l-1,r-1)<<endl;}
    while(m --)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d %d", &l, &r);
            printf("%lld\n", SumSegwin(-- l, -- r));
        }
        else if(t == 2)
        {
            scanf("%d %d %d", &l, &r, &x);
            l --;
            r --;
            while(true)
            {
                k = MaxSegwin(l, r);
                // printf("getmax a[%d]=%d\n",k.second+1,k.first);
                if(k.first >= x)
                {
                    // printf("set a[%d]=%d\n",k.second+1,k.first%x);
                    SetSegwin(k.second, k.first % x);
                }
                else
                    break;
            }
        }
        else
        {
            scanf("%d %d", &l, &x);
            SetSegwin(-- l, x);
        }
    }

    return 0;
}