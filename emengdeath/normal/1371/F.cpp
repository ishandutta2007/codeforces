#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
struct node{
    bool lc, rc;
    int mxv[2];
    int lv[2], rv[2];
    bool tag;
    bool all[2];
}f[N * 4],v;
int n, m;
char S[N];
void merge(node&a, node b, node c) {
    a.lc = b.lc, a.rc = c.rc;
    for (int i = 0; i < 2; i ++) {
        a.mxv[i] = max(b.mxv[i], c.mxv[i]);
        if (b.all[i] && c.all[i] && (b.rc == c.lc || ((b.rc^i) && !(c.lc^i)))) {
            a.all[i] = 1;
            a.mxv[i] = a.lv[i] = a.rv[i] = b.lv[i] + c.lv[i];
        } else {
            a.all[i] = 0;
            if (b.all[i] && (c.lc == b.rc || ((b.rc^i) && !(c.lc^i))))
                a.lv[i] = b.lv[i] + c.lv[i];
            else
                a.lv[i] = b.lv[i];
            if (c.all[i] && (c.lc == b.rc || ((b.rc ^ i) && !(c.lc ^ i))))
                a.rv[i] = c.rv[i] + b.rv[i];
            else
                a.rv[i] = c.rv[i];
            if (b.rc == c.lc|| ((b.rc^i) && !(c.lc^ i)))
                a.mxv[i] = max(a.mxv[i], b.rv[i] + c.lv[i]);
            a.mxv[i] = max(a.mxv[i], max(a.lv[i], a.rv[i]));
        }
    }
}
void build(int l, int r, int s) {
    if (l == r) {
        for (int i = 0; i < 2; i++) {
            f[s].lv[i] = f[s].rv[i] = f[s].mxv[i] = 1;
            f[s].all[i] = 1;
        }
        f[s].lc = f[s].rc = (S[l] == '>');
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    merge(f[s], f[s+s],f[s+s+1]);
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].tag = 0;
        if (l != r)
            f[s+s].tag ^= 1, f[s + s + 1].tag ^= 1;
        f[s].lc ^=1, f[s].rc ^= 1;
        swap(f[s].mxv[0], f[s].mxv[1]);
        swap(f[s].lv[0], f[s].lv[1]);
        swap(f[s].rv[0], f[s].rv[1]);
        swap(f[s].all[0], f[s].all[1]);
    }
}
void change(int l, int r ,int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag ^= 1;
        down(l, r, s);
        return;
    }
    change(l, (l + r) / 2, s + s, ll, rr);
    change((l + r) /2 + 1, r, s + s+1 , ll, rr);
    merge(f[s], f[s+s],f[s+s+1]);
}

void get(int l, int r ,int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        if (ll == l) v = f[s];
        else
            merge(v, v, f[s]);
        return;
    }
    get(l, (l + r) / 2, s + s, ll, rr);
    get((l + r) /2 + 1, r, s + s+1 , ll, rr);
}
int main(){
    scanf("%d %d", &n, &m);
    scanf("%s", S + 1);
    build(1, n, 1);
    while (m --) {
        int l, r;
        scanf("%d %d", &l, &r);
        change(1, n, 1, l, r);
        get(1, n, 1, l, r);
        printf("%d\n", v.mxv[0]);
    }
    return 0;
}