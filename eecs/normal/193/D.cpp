#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, p[maxn], q[maxn];
int mx[maxn << 2], sec[maxn << 2], tag[maxn << 2], cnt[maxn << 2], cnt_sec[maxn << 2];
long long ans;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void maintain(int k) {
    mx[k] = max(mx[ls], mx[rs]);
    cnt[k] = (mx[k] == mx[ls]) * cnt[ls] + (mx[k] == mx[rs]) * cnt[rs];
    sec[k] = max({mx[ls] < mx[k] ? mx[ls] : INT_MIN, sec[ls], mx[rs] < mx[k] ? mx[rs] : INT_MIN, sec[rs]});
    cnt_sec[k] = (sec[k] == mx[ls]) * cnt[ls] + (sec[k] == sec[ls]) * cnt_sec[ls];
    cnt_sec[k] += (sec[k] == mx[rs]) * cnt[rs] + (sec[k] == sec[rs]) * cnt_sec[rs];
}

void apply(int k, int v) {
    mx[k] += v, sec[k] += v, tag[k] += v;
}
void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void upd(int k, int l, int r, int p) {
    if (l == r) { mx[k] = p, cnt[k] = 1; return; }
    if (tag[k]) pushdown(k);
    mid >= p ? upd(ls, l, mid, p) : upd(rs, mid + 1, r, p);
    maintain(k);
}

void add(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) { apply(k, 1); return; }
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr);
    if (mid < qr) add(rs, mid + 1, r, ql, qr);
    maintain(k);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), q[p[i]] = i;
    }
    memset(mx, -0x3f, sizeof(mx));
    memset(sec, -0x3f, sizeof(sec));
    for (int i = 1; i <= n; i++) {
        upd(1, 1, n, i);
        if (q[i] > 1 && p[q[i] - 1] < i) add(1, 1, n, 1, p[q[i] - 1]);
        if (q[i] < n && p[q[i] + 1] < i) add(1, 1, n, 1, p[q[i] + 1]);
        if (mx[1] >= i - 1) ans += cnt[1];
        if (sec[1] >= i - 1) ans += cnt_sec[1];
    }
    printf("%lld\n", ans - n);
    return 0;
}