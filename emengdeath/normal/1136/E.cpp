#include <cstdio>
#include <algorithm>
#define fo(i, l, r) for(int i = l ;i <= r; i ++)
using namespace std;
const int N = 1e6;
struct node{
    long long sum;
    long long mn, mx;
    long long tag;
    bool havetag;
}f[N * 4];
int a[N];
long long w[N];
int n, m;
void combine(int s) {
    f[s].mn = min(f[s<<1].mn, f[s<<1|1].mn );
    f[s].mx = max(f[s<<1].mx, f[s<<1|1].mx );
    f[s].sum = f[s<<1].sum + f[s<<1|1].sum;
}
void down(int l, int r ,int s ) {
    if (f[s].havetag) {
        f[s].mn = f[s].tag;
        f[s].mx = f[s].tag;
        f[s].sum = (r - l + 1) * f[s].tag;
        if (l != r)
            f[s<<1].havetag = 1, f[s<<1].tag = f[s].tag, f[s<<1|1].tag = f[s].tag, f[s<<1|1].havetag = 1;
        f[s].havetag = 0;
    }
}
void build(int l ,int r,int s) {
    if (l == r) {
        f[s].mn = f[s].sum = f[s].mx= a[l] - w[l];
        return;
    }
    build(l, (l + r) >> 1, s << 1);
    build((l + r) / 2 + 1 , r , s << 1 | 1);
    combine(s);
}
bool ins(int l, int r, int s, int ll, long long v) {
    down(l, r, s);
    if (r < ll) return 1;
    if (f[s].mn >= v) return 0;
    if (l >= ll && f[s].mx < v) {
        f[s].tag = v;
        f[s].havetag = 1;
        down(l, r, s);
        return 1;
    }
    bool sig = ins(l, (l + r) / 2, s + s, ll, v) && ins((l + r) / 2 + 1, r , s + s + 1, ll, v);
    combine(s);
    return sig;
}
long long get(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return 0;
    if (ll <= l && r <= rr ){
        return f[s].sum;
    }
    return get(l, (l + r) / 2, s + s, ll, rr) + get((l + r) / 2 + 1, r, s + s + 1, ll, rr);
}
int main() {
    scanf("%d", &n);
    fo(i, 1, n)
        scanf("%d", &a[i]);
    fo(i, 2, n) {
        scanf("%lld", &w[i]);
        w[i] += w[i -1];
    }
    build(1, n, 1);
    fo(i, 2, n)
        w[i] += w[i - 1];
    scanf("%d", &m);
    while (m --) {
        char sig;
        int x, y;
        scanf(" %c %d %d",&sig, &x, &y);
        if (sig == 's') {
            printf("%lld\n", get(1, n, 1, x, y)+ w[y] - w[x - 1]);
        } else
            ins(1, n, 1, x, y + get(1, n, 1, x, x));
    }
    return 0;
}