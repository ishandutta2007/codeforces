#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 250010;
struct ST{
    struct node{
        int sum;
        long long all;
    };
    vector<node> f;
    int n;
    void build(int l, int r, int s, vector<pair<int, int> >&a) {
        if (l == r) {
            f[s].sum = 0;
            f[s].all = a[l].first;
            return;
        }
        build(l, (l + r) / 2, s + s, a);
        build((l + r) /2 +1, r, s + s + 1, a);
        f[s].sum = f[s+s].sum + f[s+s+1].sum;
        f[s].all = f[s+s].all * (f[s+s].sum > 0) + f[s+s+1].all * (f[s+s+1].sum > 0);
    }
    void init(vector<pair<int, int> >&a) {
        if (!a.size()) {
            f.resize(2);
            f[1].sum = 0;
            n = 1;
        } else {
            f.resize(a.size() * 4 + 1);
            build(0, (int) a.size() - 1, 1, a);
            n = a.size();
        }
    }
    void ins(int l, int r, int s, int ll) {
        if (l == r) {
            f[s].sum = 1;
            return;
        }
        if ((l + r) / 2 >= ll) ins(l, (l + r) / 2, s + s, ll);
        else
            ins((l + r) / 2 + 1, r, s + s + 1, ll);
        f[s].sum = f[s+s].sum + f[s+s+1].sum;
        f[s].all = f[s+s].all * (f[s+s].sum > 0) + f[s+s+1].all * (f[s+s+1].sum > 0);
    }
    long long get(int l, int r, int s, int ll) {
        if (ll <= 0||!f[s].sum) return 0;
        if (f[s].sum <= ll) return f[s].all;
        return get(l, (l + r) / 2, s + s, ll) + get((l + r)/ 2+ 1, r, s + s + 1, ll - f[s+s].sum);
    }
}t[N];
vector<pair<pair<int, int>, int> > g[N];
int n;
int w[N][2];
int fa[N], fav[N];
long long dp[N][2];
vector<int> du[N], can_use[N];
void dfs(int x) {
    vector<pair<int, int> > a;
    for (auto u:g[x])
        if (u.first.first != fa[x]) {
            fa[u.first.first] = x;
            fav[u.first.first] = u.first.second;
            dfs(u.first.first);
            a.push_back({u.first.second, u.second});
        }
    sort(a.begin(), a.end());
    t[x].init(a);
    for (int i = 0; i < a.size(); i ++)
        w[a[i].second][0] = x, w[a[i].second][1] = i;
}
void dfs(int x, int lim) {
    long long all = 0;
    vector<long long>d;
    for (auto u:g[x])
        if (u.first.first != fa[x]) {
            if (g[u.first.first].size() <= lim) break;
            dfs(u.first.first, lim);
            d.push_back(dp[u.first.first][1] - dp[u.first.first][0] + u.first.second);
            all += dp[u.first.first][0];
        }
    sort(d.begin(), d.end());
    dp[x][0] = dp[x][1] = 1e18;
    for (int i = 0; i <= d.size();i ++) {
        if (i) all += d[i - 1];
        for (int j = 0; j < 2; j++) {
            if (t[x].f[1].sum >= (int) g[x].size() - lim - j - i)
                dp[x][j] = min(dp[x][j],
                               t[x].get(0, t[x].n - 1, 1, (int) g[x].size() - lim - j - i)  + all);
        }
    }
    dp[x][1] = min(dp[x][0], dp[x][1]);
}
int main() {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i < n ; i ++)
    {
        int x ,y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back({{y, z}, i});
        g[y].push_back({{x, z}, i});
        ans += z;
    }
    dfs(1);
    for (int i = 1; i <= n; i ++) {
        sort(g[i].begin(), g[i].end(),
             [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) { return g[x.first.first].size() > g[y.first.first].size(); });
        du[g[i].size()].push_back(i);
        for (int j = 1; j < g[i].size(); j ++)
            can_use[j].push_back(i);
    }
    printf("%lld" , ans);
    for (int i = 1; i < n; i ++) {
        for (auto u:du[i])
            for (auto v:g[u])
                t[w[v.second][0]].ins(0, t[w[v.second][0]].n - 1, 1, w[v.second][1]);
        long long ans = 0;
        for (auto u:can_use[i])
            if (u == 1 || g[fa[u]].size() <= i) {
                dfs(u, i);
                if (u == 1)
                    ans += dp[u][0];
                else
                    ans += min(dp[u][1] + fav[u], dp[u][0]);
            }
        printf(" %lld", ans);
    }
    return 0;
}