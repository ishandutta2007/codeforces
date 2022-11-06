#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000000 + 5
#define M 10000000 + 5
int n, maxn, f[N], g[M], q[N];
long long sum[M];
void begin()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", f + i);
        maxn = max(maxn, f[i]);
    }
}
void First_Deal()
{
    for (int i = 2; i <= maxn; i ++)
    {
        if (!g[i])
        {
            g[i] = i;
            q[++ q[0]] = i;
        }
        for (int j = 1; j <= q[0] && q[j] * i <= maxn; j ++)
        {
            g[q[j] * i] = q[j];
            if (i % q[j] == 0) break ;
        }   
    }
    for (int i = 1; i <= n; i ++)
    {
        int last = 0;
        for (int j = f[i]; j != 1; j /= g[j])
        {
            if (last != g[j])
                sum[g[j]] ++;
            last = g[j];
        }
    }
    sum[0] = 0;
    for (int i = 1; i <= maxn; i ++)
        sum[i] += sum[i - 1];
}
void Query_Answer()
{
    int q;
    scanf("%d", &q);
    while (q --)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x = min(maxn + 1, x);
        y = min(maxn, y);
        cout << sum[y] - sum[x - 1] << endl;
    }
}
void work()
{
    First_Deal();
    Query_Answer();
}
void end()
{
    
}
int main()
{
    begin();
    work();
    end();
    return 0;
}