#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int S = 3;
const int N = 2e5 + 10;
const int mod[S] = {998244353, 1000000000 + 7, 1000000000 + 9};
struct node{
    int v[S];
}tmp, g[N];
char st[N];
int add(int x, int y, int mod) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y, int mod) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y, int mod){
    return 1ll * x * y % mod;
}
node operator+(const node &a,const node &b) {
    for (int i = 0; i < S; i ++)
        tmp.v[i] = add(a.v[i], b.v[i], mod[i]);
    return tmp;
}
node operator-(const node &a,const node &b) {
    for (int i = 0; i < S; i ++)
        tmp.v[i] = sub(a.v[i], b.v[i], mod[i]);
    return tmp;
}
node operator*(const node &a,const node &b) {
    for (int i = 0; i < S; i ++)
        tmp.v[i] = mul(a.v[i], b.v[i], mod[i]);
    return tmp;
}
bool operator==(const node&a, const node&b) {
    for (int i = 0; i < S; i ++)
        if (a.v[i] != b.v[i])
            return 0;
    return 1;
}
int n;
struct node1{
    node v;
    int zeros, v2;
    bool l, r;
}f[N * 4], d;
void merge(node1&a, node1 b, node1 c) {
    if (b.r && c.l) {
        a.v2 = b.v2 + c.v2 + 1;
        b.v = b.v - g[b.zeros];
        c.v = c.v - g[0];
        a.v = b.v + (c.v * g[b.zeros]);
    } else {
        a.v = b.v + (c.v * g[b.zeros]);
        a.v2 = b.v2 + c.v2;
    }
    a.zeros = b.zeros + c.zeros;
    if (!b.zeros)
        a.l = (b.l ^ c.l);
    else
        a.l = b.l;
    if (!c.zeros)
        a.r = (c.r ^ b.r);
    else
        a.r = c.r;
}
void build(int l, int r, int s) {
    if (l == r) {
        if (st[l]== '1') {
            f[s].v = g[0];
            f[s].l = f[s].r = 1;
        } else {
            f[s].zeros = 1;
        }
        return;
    }
    build(l, (l + r) /2, s + s);
    build((l + r) / 2 +1, r, s + s + 1);
    merge(f[s], f[s +s], f[s+ s+ 1]);
}
void get(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        if (ll == l)
            d = f[s];
        else
            merge(d, d, f[s]);
        return;
    }
    get(l, (l + r) / 2, s + s, ll, rr);
    get((l + r) /2 +1, r, s+ s+ 1,ll, rr);
}
int main() {
    for (int i = 0; i < S; i ++)
        g[0].v[i] = 1, g[1].v[i] = N;
    scanf("%d", &n);
    scanf("%s", st + 1);
    for (int i = 2; i <= n; i ++)
        g[i] = g[i - 1] * g[1];
    build(1, n, 1);
    int q;
    scanf("%d", &q);
    while (q --) {
        int l1, l2, len;
        scanf("%d %d %d", &l1, &l2, &len);
        get(1, n, 1, l1, l1 + len - 1);
        node1 d1 = d;
        get(1, n, 1, l2, l2 + len - 1);
        if (d1.v == d.v && d1.v2 == d.v2) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}