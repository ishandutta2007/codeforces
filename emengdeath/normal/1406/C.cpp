#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int n;
int T;
vector<int>d;
int sz[N], mxsz[N];
pair<int, int> work(int x) {
    function<void(int, int)>dfs = [&](int x, int fa){
        sz[x] = 1;
        mxsz[x] = 0;
        d.push_back(x);
        for (auto u:g[x])
            if (u != fa)
                dfs(u, x), sz[x] += sz[u], mxsz[x] = max(mxsz[x], sz[u]);
    };
    d.clear();
    dfs(x, 0);
    for (auto u:d)
        if (max(mxsz[u], (int)d.size() - sz[u]) < max(mxsz[x], (int)d.size() - sz[x])) x = u;
    for (auto u:d)
        if (max(mxsz[u], (int)d.size() - sz[u]) == max(mxsz[x], (int)d.size() - sz[x]) && x != u) return {x, u};
    return {x, 0};
}
int main() {
    scanf("%d", &T);
    while (T -- ) {
        scanf("%d", &n);
        int xx, yy;
        for (int i = 1; i < n; i ++) {
            int x ,y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
            xx = x, yy = y;
        }
        auto u = work(1);
        if (!u.second)
            printf("%d %d\n%d %d\n", xx, yy, xx, yy);
        else {
            int fa = u.second;
            int x = u.first;
            while (g[x].size() != 1) {
                if (g[x][0] == fa) {
                    fa = x;
                    x = g[x][1];
                } else {
                    fa = x;
                    x = g[x][0];
                }
            }
            printf("%d %d\n", fa, x);
            printf("%d %d\n", x, u.second);
        }
        for (int i= 1; i <= n;i  ++)
            g[i].clear();
    }
    return 0;
}