#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1000000 + 5;
int n, m, p[N], q[N], Next[N], Head[N];
LL ans;
void begin()
{
//    freopen("C.in", "r", stdin);
//    freopen("C.out", "w", stdout);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", p + i);
        if (i > 1) ans += abs(p[i] - p[i - 1]);
        Next[i] = Head[p[i]];
        Head[p[i]] = i;
    }
}
void work()
{
    LL tmax = 0;;
    for (int i = 1; i <= m; i ++)
    {
        q[0] = 0;
        LL tsum = 0, tchange = 0;
        for (int x = Head[i]; x; x = Next[x])
        {
            if (x != n && p[x + 1] != i) q[++ q[0]] = p[x + 1], tsum += abs(p[x + 1] - p[x]);
            if (x != 1 && p[x - 1] != i) q[++ q[0]] = p[x - 1], tsum += abs(p[x - 1] - p[x]);
        }
        sort(q + 1, q + q[0] + 1);
        for (int x = 1; x <= q[0]; x ++)
            tchange += abs(q[x] - q[q[0] + 1 >> 1]);
        tmax = max(tmax, tsum - tchange);
    }
    ans -= tmax;
}
void end()
{
    cout << ans << endl;
//    fclose(stdin);
//    fclose(stdout);
}
int main()
{
    begin();
    work();
    end();
    return 0;
}