#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#define dis_t dis_t233
#define mx_dis_t mx_dis_t233
using namespace std;
const int N = 300101;
long long dis_s[N], dis_t[N], mx_dis_s[N], mx_dis_t[N];
int n, m;
int fa[N];
bool sig;
int d[N];
vector<int> q;
set<pair<int, int> > w;
vector<pair<int, int> > g[N];
void dfs(int x, long long*dis) {
    for (auto u:g[x])
        if (u.first != fa[x]) {
            fa[u.first] = x;
            dis[u.first] = dis[x] + u.second;
            dfs(u.first, dis);
        }
}
void dfs(int x, int fa) {
    q.push_back(x);
    for (auto u:g[x])
        if (u.first != fa) {
            dfs(u.first, x);
        }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }
    fa[1] = 0;
    dfs(1, dis_s);
    fa[n] = 0;
    dfs(n, dis_t);
    d[0] = d[1] = 1;
    while (d[d[0]]!=n) {
        d[d[0]+1] = fa[d[d[0]]];
        d[0]++;
        w.insert(make_pair(d[d[0]], d[d[0] - 1]));
        w.insert(make_pair(d[d[0] - 1], d[d[0]]));
    }
    for (int i = 1; i <= d[0]; i ++) {
        q.clear();
        for (auto u:g[d[i]])
            if (w.find(make_pair(u.first, d[i])) == w.end()) {
                dfs(u.first, d[i]);
            }
        if (q.size() > 1) {
            sig = 1;
        } else {
            if (q.size())
                mx_dis_s[i] = dis_s[q[0]], mx_dis_t[i] = dis_t[q[0]];
        }
    }
    long long mx = 0, last_mx = 0, last_mxx = 0;
    for (int i = 1; i <= d[0]; i ++) {
        if (i - 2 >= 1 && i <= d[0]) {
            mx = max(mx, dis_s[d[i - 2]] + dis_t[d[i]]);
        }
        if (i != 1 && mx_dis_t[i])
            mx = max(mx, last_mxx + mx_dis_t[i]);
        if (i != 1 && last_mx)
            mx = max(mx, last_mx + dis_t[d[i]]);
        if (mx_dis_s[i])
            last_mx = max(mx_dis_s[i], last_mx), last_mxx = max(mx_dis_s[i], last_mxx);
        last_mxx = max(last_mxx, dis_s[d[i]]);
    }
    long long orig = dis_s[n];
    while (m --) {
        long long v;
        scanf("%lld", &v);
        if (sig) printf("%lld\n", orig);
        else
            printf("%lld\n", min(orig, mx + v));
    }
    return 0;
}