#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5 + 10;
struct node{
    int f[2][1<<5];
    bool tag;
}f[N * 4], v;
int w;
int n, q, m;
bool a[N];
bool g[7][2][1 << 6];
int change[6][1<<5];
void down(int l, int r, int s){
    if (f[s].tag){
        for (int i = 0; i < (1 <<m) ; i ++)
            swap(f[s].f[0][i],f[s].f[1][i]);
        if (l!=r)
            f[s+ s].tag ^= 1, f[s+s+1].tag ^= 1;
        else
            a[l] ^= 1;
        f[s].tag = 0;
    }
}
void combine(node &a, node b, node c) {
    for (int i = 0; i < (1 << m) ; i ++)
        a.f[0][i] = b.f[0][c.f[0][i]], a.f[1][i] = b.f[1][c.f[1][i]];
}
void build(int l, int r, int s) {
    if (l == r){
        for (int i = 0; i < (1<<m); i ++)
            for (int j = 0; j < 2; j ++)
                f[s].f[j][i] = (g[m][a[l] ^ j][i] << (m - 1)) + (i >> 1);
        return;
    }
    build(l, (l + r) /2 , s + s);
    build((l + r) /2 + 1, r , s + s +1);
    combine(f[s], f[s+s],f[s+s+1]);
}
void add(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag ^= 1;
        down(l, r, s);
        return;
    }
    add(l, (l + r) / 2, s + s, ll, rr);
    add((l + r) / 2 + 1, r, s + s +1, ll, rr);
    combine(f[s], f[s+s],f[s+s+1]);
}

void get(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        if (ll == l) v = f[s];
        else
            combine(v, v, f[s]);
        return;
    }
    get(l, (l + r) / 2, s + s, ll, rr);
    get((l + r) / 2 + 1, r, s + s +1, ll, rr);
}
void get1(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (l == r) {
        if (l == ll) {
            w = 0;
        }
        w |= (a[l] << (rr - l));
        return;
    }
    get1(l, (l + r) / 2, s + s, ll, rr);
    get1((l + r) / 2 + 1, r, s + s +1, ll, rr);
}
int main() {
    scanf("%d %d %d", &n, &m,&q);
    g[1][1][0] = 1;
    g[1][0][0] = 1;
    g[1][1][1] = 0;
    g[1][0][1] = 1;
    for (int i = 2; i <= m + 1; i ++)
        for (int sig = 1; sig >= 0; sig --)
            for (int j = (1 << i) - 1; j >= 0 ; j -- ) {
                if (!sig)
                    g[i][sig][j] |= !g[i][sig^1][j];
                for (int k = 0; k < i; k ++)
                    if ((!((j>>k)&1)) && i - k <= m) {
                        g[i][sig][j] |= 1;
                    }
            }
    change[1][1] = 0;
    change[1][0] = 1;
    for (int i = 2; i <= m; i ++) {
        for (int j = 0; j < (1 << i); j ++){
            int x = change[i - 1][j & ((1 << (i - 1)) - 1)];
            change[i][j] = x + (g[i - 1][j >> (i - 1)][x] <<(i-1));
        }
    }
    for (int i = 1; i <= n; i ++){
        long long x;
        scanf("%lld", &x);
        a[i] = (x & 1);
    }
    build(1, n , 1);
    while (q --) {
        int x, y, z;
        long long zz;
        scanf("%d %d %d", &x, &y, &z);
        if (x == 1) {
            scanf("%lld", &zz);
            if (zz &1) add(1, n, 1, y,z);
        } else {
            bool sig = 0;
            if (z - y + 1 > m) {
                get(1, n, 1, y, z - m);
                get1(1, n, 1, z - m + 1, z);
                sig = (v.f[0][change[m][w]] >> (m - 1));
            } else {
                get1(1, n, 1, y, z);
                sig = (change[z - y + 1][w] >> (z - y));
            }
            sig?puts("1"):puts("2");
        }
    }
    return 0;
}