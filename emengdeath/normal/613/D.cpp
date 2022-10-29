#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int N = 1e5 + 19;
const int S = 17;
int fa[N][S + 1], deep[N], dfn[N];
int dfn_tot;
int n, m, sig;
vector<int>g[N], e[N];
vector<int> w;
set<pair<int, int> > o;
int tag[N];
bool can_do;
void dfs(int x) {//
    deep[x] ++;
    dfn[x] = ++ dfn_tot;
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
vector<int> d;
void link(int x, int y) {
    e[x].push_back(y);
    if (tag[x] == tag[y] && tag[x] == sig && o.find({x, y}) != o.end()) can_do = 0;
    if (e[x].size() == 1) w.push_back(x);
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

pair<int, int> dfs1(int x) {
    if (tag[x] == sig) {
        pair<int, int> v = {0, 1};
        for (auto u:e[x]) {
            auto w = dfs1(u);
            v.first += w.first + w.second;
        }
        return v;
    } else {
        pair<int, int> v = {0, 0};
        int sum = 0;
        for (auto u:e[x]) {
            auto w = dfs1(u);
            v.first += w.first;
            sum += w.second;
        }
        if (sum <= 1)
            v.second = sum;
        else
            v.first ++;
        return v;
    }
}
int main() {
    scanf("%d", &n);
    for (int i= 1; i < n;i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        o.insert({x, y});
        o.insert({y, x});
    }
    dfs(1);
    scanf("%d", &m);
    while (m --) {
        int y;
        scanf("%d", &y);
        sig++;
        vector<int> dd;
        while (y --) {
            int x;
            scanf("%d", &x);
            dd.push_back(x);
            tag[x] = sig;
        }
        can_do = 1;
        sort(dd.begin(), dd.end(), [](int x, int y) {return dfn[x] < dfn[y];});
        for (auto u:dd)
            add(u);
        for (int i = 1; i < d.size(); i ++)
            link(d[i - 1], d[i]);
        if (!can_do) {
            puts("-1");
        } else {
            printf("%d\n", dfs1(d[0]).first);
        }
        d.clear();
        for (auto u:w)
            e[u].clear();
        w.clear();
    }
    return 0;
}