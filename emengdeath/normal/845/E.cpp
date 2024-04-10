#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 501;
struct node{
    int sum;
    int v, l, r;
    int son[2];
    void clear(){
        sum = v = son[0] = son[1] = 0;
        l = 1e9;
        r = -1e9;
    }
}f[N * 100];
struct node1{
    int l, r, x;
    bool sig;
}d[N * 10];
int a[N][2], tot;
int n, m, k;
void update(int l, int r,int x) {
    if (f[x].v) {
        f[x].sum = r - l + 1;
        f[x].r = -1e9, f[x].l = 1e9;
    }else {
        f[x].sum = f[f[x].son[0]].sum + f[f[x].son[1]].sum;
        f[x].r = -1e9, f[x].l = 1e9;
        if (f[x].son[0]) {
            f[x].l = min(f[x].l, f[f[x].son[0]].l);
            f[x].r = max(f[x].r, f[f[x].son[0]].r);
        } else {
            f[x].l = min(f[x].l, l);
            f[x].r = max(f[x].r, (l + r) / 2);
        }
        if (f[x].son[1]) {
            f[x].l = min(f[x].l, f[f[x].son[1]].l);
            f[x].r = max(f[x].r, f[f[x].son[1]].r);
        } else {
            f[x].l = min(f[x].l, (l + r) / 2 + 1);
            f[x].r = max(f[x].r, r);
        }
    }
}
void ins(int l, int r, int s ,int ll, int rr, int v) {
    if (r < ll || rr < l ) return;
    if (ll <= l && r <= rr ) {
        f[s].v += v;
        update(l, r, s);
        return;
    }
    if (!f[s].son[0]) {
        f[s].son[0] = ++tot;
        f[tot].clear();
        update(l, (l + r) / 2,tot);
    }

    if (!f[s].son[1]) {
        f[s].son[1] = ++tot;
        f[tot].clear();
        update((l + r) / 2 + 1, r,tot);
    }
    ins(l, (l + r) / 2, f[s].son[0], ll, rr, v);
    ins((l + r) / 2+ 1, r, f[s].son[1], ll, rr, v);
    update(l ,r , s);
}
bool check(int x) {
    int cnt = 0;
    tot = 1;
    f[1].clear();
    update(1, n, 1);
    for (int i = 1; i <= k; i ++) {
        d[++cnt] = {a[i][0] - x, a[i][0] + x, max(a[i][1] - x, 1), 0};
        d[++cnt] = {a[i][0] - x, a[i][0] + x, min(a[i][1] + x+ 1, m + 1), 1};
    }
    sort(d + 1,  d + cnt + 1, [](node1 a, node1 b){
        return a.x < b.x;
    });
    int l = 1;
    int mnn = n;
    int mxn = 1;
    int mnm = m;
    int mxm = 1;
    while (l <= cnt) {
        int r = l;
        while (r < cnt && d[r + 1].x == d[r].x) r ++;
        if (f[1].sum != n && d[l].x - 1 > 0) {
            mxm = d[l].x - 1;
            mnn = min(f[1].l, mnn);
            mxn = max(f[1].r, mxn);
        }
        while (l <= r) {
            ins(1, n, 1, d[l].l, d[l].r, 1 - d[l].sig * 2);
            l ++;
        }
        if (f[1].sum != n && d[r].x <= m) {
            mnm = min(d[r].x, mnm);
            mnn = min(f[1].l, mnn);
            mxn = max(f[1].r, mxn);
        }
    }
    if (d[cnt].x <= m)
        mxm = m;
    return max(x, max((mxn - mnn + 1) / 2, (mxm - mnm + 1) / 2)) == x;
}
int main() {
    scanf("%d %d %d",&n,&m,&k);
    if (!k) {
        printf("%d\n", max(n / 2, m / 2));
        return 0;
    }
    for (int i = 1; i <= k; i ++)
        scanf("%d %d", &a[i][0], &a[i][1]);
    int l = 0, r = 1e9, mid, s = 1e9;
    check(0);
    while (l <= r)
        if (check(mid = (l+ r) / 2)) s = min(s, mid), r = mid - 1;
        else
            l = mid + 1;
    printf("%d\n", s);
    return 0;
}