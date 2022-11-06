#include <cstdio>
using namespace std;
typedef long long LL;
#define N 500000 + 1
#define M 10000000 + 5

int n, m, tot, A[N], q[N], Miu[N], Head[N], T[N];
LL ans;
bool Vis[N], Flag[N];

struct Edge
{
    int next, node;
}h[M];

inline void Addedge(int u, int v)
{
    h[++ tot].next = Head[u], Head[u] = tot;
    h[tot].node = v;
}

inline void Prepare()
{
    Miu[1] = 1;
    for (int i = 2; i < N; i ++)
    {
        if (!Vis[i])
        {
            q[++ q[0]] = i;
            Miu[i] = -1;
        }
        for (int j = 1; j <= q[0] && i * q[j] < N; j ++)
        {
            Vis[i * q[j]] = 1;
            if (i % q[j] == 0)
            {
                Miu[i * q[j]] = 0;
                break ;
            }
            Miu[i * q[j]] = -Miu[i];
        }
    }
    for (int i = 1; i < N; i ++)
    {
        if (Miu[i] == 0) continue ;
        for (int j = i; j < N; j += i)
            Addedge(j, i);
    }
}

inline void Modify(int x, int op)
{
    for (int i = Head[x]; i; i = h[i].next)
    {
        int u = h[i].node;
        ans -= ((LL) T[u] * (T[u] - 1) >> 1) * Miu[u];
        T[u] += op;
        ans += ((LL) T[u] * (T[u] - 1) >> 1) * Miu[u];
    }
}

int main()
{
    Prepare();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    while (m --)
    {
        int x;
        scanf("%d", &x);
        Modify(A[x], Flag[x] ? -1 : 1);
        Flag[x] ^= 1;
        printf("%I64d\n", ans);
    }
    
    return 0;
}