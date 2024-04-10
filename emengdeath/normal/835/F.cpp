#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 400101;
vector<pair<int, int> > g[N];
int d[N], id[N], p[N];
long long v[N];
bool bz[N];
long long dis[N], mx[N];
int n;
long long ans;
bool dfs(int x, int fa) {
    if (id[x]) {
        for (int i = id[x] + 1; i <= d[0]; i ++)
            p[++p[0]] = d[i], dis[p[0]] = v[i - 1];
        p[++p[0]] = x;
        dis[p[0]] = v[d[0]];
        return 1;
    }
    d[++d[0]] =x;
    id[x] = d[0];
    for (auto u:g[x])
        if (u.first != fa) {
            v[d[0]] = u.second;
            if (dfs(u.first, x)) return 1;
        }
    d[0] --;
    return 0;
}
void dfs1(int x, int fa) {
    mx[x] = 0;
    for (auto u:g[x])
        if (u.first != fa && !bz[u.first]) {
            dfs1(u.first, x);
            ans = max(ans, mx[x] + mx[u.first] + u.second);
            mx[x] = max(mx[x], mx[u.first] + u.second);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    dfs(1, 0);
    int tot = p[0];
    for (int i = 1; i <= tot; i ++)
        bz[p[i]] = 1;
    for (int i= 1; i <= tot; i ++) {
        p[i + tot] = p[i], dis[i + tot] = dis[i];
        dfs1(p[i],0);
        v[i] = v[i + tot] = mx[p[i]];
    }
    for (int i = 1; i <= tot + tot; i ++)
        dis[i] += dis[i - 1];
    priority_queue<pair<long long, int> > q, qq;
    long long ans1 = 1e18;
    for (int i = 1; i <= tot + tot; i ++) {
        q.push(make_pair(v[i] - dis[i], i));
        qq.push(make_pair(v[i] + dis[i], i));
        if (i == 1 || i < tot) continue;
        pair<long long, int> a[2], b[2];
        for (int j = 0; j < 2; j ++) {
            while (i - q.top().second >= tot)q.pop();
            a[j] = q.top();
            q.pop();
        }
        for (int j = 0; j < 2; j ++) {
            while (i - qq.top().second >= tot) qq.pop();
            b[j] = qq.top();
            qq.pop();
        }
        for (int j = 0; j < 2;j ++)
            q.push(a[j]), qq.push(b[j]);
        long long w = 0;
        for (int j = 0; j < 2; j ++)
            for (int k = 0; k < 2; k ++)
                if (a[j].second != b[k].second)
                    w = max(w, a[j].first + b[k].first);
        ans1 = min(ans1, w);
    }
    printf("%lld\n", max(ans1, ans));
    return 0;
}