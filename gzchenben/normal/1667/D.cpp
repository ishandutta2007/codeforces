#include <cstdio>
#include <vector>
using namespace std;
int n, t, f[200005];
vector<int> vec[200005];
bool flag;
void dfs1(int x, int fa)
{
    int cnt[2] = {0, 0};
    for (auto &p : vec[x])
    {
        if (p == fa)
            continue;
        dfs1(p, x);
        cnt[f[p]]++;
    }
    // printf("%d %d %d\n", x, cnt[0], cnt[1]);
    if (cnt[0] + 1 == cnt[1])
        f[x] = 0;
    else if (cnt[0] == cnt[1])
        f[x] = 1;
    else if (cnt[0] + 2 == cnt[1] && x != 1)
        f[x] = 0;
    else if (cnt[0] == cnt[1] + 1 && x != 1)
        f[x] = 1;
    else
        flag = true;
}
void dfs2(int x, int fa)
{
    vector<int> tmp[2];
    for (auto &p : vec[x])
    {
        if (p != fa)
            tmp[f[p]].push_back(p);
        else
            tmp[f[x]].push_back(p);
    }
    int cur = vec[x].size() % 2;
    for (int i = 1; i <= vec[x].size(); i++)
    {
        int nxt = tmp[cur].back();
        tmp[cur].pop_back();
        if (nxt == fa)
            printf("%d %d\n", x, fa);
        else
            dfs2(nxt, x);
        cur ^= 1;
    }
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            vec[i].clear();
            f[i] = 0;
        }
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        flag = false;
        dfs1(1, 0);
        if (flag)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        dfs2(1, 0);
    }
}