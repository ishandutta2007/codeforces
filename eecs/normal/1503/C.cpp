#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
pair<int, int> p[maxn];
long long ans, f[maxn], g[maxn], mn[maxn << 2], mn2[maxn << 2], cost;

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd(int k, int l, int r, int p, long long v, long long v2) {
    if (l == r) { mn[k] = v, mn2[k] = v2; return; }
    mid >= p ? upd(ls, l, mid, p, v, v2) : upd(rs, mid + 1, r, p, v, v2);
    mn[k] = min(mn[ls], mn[rs]), mn2[k] = min(mn2[ls], mn2[rs]);
}

long long query2(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn2[k];
    long long mn = 1e18;
    if (mid >= ql) mn = query2(ls, l, mid, ql, qr);
    if (mid < qr) mn = min(mn, query2(rs, mid + 1, r, ql, qr));
    return mn;
}

long long query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn[k];
    long long mn = 1e18;
    if (mid >= ql) mn = query(ls, l, mid, ql, qr);
    if (mid < qr) mn = min(mn, query(rs, mid + 1, r, ql, qr));
    return mn;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
        ans += p[i].second;
    }
    sort(p + 1, p + n + 1);
    memset(mn, 0x3f, sizeof(mn)), memset(mn2, 0x3f, sizeof(mn2));
    memset(f, 0x3f, sizeof(f)), f[n] = 0;
    upd(1, 1, n, n, p[n].first, 0);
    for (int i = n - 1; i; i--) {
        int l = i + 1, r = n, ans = i;
        while (l <= r) {
            if (p[mid].first - p[i].first <= p[i].second) l = (ans = mid) + 1;
            else r = mid - 1;
        }
        f[i] = query2(1, 1, n, i, ans);
        if (ans < n) f[i] = min(f[i], query(1, 1, n, ans + 1, n) - p[i].first - p[i].second);
        upd(1, 1, n, i, f[i] + p[i].first, f[i]);
    }
    printf("%lld\n", ans + f[1]);
    return 0;
}