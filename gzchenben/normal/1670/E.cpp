#include <cstdio>
#include <vector>
using namespace std;
int t, p, n, ansP[300005], ansE[300005], Now;
vector<pair<int, int>> Edge[300005];
void dfs(int Pos, int In, bool flag) // flag = 1 : Max on Point, Min on Edge
{
    Now++;
    ansP[Pos] = (flag ? Now + n : Now);
    ansE[In] = (flag ? Now : Now + n);
    for (auto &p : Edge[Pos])
    {
        if (p.second == In)
            continue;
        dfs(p.first, p.second, !flag);
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &p);
        n = (1 << p);
        for (int i = 1; i <= n; i++)
        {
            Edge[i].clear();
        }
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            Edge[u].push_back(make_pair(v, i));
            Edge[v].push_back(make_pair(u, i));
        }
        printf("1\n");
        Now = -1;
        dfs(1, -1, true);
        for (int i = 1; i <= n; i++)
            printf("%d ", ansP[i]);
        printf("\n");
        for (int i = 1; i <= n - 1; i++)
            printf("%d ", ansE[i]);
        printf("\n");   
    }
}