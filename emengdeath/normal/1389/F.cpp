#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
struct node{
    int mx;
    int tagadd;
    void addtag(int v) {
        tagadd += v;
        mx += v;
    }
}f[2][N * 4];
struct node1{
    int l, r, t;
}a[N];
void down(int l, int r, int s, node*f) {
    if (f[s].tagadd) {
        if (l != r) {
            f[s+s].addtag(f[s].tagadd);
            f[s+s+1].addtag(f[s].tagadd);
        }
        f[s].tagadd = 0;
    }
}
int get(int l, int r, int s, int ll, int rr, node*f) {
    if (r < ll || rr < l) return 0;
    down(l, r, s, f);
    if (ll <= l && r <= rr ) return f[s].mx;
    return max(get(l, (l + r)/2, s+s, ll, rr, f) , get((l + r) / 2 + 1, r, s+s+ 1, ll, rr, f));
}
void update(int s, node*f) {
    f[s].mx = max(f[s+s].mx, f[s+s+1].mx);
}
void add(int l, int r, int s, int ll, int rr, node*f, int v) {
    down(l,r,s,f);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr)  {
        f[s].addtag(v);
        return;
    }
    add(l, (l + r) / 2, s+s,ll,rr, f, v);
    add((l + r) / 2+ 1,r, s+s+1,ll,rr, f, v);
    update(s, f);
}
void ins(int l, int r, int s, int ll, int v, node*f) {
    down(l, r, s, f);
    if (l == r) {
        f[s].mx = max(f[s].mx, v);
        return;
    }
    if ((l + r) / 2>= ll)
        ins(l, (l + r) / 2, s + s, ll, v, f);
    else
        ins((l + r) / 2 + 1, r, s+s+1, ll, v, f);
    update(s,f);
}
int n;
int c[N];
int main() {
    scanf("%d", &n);
    c[++c[0]] = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].t);
        c[++c[0]] = a[i].l;
        c[++c[0]] = a[i].r;
        a[i].t --;
    }
    sort(c +1, c+c[0] + 1);
    int tmp = c[0];
    c[0] = 1;
    for (int i = 2; i <= tmp ; i ++)
        if (c[c[0]] != c[i])
            c[++c[0]] = c[i];
    for (int i = 1; i <= n; i ++) {
        a[i].l = lower_bound(c+1,c+c[0]+1,a[i].l) - c;
        a[i].r = lower_bound(c+1,c+c[0]+1,a[i].r) - c;
    }
    sort(a+1,a+n+1, [](const node1&a,const node1&b) {
        return a.r < b.r;
    });
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int x = get(1, c[0], 1, 1, a[i].l - 1, f[a[i].t ^ 1]);
        add(1, c[0], 1, 1, a[i].l - 1,f[a[i].t ^ 1], 1);
        ans = max(ans, x + 1);
        ins(1, c[0], 1, a[i].r, x + 1, f[a[i].t]);
    }
    printf("%d\n", ans);
    return 0;
}