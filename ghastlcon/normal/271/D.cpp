#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 1520
#define M 26
using namespace std;

char a[N], b[M + 1];
int f[N], g[N], h[N];
int x[N], y[N], c[N];

void InitSA(char *s, int n, int m)
{
    int i, j, k, p;
    int *x, *y;

    x = ::x;
    y = ::y;
    for(i = 0; i < n; i ++)
    {
        x[i] = s[i];
        c[x[i]] ++;
    }
    for(i = 1; i <= m; i ++)
        c[i] += c[i - 1];
    for(i = n - 1; i > -1; i --)
        f[-- c[x[i]]] = i;

    for(k = 1; k <= n; k <<= 1)
    {
        for(i = n - k, p = 0; i < n; i ++)
            y[p ++] = i;
        for(i = 0; i < n; i ++)
            if(f[i] >= k)
                y[p ++] = f[i] - k;

        for(i = 0; i <= m; i ++)
            c[i] = 0;
        for(i = 0; i < n; i ++)
            c[x[i]] ++;
        for(i = 1; i <= m; i ++)
            c[i] += c[i - 1];
        for(i = n - 1; i > -1; i --)
            f[-- c[x[y[i]]]] = y[i];

        swap(x, y);
        for(i = x[f[0]] = m = 1; i < n; i ++)
            x[f[i]] = y[f[i]] == y[f[i - 1]] && y[f[i] + k] == y[f[i - 1] + k] ? m : ++ m;
        if(m >= n)
            break;
    }

    for(i = 0; i < n; i ++)
        g[f[i]] = i;

    for(i = k = 0; i < n; i ++)
    {
        k = max(k - 1, 0);
        if(g[i])
            for(j = f[g[i] - 1]; s[i + k] == s[j + k]; k ++)
                ;
        else
            k = 0;
        h[g[i]] = k;
    }

    // for(i=0;i<n;i++)cout<<f[i]<<' ';cout<<endl;
    // for(i=0;i<n;i++)cout<<h[i]<<' ';cout<<endl;

    return;
}

int BSFind(int n, int k, int x)
{
    int l, m, r;

    for(l = h[x], r = n - f[x] + 1; l + 1 < r; )
        if(c[f[x] + (m = (l + r) >> 1) - 1] - (f[x] ? c[f[x] - 1] : 0) <= k)
            l = m;
        else
            r = m;

    // printf("at %d, len %d\n", x, l);

    return l - h[x];
}

int main(void)
{
    int n, k;
    int i, o;

    scanf("%s %s %d", a, b, &k);
    InitSA(a, n = strlen(a), 'z');

    for(i = 0; i < n; i ++)
        c[i] = (i ? c[i - 1] : 0) + 49 - b[a[i] - 97];
    // for(i=0;i<n;i++)cout<<c[i]<<' ';cout<<endl;

    for(i = o = 0; i < n; i ++)
    {
        // printf("at %d : %d\n", i, BSFind(n,k,i));
        o += BSFind(n, k, i);
    }
    printf("%d\n", o);

    return 0;
}