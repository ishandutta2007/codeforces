#include <cstdio>
#include <map>
using namespace std;
int n, ans = 100;
unsigned long long x, N;
map<unsigned long long, int> mp;

int dfs(unsigned long long st)
{
    if (mp[st])
        return mp[st];
    if (st >= N)
        return 0;
    unsigned long long Now = st;
    bool vis[10];
    for (int i = 0; i <= 9; i++)
        vis[i] = false;
    while (Now)
    {
        vis[Now % 10] = true;
        Now /= 10;
    }
    // printf("%lld\n", st);
    int res = 100;
    for (int i = 2; i <= 9; i++)
    {
        if (vis[i])
            res = min(res, dfs(st * i) + 1);
    }
    return mp[st] = res;
}
int main()
{
    scanf("%d%llu", &n, &x);
    N = 1;
    for (int i = 1; i <= n-1; i++)
        N *= 10;
    int ans = dfs(x);
    printf("%d\n", ans == 100 ? -1 : ans);
}