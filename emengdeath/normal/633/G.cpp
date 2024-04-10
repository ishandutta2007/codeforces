#include <algorithm>
#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;
const int M = 1000;
const int N = 1e5 + 10;
struct node{
    bitset<M> v;
    int tag;
}f[N * 4];
int n, m;
int a[N];
int dfnl[N], dfnr[N], dfn2id[N];
vector<int>g[N];
bitset<M> mask, all_mask, tmp, d;
void upd(int s){
    f[s].v = f[s+s].v | f[s+s+1].v;
}
int add(int x, int y) {
    x += y;
    return x >= m? x-  m : x;
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        tmp = ((f[s].v << f[s].tag) & all_mask);
        f[s].v = (tmp | ((f[s].v ^ (tmp >> f[s].tag)) >> (m - f[s].tag)));
        if (l!=r)
            f[s+s].tag = add(f[s+s].tag, f[s].tag), f[s+s+1].tag = add(f[s+s+1].tag, f[s].tag);
        f[s].tag = 0;
    }
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].v[a[dfn2id[l]]] = 1;
        return;
    }
    build(l, (l+r)/2,s+s);
    build((l+r) /2+1,r,s+s+1);
    upd(s);
}
void dfs(int x, int fa) {
    static int cnt = 0;
    dfn2id[dfnl[x] = ++cnt] = x;
    for (auto u:g[x])
        if (u != fa) {
            dfs(u, x);
        }
    dfnr[x] = cnt;
}
void change(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag = v;
        down(l, r, s);
        return;
    }
    change(l, (l+r)/2,s+s, ll, rr, v);
    change((l+r)/2+1,r,s+s+1, ll, rr, v);
    upd(s);
}
void get(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        if (ll == l) d = f[s].v;
        else d |= f[s].v;
        return;
    }
    get(l,(l+r)/2,s+s,ll,rr);
    get((l+r)/2+1,r,s+s+1,ll,rr);
}
int main() {
    scanf("%d %d", &n, &m);
    all_mask[0] = all_mask[1] = 1;
    for (int i = 2; i < m; i ++) {
        bool sig = 1;
        all_mask[i] = 1;
        for (int j = 2; 1ll * j * j <= i; j ++)
            if (i % j == 0) {
                sig = 0;
                break;
            }
        mask[i] = sig;
    }
    for (int i = 1; i <= n;i ++) {
        scanf("%d", &a[i]);
        a[i] %= m;
    }
    for (int i= 1; i < n; i ++) {
        int x,y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    build(1, n, 1);
    int q;
    scanf("%d", &q);
    while (q --) {
        int sig, x, y;
        scanf("%d %d", &sig, &x);
        if (sig == 1) {
            scanf("%d", &y);
            change(1, n, 1, dfnl[x], dfnr[x], y % m);
        } else {
            get(1, n,1,dfnl[x],dfnr[x]);
            printf("%d\n", (int)(d&mask).count());
        }
    }
    return 0;
}