#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 5e5 + 10;
int n, m;
vector<pair<int, int> > g[N];
pair<int, int> b[N][2];
int len[N], deep[N], l[N], r[N], cnt, sig[N], l2id[N];
int ans[N];
int edge[N][2], q[N];
struct node{
    int v[2];
    bool tag;
    void clear() {
        v[0] = v[1] = 0;
        tag = 0;
    }
}f[N * 4];
void dfs(int x, int fa) {
    for (auto u:g[x])
        if (u.first != fa) {
            dfs(u.first, x);
            if (b[u.first][0].second + 1 >= b[x][0].second) {
                b[x][1] = b[x][0];
                b[x][0] = {u.first, b[u.first][0].second + 1};
            } else {
                if (b[u.first][0].second + 1 > b[x][1].second) {
                    b[x][1] = {u.first, b[u.first][0].second + 1};
                }
            }
        }
}
void dfs(int x, int up, int fa) {
    len[x] = max(b[x][0].second, up);
    for (auto u:g[x])
        if (u.first != fa) {
            int up1 = up;
            if (u.first != b[x][0].first)
                up1 = max(up1, b[x][0].second);
            else
                up1 = max(up1, b[x][1].second);
            dfs(u.first, up1 + 1, x);
        }
}
void dfs1(int x, int fa) {
    l2id[l[x] = ++cnt] = x;
    deep[x] ++;
    for (auto u:g[x])
        if (u.first != fa) {
            sig[u.first] = (sig[x] ^ u.second);
            deep[u.first] = deep[x];
            dfs1(u.first, x);
        }
    r[x] = cnt;
}
void down(int l, int r, int s) {
    if (f[s].tag){
        swap(f[s].v[0], f[s].v[1]);
        if (l != r)
            f[s+s].tag ^= f[s].tag, f[s+s+1].tag ^= f[s].tag;
        f[s].tag = 0;
    }
}
void merge(int s) {
    f[s].v[0] = max(f[s+s+1].v[0], f[s+s].v[0]);
    f[s].v[1] = max(f[s+s+1].v[1], f[s+s].v[1]);
}
void build(int l, int r, int s) {
    f[s].clear();
    if (l == r) {
        f[s].v[sig[l2id[l]]] = deep[l2id[l]];
        return;
    }
    build(l, (l+r)/2,s+s);
    build((l+r)/2 + 1, r, s+s+1);
    merge(s);
}
void change(int l, int r, int s ,int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag = 1;
        down(l, r, s);
        return;
    }
    change(l, (l+r)/2, s + s, ll, rr);
    change((l+r)/2 + 1, r, s + s + 1, ll, rr);
    merge(s);
}
void work(int root) {
    cnt = 0;
    deep[root] = -1;
    sig[root] = 0;
    dfs1(root, 0);
    build(1, n, 1);
    for (int i = 1; i <= m;i  ++) {
        int x;
        if (deep[edge[q[i]][0]] > deep[edge[q[i]][1]])
            x = edge[q[i]][0];
        else
            x = edge[q[i]][1];
        change(1, n, 1, l[x], r[x]);
        ans[i] = max(ans[i], f[1].v[0]);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back({y, z});
        g[y].push_back({x, z});
        edge[i][0] = x, edge[i][1] = y;
    }
    dfs(1, 0);
    dfs(1, 0, 0);
    int mx = 0;
    for (int i = 1; i <= n ; i ++) {
        mx = max(len[i], mx);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &q[i]);
    }
    for (int i = 1; i <= n; i ++)
        if (len[i] == mx) {
            work(i);
            deep[i] = -1;
            dfs1(i, 0);
            for (int j = 1; j <= n;j ++)
                if (deep[j] == mx) {
                    work(j);
                    break;
                }
            break;
        }
    for (int i = 1; i <= m;i ++)
        printf("%d\n", ans[i]);
    return 0;
}