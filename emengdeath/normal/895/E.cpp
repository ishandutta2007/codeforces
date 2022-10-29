#include <algorithm>
#include <cstdio>
using namespace std;
typedef long double ld;
const int N = 1e5 + 10;
struct node{
    ld tagadd, tagmul;
    ld v;
    int len;
    void updatemul(ld x) {
        v *= x;
        tagmul *= x;
        tagadd *= x;
    }
    void updateadd(ld x) {
        tagadd += x;
        v += x * len;
    }
}f[N * 4];
int n, m;
int a[N];
void build(int l, int r, int s) {
    f[s].tagadd = 0;
    f[s].tagmul = 1;
    f[s].len = r - l  +1;
    if (l ==r ){
        f[s].v = a[l];
        return;
    }
    build(l, (l + r) / 2, s +s);
    build((l + r) / 2 + 1, r, s +s + 1);
    f[s].v = f[s+s].v  + f[s+s+1].v;
}
void down(int l, int r, int s) {
    if (l != r) {
        f[s+s].updatemul(f[s].tagmul);
        f[s+s+1].updatemul(f[s].tagmul);
        f[s+s].updateadd(f[s].tagadd);
        f[s+s+1].updateadd(f[s].tagadd);
        f[s].tagmul = 1, f[s].tagadd = 0;
    }
}
void ins(int l, int r, int s, int ll, int rr, ld tagmul, ld tagadd) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].updatemul(tagmul);
        f[s].updateadd(tagadd);
        return;
    }
    ins(l, (l + r) / 2, s+s, ll, rr, tagmul, tagadd);
    ins((l+r)/2 + 1, r, s + s+ 1, ll, rr, tagmul, tagadd);
    f[s].v = f[s+s].v + f[s+s+1].v;
}

ld get(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return 0;
    if (ll <= l && r <= rr) {
        return f[s].v;
    }
    return get(l, (l + r) / 2, s+s, ll, rr) + get((l+r)/2 + 1, r, s + s+ 1, ll, rr);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    build(1, n, 1);
    while (m --) {
        int sig, l, r;
        scanf("%d %d %d", &sig, &l, &r);
        if (sig == 1) {
            int ll, rr;
            scanf("%d %d", &ll, &rr);
            ld all = get(1, n, 1, l, r), all1 = get(1, n, 1, ll, rr);
            int len = r - l + 1, len1 = rr - ll + 1;
            ins(1, n, 1, l, r, (ld)(len -1) / len, (ld)all1 / (1ll * len1 * len));
            ins(1, n, 1, ll, rr, (ld)(len1 -1) / len1, (ld)all / (1ll * len1 * len));
        } else {
            ld v = get(1, n, 1, l, r);
            printf("%.10f\n",(double)v);
        }
    }
    return 0;
}