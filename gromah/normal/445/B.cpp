#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000 + 5
int n, m, Fa[N];
bool Use[N];
LL ans = 1;

int find(int x)
{
    if (x != Fa[x])
        Fa[x] = find(Fa[x]);
    return Fa[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        Fa[i] = i;
    for (int i = 1, u, v; i <= m; i ++)
    {
        scanf("%d%d", &u, &v);
        if (find(u) != find(v))
            Fa[find(u)] = find(v);
    }
    for (int i = 1; i <= n; i ++)
        Fa[i] = find(i);
    for (int i = 1; i <= n; i ++)
        if (!Use[Fa[i]])
            Use[Fa[i]] = 1;
        else ans *= 2;
    
    cout << ans << endl;
    return 0;
}