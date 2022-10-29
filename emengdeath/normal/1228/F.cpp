#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int N = (1 << 18);
vector<int> g[N];
int n, m;
set<int>ans;
bool bz[N];
int mxsz[N], sz[N];
int v;
void dfs(int x, int fa) {
    sz[x] = 1;
    mxsz[x] = 0;
    for (auto u:g[x])
        if (u != fa) {
            dfs(u, x);
            sz[x] += sz[u];
            mxsz[x] = max(mxsz[x], sz[u]);
        }
}
int calc(int x) {
    return max(mxsz[x], n - 1 - sz[x]);
}
int dfs1(int x, int fa) {
    vector<int>d;
    for (auto u:g[x])
        if (u != fa) {
            d.push_back(dfs1(u, x));
        }
    if (!d.size())  return 0;
    sort(d.begin(), d.end());
    if (d.size() > 2) {
        if (v) {
            v = -1;
            return 0;
        } else {
            if (d[1] == d[0] && d[2] == d[0] + 1) {
                v = x;
                return d[2] + 1;
            } else
                v = -1;
            return 0;
        }
    }
    if (d.size() == 1) {
        if (v) {
            v = -1;
            return 0;
        } else {
            v = x;
            return d[0] + 1;
        }
    }
    if (d[0] != d[1]) {
        v = -1;
        return 0;
    }
    return d[0] + 1;
}
int main() {
    scanf("%d", &m);
    n = (1 << m) - 1;
    for (int i = 1; i < n - 1; i ++) {
        int x ,y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        bz[x] = bz[y] = 1;
    }
    if (!bz[1])
        dfs(2, 0);
    else
        dfs(1, 0);
    vector<int> d;
    for (int i = 1; i <= n; i ++)
        if (bz[i]) {
            if (d.empty())
                d.push_back(i);
            else {
                if (calc(i) < calc(d[0]))
                    d.clear(), d.push_back(i);
                else
                    if (calc(i) == calc(d[0]))
                        d.push_back(i);
            }
        }
    for (auto u:d) {
        v = 0;
        dfs1(u, 0);
        if (v != -1)
            ans.insert(v);
    }
    printf("%d\n", (int) ans.size());
    for (auto u:ans)
        printf("%d ", u);
    return 0;
}