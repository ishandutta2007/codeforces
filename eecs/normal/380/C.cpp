#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, q;
char s[maxn];
struct node { int cr, cl; } t[maxn << 2];

node merge(node A, node B) {
    node C;
    // ))) ((( ))) (((
    C.cr = A.cr, C.cl = B.cl;
    if (A.cl >= B.cr) C.cl += A.cl - B.cr;
    else C.cr += B.cr - A.cl;
    return C;
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) {
        if (s[l] == '(') t[k].cl++;
        else t[k].cr++;
        return;
    }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k] = merge(t[ls], t[rs]);
}

node query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
}

int main() {
    scanf("%s %d", s + 1, &q), n = strlen(s + 1);
    build(1, 1, n);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        auto p = query(1, 1, n, l, r);
        printf("%d\n", r - l + 1 - p.cl - p.cr);
    }
    return 0;
}