#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100000 + 5
int m, n, f[N], q[N];
int lob(int x)
{
    return (x & -x);
}
bool cmp(int u, int v)
{
    return lob(u) < lob(v);
}
void begin()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    sort(f + 1, f + n + 1, cmp);
}
void work()
{
    for (int i = n; i && m; i --)
        if (m >= lob(f[i]))
        {
            m -= lob(f[i]);
            q[++ q[0]] = f[i];
        }
}
void end()
{
    if (!m)
    {
        printf("%d\n", q[0]);
        for (int i = 1; i <= q[0]; i ++)
            printf("%d%c", q[i], i == q[0] ? '\n' : ' ');
    }
    else puts("-1\n");    
}
int main()
{
    begin();
    work();
    end();
    return 0;
}