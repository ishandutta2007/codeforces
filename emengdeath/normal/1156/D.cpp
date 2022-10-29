#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 1;
int n;
int f[N][2][2];
long long ans;
vector<pair<int, int> >g[N];
void dfs(int x, int fa)
{
    for (auto u:g[x])
        if (u.first != fa) {
            dfs(u.first, x);
            if (u.second) {
                f[x][1][1] += f[u.first][1][1] + 1;
                f[x][1][0] += f[u.first][1][0] + f[u.first][0][0];
            }else {
                f[x][0][0] += f[u.first][0][0] + 1;
                f[x][0][1] += f[u.first][1][1] + f[u.first][0][1];
            }
        }
    ans += f[x][0][0] * 2 + f[x][0][1] + f[x][1][0] + f[x][1][1] * 2;
}
void dfs(int x, int fa, int sum00, int sum01, int sum10, int sum11)
{
    ans += sum00 * 2 + sum01 + sum10 + sum11 * 2;
    for (auto u:g[x])
        if (u.first != fa) {
            if (u.second)
                dfs(u.first, x, 0, sum00 + sum01 + f[x][0][0] + f[x][1][0] - f[u.first][1][0] - f[u.first][0][0], 0, sum11 + f[x][1][1] - f[u.first][1][1]);
            else
                dfs(u.first, x, sum00 + f[x][0][0] - f[u.first][0][0], 0, sum10 + sum11 + f[x][0][1] + f[x][1][1] - f[u.first][1][1] - f[u.first][0][1], 0);
        }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n ; i ++)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        g[x].push_back(make_pair(y, c));
        g[y].push_back(make_pair(x, c));
    }
    dfs(1, 0);
    dfs(1, 0, 0, 0, 0, 0);
    printf("%lld\n", ans / 2);
    return 0;
}