#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
const int S = 17;
int n;
vector<int> g[N], e[N], w[N];
int dfn[N];
int c[N];
int fa[N][S + 1], deep[N];
struct node{
    int sum;
    long long v;
    void upd(long long vv, int summ) {
        if (sum < summ) sum = summ, v = vv;
        else
            if (sum == summ) v += vv;
    }
}f[N];
vector<int> d;
void dfs(int x) {//
    static int cnt = 0;
    deep[x] ++;
    dfn[x] = ++cnt;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
        }
}
int up(int x, int y){
    for (int i = S; i >= 0; i --)
        if (y >= (1 << i))
            y -= (1 << i), x = fa[x][i];
    return x;
}
int getlca(int x, int y) {
    if (deep[x] < deep[y])
        swap(x, y);
    x = up(x, deep[x] - deep[y]);
    for (int i = S; i >= 0; i --)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return x != y ? fa[x][0] : x;
}
void link(int x, int y) {
    e[x].push_back(y);
}
void add(int x) {//dfs
    if (d.empty()){
        d.push_back(x);
    } else {
        if (getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
            int last = d[d.size() - 1];
            d.pop_back();
            while (!d.empty() && getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
                link(d[d.size() - 1], last);
                last = d[d.size() - 1];
                d.pop_back();
            }
            if (d.empty() || getlca(last, x) != d[d.size() - 1] ) {
                int u = getlca(last, x);
                link(u, last);
                d.push_back(u);
            } else {
                link(d[d.size() - 1], last);
            }
        }
        d.push_back(x);
    }
}
int dfs(int x, int cc) {
    int cnt = (c[x] == cc);
    for (auto u:e[x]) {
        cnt += dfs(u, cc);
    }
    f[x].upd(cc, cnt);
    e[x].clear();
    return cnt;
}
void dfs1(int x) {
    for (auto u:g[x])
        if (u != fa[x][0]) {
            dfs1(u);
            f[x].upd(f[u].v, f[u].sum);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &c[i]);
        w[c[i]].push_back(i);
    }
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n;i ++) {
        if (w[i].empty())continue;
        sort(w[i].begin(), w[i].end(), [](int x ,int y) {return dfn[x] < dfn[y];});
        d.clear();
        for (auto u:w[i])
            add(u);
        for (int i = 0; i + 1 < d.size(); i ++)
            link(d[i], d[i + 1]);
        dfs(d[0], i);
    }
    dfs1(1);
    for (int i =1; i <= n; i ++)
        printf("%lld ", f[i].v);
    return 0;
}