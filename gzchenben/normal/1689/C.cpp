#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, t;
int Dep[300005], Ans;
vector<int> vec[300005];
void dfs(int x, int pre)
{
    Dep[x] = Dep[pre] + 1;
    if (vec[x].size() < 3 && x != 1)
    {
        Ans = max(Ans, n - 2 * Dep[x] + (2 - (int)vec[x].size()));
    }
    for (auto &p : vec[x])
    {
        if (p != pre)
            dfs(p, x);
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            vec[i].clear();
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        Ans = 0;
        if (vec[1].size() < 2)
            Ans = n - 2;
        dfs(1, 0);
        printf("%d\n", Ans);
    }
}