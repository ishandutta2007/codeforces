#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
vector<int>g[N];
int n,m;
int lst[N];
bool bz[N];
vector<pair<int, int> > ans;
vector<int> d;
bool dfs(int x) {
    bz[x] = 1;
    d.push_back(x);
    if (lst[d.size()]) {
        ans.push_back({x, lst[d.size()]});
        lst[d.size()] = 0;
    } else lst[d.size()] = x;
    if (d.size() == (n + 1) / 2) {
        puts("PATH");
        printf("%d\n", d.size());
        for (int i = 0; i < d.size() ;i ++)
            printf("%d%c", d[i], " \n"[i == (int)d.size() - 1]);
        return 1;
    }
    for (auto u:g[x])
        if (!bz[u]) {
            if (dfs(u)) return 1;
        }
    d.pop_back();
    return 0;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d", &n, &m);
        ans.clear();
        for (int i = 1; i <= m; i ++) {
            int x ,y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
            bz[i] = 0;
            lst[i] = 0;
        }
        d.clear();
        if (!dfs(1)) {
            puts("PAIRING");
            printf("%d\n", ans.size());
            for (auto u: ans)
                printf("%d %d\n", u.first, u.second);
        }

        for (int i =1; i <= n; i ++)
            g[i].clear();
    }
    return 0;
}