#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int fa[N], v[N];
vector<pair<int, int> > g[N];
vector<pair<pair<int, int>, int> > e;
int getfa(int x) {
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
void dfs(int x, int fa) {
    for (auto u:g[x])
        if (u.first != fa) {
            v[u.first] = v[x] ^ u.second;
            dfs(u.first, x);
        }
}
const int M = 64;
typedef unsigned long long type;
struct T {
    type v[M];
    int tot;
    void clear(){
        tot = 0;
        memset(v, 0, sizeof(v));
    }
    void insert(type u) {
        for (int i = tot - 1; i >= 0; i--)
            if ((u ^ v[i]) < u) u ^= v[i];
        for (int i = 0; i < tot; i++)
            if ((u ^ v[i]) < v[i]) v[i] ^= u;
        v[tot++] = u;
        for (int i = tot - 1; v[i - 1] > v[i]&& i >= 1; i --)
            swap(v[i], v[i - 1]);
    }

    bool can_describe(type x) {
        for (int i = tot - 1; i >= 0; i--)
            if ((x ^ v[i]) < x) x ^= v[i];
        return x == 0;
    }
}w;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x, y, v;
        scanf("%d %d %d", &x, &y, &v);
        if (getfa(x) == getfa(y)) {
            e.push_back({{x, y}, v});
        }  else {
            fa[getfa(x)] = y;
            g[x].push_back({y, v});
            g[y].push_back({x, v});
        }
    }
    dfs(1, 0);
    w.clear();
    for (auto u:e) {
        int x = v[u.first.first] ^ v[u.first.second] ^ u.second;
        if (!w.can_describe(x))
            w.insert(x);
    }
    int ans = v[1] ^ v[n];
    for (int i = 0; i < w.tot; i ++)
        if ((ans ^ w.v[i]) < ans)
            ans ^= w.v[i];
    printf("%d\n", ans);
    return 0;
}