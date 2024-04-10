#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
vector<pair<int, int> > g[N], e[N];
int n, m, k;
bool bz[N], bz1[N];
int w[N], cnt, tmp[N];
long long v[N];
int dfn[N], low[N], stack[N], tot, instack[N], bel[N];
int allbz, cntbz[N];
long long ans[N];
long long fl[N][2], fr[N][2], f[N][2], c[2];
void tdfs(int x, int fa) {
    low[x] = dfn[x] = ++tot;
    instack[stack[++stack[0]] = x] = 1;
    for (auto u:e[x])
        if (u.first != fa) {
            if (!dfn[u.first]) {
                tdfs(u.first, x);
                low[x] = min(low[x], low[u.first]);
            } else if (instack[u.first])
                low[x] = min(low[x], dfn[u.first]);
        }{}
    if (dfn[x] == low[x]) {
        ++cnt;
        do{
            bel[stack[stack[0]]] = cnt;
            instack[stack[stack[0]--]] = 0;
        } while (stack[stack[0] + 1] != x);
    }
}
void mymerge(long long*a, long long*b, bool sig1, bool sig2, long long*d, long long w) {
    c[0] = -1e18;
    c[1] = -1e18;
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++) {
            int v = 0;
            if (sig2 && (j && sig1))
                v = -w;
            c[i|j] = max(c[i|j], a[i] + b[j] + v);
        }
    d[0] = c[0];
    d[1] = c[1];
}
void dfs(int x, int fa) {
    long long l[2] = {0, 0}, r[2] = {0, 0};
    for (int i = 0; i < g[x].size(); i ++)
        if (g[x][i].first == fa) {
            swap(g[x][i], g[x][g[x].size() - 1]);
            g[x].pop_back();
            break;
        }
    for (auto u:g[x])
        if (u.first != fa) {
            dfs(u.first, x);
            cntbz[x] += cntbz[u.first];
            mymerge(l, f[u.first], (allbz - cntbz[u.first] > 0), (cntbz[u.first] > 0), l, u.second);
            fl[u.first][0] = l[0];
            fl[u.first][1] = l[1];
        }
    for (int i = (int)g[x].size() - 1; i >= 0; i --) {
        auto u = g[x][i];
        mymerge(r, f[u.first], (allbz - cntbz[u.first] > 0), (cntbz[u.first] > 0), r, u.second);
        fr[u.first][0] = r[0];
        fr[u.first][1] = r[1];
    }
    f[x][0] = 0;
    f[x][1] = v[x];
    mymerge(f[x], l, (allbz - cntbz[x] > 0), (cntbz[x] > 0), f[x], 0);
    cntbz[x] += bz1[x];
}
void dfs1(int x, long long*upf, long long ev) {
    long long tmp[2] = {0, 0};
    long long tmp1[2] = {0, 0};
    tmp[0] = -1e18;
    tmp[1] = v[x];
    mymerge(tmp, upf, (cntbz[x] > 0), (allbz - cntbz[x]> 0), tmp, ev);
    if (g[x].size()) {
        mymerge(tmp, fr[g[x][0].first], 0, 0, tmp, 0);
    }
    ans[x] = tmp[1];
    tmp[0] = 0;
    tmp[1] = v[x];
    mymerge(tmp, upf, (cntbz[x] > 0), (allbz - cntbz[x]> 0), tmp, ev);
    for (int i = 0; i < g[x].size(); i ++) {
        tmp1[0] = tmp[0];
        tmp1[1] = tmp[1];
        if (i)
            mymerge(tmp1, fl[g[x][i - 1].first], 0 ,0, tmp1, 0);
        if (i + 1 < g[x].size())
            mymerge(tmp1, fr[g[x][i + 1].first], 0, 0, tmp1, 0);
        dfs1(g[x][i].first, tmp1, g[x][i].second);
    }
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i ++)
    {
        int x;
        scanf("%d", &x);
        bz[x] = 1;
    }
    for (int i = 1; i <= n;i ++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m;i ++)
        scanf("%d", &tmp[i]);
    for (int i = 1; i <= m;i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].push_back({y, tmp[i]});
        e[y].push_back({x, tmp[i]});
    }
    tdfs(1, 0);
    for (int i = 1; i <= n;i ++) {
        v[bel[i]] += w[i];
        bz1[bel[i]] |= bz[i];
        for (auto u:e[i])
            if (bel[i] != bel[u.first])
                g[bel[i]].push_back({bel[u.first], u.second});
    }
    for (int i = 1; i <= cnt; i ++)
        allbz += bz1[i];
    dfs(1, 0);
    long long w[2] = {0, 0};
    dfs1(1, w, 0);
    for (int i = 1; i <= n;i ++)
        printf("%lld%c", ans[bel[i]], " \n"[i == n]);
    return 0;
}