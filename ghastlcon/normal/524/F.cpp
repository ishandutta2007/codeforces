#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#define N 2000020
using namespace std;
 
char a[N];
int f[N], g[N], h[N];
deque<int> q;
 
void InitSA(char *s, int n, int m)
{
    static int l[N], r[N], c[N];
    int i, p, k;
    int *x, *y;
 
    x = l;
    y = r;
    for(i = 0; i < n; i ++)
    {
        x[i] = s[i + 1];
        c[x[i]] ++;
    }
    for(i = 2; i <= m; i ++)
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
 
        for(i = 1; i <= m; i ++)
            c[i] = 0;
        for(i = 0; i < n; i ++)
            c[x[i]] ++;
        for(i = 2; i <= m; i ++)
            c[i] += c[i - 1];
        for(i = n - 1; i > -1; i --)
            f[-- c[x[y[i]]]] = y[i];
 
        swap(x, y);
        for(i = x[f[0]] = m = 1; i < n; i ++)
            x[f[i]] = y[f[i]] == y[f[i - 1]] && y[f[i] + k] == y[f[i - 1] + k] ? m : ++ m;
        if(m >= n)
            break;
    }
 
    return;
}
 
int main(void)
{
    int n;
    int i;
 
    scanf("%s", a + 1);
    n = strlen(a + 1);
    for(i = 1; i <= n; i ++)
        a[i + n] = a[i];
    InitSA(a, n * 2, ')');
    // cout<<a+1<<endl;for(i=0;i<n*2;i++)cout<<f[i]+1<<' ';
 
    for(i = 1; i <= n * 2; i ++)
    {
        g[i] = g[i - 1] + (a[i] == '(' ? 1 : -1);
        for(; !q.empty() && i - q.front() > n; q.pop_front())
            ;
        for(; !q.empty() && g[q.back()] > g[i]; q.pop_back())
            ;
        q.push_back(i);
 
        if(i >= n)
            h[i - n + 1] = g[q.front()];
    }
    // for(i=1;i<=n*2;i++)cout<<g[i]<<' ';cout<<endl;
    // for(i=1;i<=n*2;i++)cout<<h[i]<<' ';cout<<endl;
 
    if(g[n] < 0)
        for(i = 0; i < -g[n]; i ++)
            printf("(");
    for(i = 0; i < n * 2; i ++)
        if(f[i] < n && h[f[i] + 1] - g[f[i]] >= min(g[n], 0))
            break;
    a[f[i] + 1 + n] = 0;
    printf("%s", a + f[i] + 1);
    if(g[n] > 0)
        for(i = 0; i <  g[n]; i ++)
            printf(")");
 
    return 0;
}