#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char buf[1 << 21], *S = buf, *T = buf;
#define gc ((S == T && (S = buf, T = buf + fread(buf, 1, 1 << 21, stdin), S == T)) ? EOF : *(S++))
// #define gc getchar()
inline ll read() {
    ll a = 0;
    int c = gc;
    for(; c < '0' || c > '9'; c = gc);
    for(; c >= '0' && c <= '9'; c = gc) a = (a << 1) + (a << 3) + (c ^ '0');
    return a;
}
struct edge {
    int v;
    ll w1, w2;
    int nxt;
    edge() {}
    edge(int _v, ll W1, ll W2, int next) : v(_v), w1(W1), w2(W2), nxt(next) {}
} e[600010];
int head[300010], tot, dep[300010];
int f[300010][20];
ll c[300010][20][2][2];
ll w[300010];
inline void addedge(int u, int v, ll w1, ll w2) {
    e[++tot] = edge(v, w1, w2, head[u]);
    head[u] = tot;
}
inline void dp1(int now, int f) {
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == f) continue;
        dp1(e[i].v, now);
        w[now] = min(w[now], w[e[i].v] + e[i].w1 + e[i].w2);
    }
}
inline void dp2(int now, int f) {
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == f) continue;
        w[e[i].v] = min(w[e[i].v], w[now] + e[i].w1 + e[i].w2);
        dp2(e[i].v, now);
    }
}
inline void dfs(int now, int fa) {
    dep[now] = dep[fa] + 1;
    for(int i = head[now]; i; i = e[i].nxt) {
        if(e[i].v == fa) continue;
        f[e[i].v][0] = now;
        c[e[i].v][0][0][0] = min(e[i].w2, e[i].w1 + w[now] + w[e[i].v]);
        c[e[i].v][0][0][1] = min(e[i].w1 + w[e[i].v], e[i].w2 + w[now]);
        c[e[i].v][0][1][0] = min(e[i].w2 + w[e[i].v], e[i].w1 + w[now]);
        c[e[i].v][0][1][1] = min(e[i].w1, e[i].w2 + w[now] + w[e[i].v]);
        dfs(e[i].v, now);
    }
}
int n, q;
inline void ready() {
    for(int j = 1; j < 20; j++)
        for(int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1],
            c[i][j][0][0] = min(c[i][j - 1][0][0] + c[f[i][j - 1]][j - 1][0][0], c[i][j - 1][0][1] + c[f[i][j - 1]][j - 1][1][0]),
            c[i][j][1][0] = min(c[i][j - 1][1][0] + c[f[i][j - 1]][j - 1][0][0], c[i][j - 1][1][1] + c[f[i][j - 1]][j - 1][1][0]),
            c[i][j][0][1] = min(c[i][j - 1][0][0] + c[f[i][j - 1]][j - 1][0][1], c[i][j - 1][0][1] + c[f[i][j - 1]][j - 1][1][1]),
            c[i][j][1][1] = min(c[i][j - 1][1][0] + c[f[i][j - 1]][j - 1][0][1], c[i][j - 1][1][1] + c[f[i][j - 1]][j - 1][1][1]);
}
inline ll get(int a, int typea, int b, int typeb) {
    if(dep[a] < dep[b]) swap(a, b), swap(typea, typeb);
    ll a0 = typea ? w[a] : 0, b0 = typeb ? w[b] : 0;
    ll a1 = w[a] - a0, b1 = w[b] - b0, new0, new1;
    for(int i = 19; i >= 0; i--) if(dep[f[a][i]] >= dep[b]) {
        new0 = min(a0 + c[a][i][0][0], a1 + c[a][i][1][0]),
        new1 = min(a0 + c[a][i][0][1], a1 + c[a][i][1][1]);
        a0 = new0, a1 = new1;
        a = f[a][i];
    }
    if(a == b) return min(a0 + b0, a1 + b1);
    for(int i = 19; i >= 0; i--) if(f[a][i] != f[b][i]) {
        new0 = min(a0 + c[a][i][0][0], a1 + c[a][i][1][0]);
        new1 = min(a0 + c[a][i][0][1], a1 + c[a][i][1][1]);
        a0 = new0, a1 = new1;
        a = f[a][i];
        new0 = min(b0 + c[b][i][0][0], b1 + c[b][i][1][0]);
        new1 = min(b0 + c[b][i][0][1], b1 + c[b][i][1][1]);
        b0 = new0, b1 = new1;
        b = f[b][i];
    }
    new0 = min(a0 + c[a][0][0][0], a1 + c[a][0][1][0]),
    new1 = min(a0 + c[a][0][0][1], a1 + c[a][0][1][1]);
    a0 = new0, a1 = new1;
    a = f[a][0];
    new0 = min(b0 + c[b][0][0][0], b1 + c[b][0][1][0]),
    new1 = min(b0 + c[b][0][0][1], b1 + c[b][0][1][1]);
    b0 = new0, b1 = new1;
    b = f[b][0];
    return min(a0 + b0, a1 + b1);
}
ll u, v, w1, w2;
int main() {
    // freopen("hehezhou.in", "r", stdin);
    // freopen("hehezhou.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++) w[i] = read();
    for(int i = 1; i < n; i++) u = read(), v = read(), w1 = read(), w2 = read(), addedge(u, v, w1, w2), addedge(v, u, w1, w2);
    dp1(1, 0);
    dp2(1, 0);
    dfs(1, 0);
    ready();
    q = read();
    for(int i = 1; i <= q; i++) {
        u = read(), v = read();
        printf("%lld\n", get((u + 1) >> 1, u & 1, (v + 1) >> 1, v & 1));
    }
    return 0;
}