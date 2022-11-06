#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 300 + 5

int n, A[N], Fa[N], Ord[N];
bool Map[N][N], Flag[N];

inline int Find(int x)
{
    return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

inline bool cmp(int u, int v)
{
    return A[u] < A[v];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Ord[i] = Fa[i] = i;
    }
    sort(Ord + 1, Ord + n + 1, cmp);
    char ch = '\n';
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            while (ch != '0' && ch != '1')
                ch = getchar();
            if (ch == '1') Fa[Find(i)] = Find(j);
            ch = getchar();
        }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            Map[i][j] = Find(i) == Find(j);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (Map[i][Ord[j]] && !Flag[j])
            {
                printf("%d%c", j, i == n ? '\n' : ' ');
                Flag[j] = 1;
                break ;
            }
    
    return 0;
}