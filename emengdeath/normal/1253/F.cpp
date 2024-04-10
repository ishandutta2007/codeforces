#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int n, m, k, q;
int fa[N];
long long dis[N];
long long ans[N];
vector<pair<int, int> > g[N], Q[N];
priority_queue<pair<long long, pair<int, int> > > h;
int getfa(int x) {return x == fa[x] ? x: fa[x] = getfa(fa[x]);}
void update(int x) {
    for (auto u:g[x])
        if (dis[u.first] > dis[x] + u.second) {
            h.push(make_pair(-(dis[u.first] = dis[x] + u.second), make_pair(u.first, x)));
        }
}
void combine1(int x, int y) {
    update(x);
    x = getfa(x), y = getfa(y);
    fa[x] = y;
}
void combine(int x, int y, long long v) {
    x = getfa(x), y = getfa(y);
    if (x == y) return;
    if (Q[x].size() < Q[y].size())
        swap(x, y);
    fa[y] = x;
    for (auto u:Q[y])
        if (getfa(x) == getfa(u.first)) {
            if (!ans[u.second])ans[u.second] = v;
        }else
            Q[x].push_back(u);

}
int main() {
    scanf("%d %d %d %d", &n , &m, &k, &q);
    for (int i = 1;i <= m; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        Q[x].push_back(make_pair(y, i));
        Q[y].push_back(make_pair(x, i));
    }
    for (int i = 1; i <= n; i ++)
        fa[i] = i;
    for (int i = k + 1; i <= n; i ++)
        dis[i] = 1e18;
    for (int i= 1; i <= k; i ++)
        update(i);
    while (!h.empty()) {
        auto x = h.top();
        h.pop();
        if (dis[x.second.first] != -x.first) continue;
        combine1(x.second.first, x.second.second);
    }
    for (int i = 1; i <= n; i ++)
        for (auto u:g[i])
            h.push(make_pair(-dis[i] - dis[u.first] - u.second, make_pair(u.first, i)));
    while (!h.empty()) {
        auto x = h.top();
        h.pop();
        combine(x.second.first, x.second.second, -x.first);
    }
    for (int i = 1; i <= q; i ++)
        printf("%lld\n", ans[i]);
    return 0;
}