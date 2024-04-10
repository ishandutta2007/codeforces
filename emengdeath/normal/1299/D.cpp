#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int N = 5;
const int mod = 1e9 + 7;
const int M = 1e5 + 10;

namespace fastrand{
    unsigned long long x;
    void srand(unsigned long long seed) {x=seed;}
    unsigned long long gen() {
        x ^= x << 49;
        x ^= x >> 15;
        x ^= x << 35;
        return x >> 2;
    }
}

struct LinearBasis{
    unsigned int d[N + N];
    int tot = 0;
    void insert(unsigned int x){
        if (x)
            d[tot ++] = x;
    }
    void build(){
        int x = (1 << (N - 1));
        for (int i = 0; i < tot && x; i ++) {
            for (int j = i; j < tot; j ++)
                if (x &d[j]) {
                    if (i != j)
                        d[i] ^= d[j];
                    break;
                }
            if (x & d[i]) {
                for (int j = 0 ; j < tot; j ++)
                    if ((x &d[j]) &&i !=j) {
                        d[j] ^= d[i];
                    }
            } else x >>= 1, i --;
        }
    }
    bool can_describe(unsigned int x) {
        for (int j = 0; j < tot;j ++)
            if ((x ^ d[j]) < x)
                x ^= d[j];
        return x == 0;
    }
}f[400], tmp;
vector<int> h[400];
map<vector<int>, int> w;
int tot;
int behave[400][400];
int n, m;
struct node{
    int to, v, id;
    node(int to = 0, int v = 0, int id = 0):to(to), v(v), id(id) {}
};
vector<node> g[M];
int bz[M];
int F[400], c[400];
int edge[M][3];
unsigned long long tp[M];
vector<int> p, q;
struct node1{
    int x, y, xy;
    node1(int x = 0, int y = 0, int xy = 0) : x(x), y(y), xy(xy){}
};
vector<node1> pp;
bool tag[M][32][2];
unsigned  long long from[M][32][2][2];
bool first[M];
void dfs(int x, int v, unsigned long long fa, bool si) {
    if (!from[x][v][si][0])
        from[x][v][si][0] = fa + 1;
    else
        if (!from[x][v][si][1] && from[x][v][si][0] != fa + 1)
            from[x][v][si][1] = fa + 1;
    if (tag[x][v][si]) return;
    tag[x][v][si] = 1;
    for (auto u:g[x])
        if (u.to != 1) {
            dfs(u.to, v ^ u.v, tp[u.id] ^ fa, si);
            if (!first[u.id]) {
                first[u.id] = 1;
                q.push_back(u.id);
            }
        }
}
int sig[32];
void work(int tagi, int tagj){
    for (auto u:q) {
        int x = edge[u][0], y = edge[u][1];
        for (int i = 0; i < 32; i++)
            if (tag[x][i][tagi])
                for (int j = 0; j < 32 ;j ++)
                    if (tag[y][j][tagj])
                        for (int ii = 0; ii < 2; ii ++)
                            if (from[x][i][tagi][ii])
                                for (int jj = 0; jj < 2; jj ++)
                                    if (from[y][j][tagj][jj] && (tagi != tagj|| ((from[y][j][tagj][jj]  -1) ^ (from[x][i][tagi][ii] - 1) ^ tp[u])))
                                        sig[i ^j ^ edge[u][2]] = 1;
    }
}
int check() {
    if (sig[0])
        return 0;
    tmp.tot= 0;
    for (int i = 1; i < 32; i ++)
        if (sig[i])
        {
            if (tmp.can_describe(i)) {
                continue;
            }
            tmp.insert(i);
            tmp.build();
        }
    if (tmp.tot == 0)
        return -1;
    vector<int>h;
    for (int i = 0; i < tmp.tot; i ++)
        h.push_back(tmp.d[i]);
    return w[h];
}
void work(int& ans, int i, int res) {
    if (res == -1)
        (ans += F[i]) %= mod;
    else
        if (res && behave[res][i])
            (ans += F[i]) %= mod;
}
int edgex2y[M];
int main(){
    for (int i = 1; i < (1 << 5); i ++) {
        for (int j = tot; j >= 1; j --) {
            if (!f[j].can_describe(i)) {
                ++tot;
                f[tot].tot = 0;
                for (auto u:h[j])
                    f[tot].insert(u);
                f[tot].insert(i);
                f[tot].build();
                h[tot].clear();
                for (int k = 0;k < f[tot].tot;k ++)
                    h[tot].push_back(f[tot].d[k]);
                if (w.find(h[tot])!= w.end()) {
                    tot --;
                    continue;
                }
                w[h[tot]] = tot;
            }
        }
        f[++tot].tot = 0;
        f[tot].insert(i);
        f[tot].build();
        h[tot].clear();
        h[tot].push_back(i);
        w[h[tot]] = tot;
    }
    for (int i = 1; i <= tot; i ++)
        for (int j = 1; j <= tot; j ++)
        {
            tmp.tot = 0;
            for (auto u:h[j])
                tmp.insert(u);
            for (auto u:h[i])
                tmp.insert(u);
            tmp.build();
            bool is_zero = 0;
            for (int i = 0; i < tmp.tot; i ++)
                is_zero |= (tmp.d[i] == 0);
            if (is_zero) continue;
            q.clear();
            for (int k = 0; k < tmp.tot; k ++)
                q.push_back(tmp.d[k]);
            behave[i][j] = w[q];
        }
    scanf("%d %d", &n, &m);
    srand(123456789);
    for (int i = 1; i <= m ; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x > y) swap(x, y);
        edge[i][0] = x, edge[i][1] = y, edge[i][2]  =z;
        g[x].push_back(node(y, z, i));
        g[y].push_back(node(x, z, i));
        tp[i] = rand();
    }
    int extra = 1;
    for (auto u:g[1]) {
        for (auto v:g[u.to])
            if (v.to != 1 && bz[v.to]) {
                edgex2y[bz[v.to]] = u.id;
                edgex2y[u.id] = -1;
                break;
            }
        bz[u.to] = u.id;
    }
    for (auto u:g[1]){
        if (edgex2y[u.id] == -1) continue;
        if (!edgex2y[u.id]) {
            q.clear();
            dfs(u.to, u.v, tp[u.id], 0);
            memset(sig, 0, sizeof(sig));
            work(0, 0);
            int res = check();
            if (res == -1) extra = extra * 2 % mod;
            else
                p.push_back(res);
        } else {
            q.clear();
            dfs(u.to, u.v, tp[u.id], 0);
            dfs(edge[edgex2y[u.id]][1], edge[edgex2y[u.id]][2], tp[edgex2y[u.id]], 1);
            memset(sig, 0, sizeof(sig));
            work(0, 0);
            int x = check();
            work(1, 0);
            work(0, 1);
            work(1, 1);
            int xy = check();
            memset(sig, 0, sizeof(sig));
            work(1, 1);
            int y = check();
            pp.push_back(node1(x, y, xy));
        }
    }
    for (auto u:p) {
        for (int i = 0; i <= tot; i++)
            (c[behave[u][i]] += F[i]) %= mod;
        for (int i = 0; i <= tot; i ++)
            (F[i] += c[i]) %= mod, c[i] = 0;
        (F[u] += 1) %= mod;
    }
    int ans = 0;
    int extra_1 = 1;
    for (auto u:pp){
        int sum = 1;
        if (u.x == -1) {
            sum ++;
            for (int i = 0; i <= tot; i++)
                (c[i] += F[i]) %= mod;
        } else {
            for (int i = 0; i <= tot; i++)
                (c[behave[u.x][i]] += F[i]) %= mod;
            (c[u.x] += extra_1 ) %= mod;
        }
        if (u.y == -1) {
            sum ++;
            for (int i = 0; i <= tot; i++)
                (c[i] += F[i]) %= mod;
        } else {
            for (int i = 0; i <= tot; i++)
                (c[behave[u.y][i]] += F[i]) %= mod;
            (c[u.y] += extra_1 ) %= mod;
        }
        if (u.xy == -1) {
            sum ++;
            for (int i = 0; i <= tot; i++)
                (c[i] += F[i]) %= mod;
        } else {
            for (int i = 0; i <= tot; i++)
                (c[behave[u.xy][i]] += F[i]) %= mod;
            (c[u.xy] += extra_1) %= mod;
        }
        for (int i = 0; i <= tot; i ++)
            (F[i] += c[i]) %= mod, c[i] = 0;
        extra_1 = 1ll * extra_1 * sum % mod;
    }
    for (int i = 1; i <= tot; i ++)
        ans = (ans + 1ll * F[i] * extra) % mod;
    (ans += 1ll * extra * extra_1) %= mod;
    printf("%d\n", ans);
    return 0;
}