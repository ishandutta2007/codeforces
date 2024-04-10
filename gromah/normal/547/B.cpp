#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000 + 5

int n, Max, A[N], Ord[N], Ans[N], Fa[N], Size[N];

inline bool cmp(int u, int v)
{
    return A[u] < A[v];
}

inline int Find(int x)
{
    return (x == Fa[x]) ? x : (Fa[x] = Find(Fa[x]));
}

inline void Add(int pos)
{
    Size[pos] = 1;
    if (pos > 1 && Fa[pos - 1])
    {
        Size[pos] += Size[Find(pos - 1)];
        Size[Find(pos - 1)] = 0;
        Fa[Find(pos - 1)] = pos;
    }
    if (pos < n && Fa[pos + 1])
    {
        Size[pos] += Size[Find(pos + 1)];
        Size[Find(pos + 1)] = 0;
        Fa[Find(pos + 1)] = pos;
    }
    Fa[pos] = pos;
    Max = max(Max, Size[pos]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; Ord[i] = i, i ++)
        scanf("%d", A + i);
    sort(Ord + 1, Ord + n + 1, cmp);
    for (int i = n; i; i --)
    {
        int t = Max;
        Add(Ord[i]);
        for (t ++; t <= Max; t ++)
            Ans[t] = A[Ord[i]];
    }
    for (int i = 1; i <= n; i ++)
        printf("%d%c", Ans[i], (i == n ? '\n' : ' '));
//    while (1) ;
    return 0;
}