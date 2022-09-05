#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, m, l[maxn], r[maxn], mark[maxn];
ll ans;
vector<array<int, 3>> V[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
int cnt[maxn << 2], mn[maxn << 2], tag[maxn << 2];
ll sum[maxn << 2];

void maintain(int k) {
    cnt[k] = sum[k] = 0, mn[k] = min(mn[ls], mn[rs]);
    if (mn[k] == mn[ls]) cnt[k] += cnt[ls], sum[k] += sum[ls];
    if (mn[k] == mn[rs]) cnt[k] += cnt[rs], sum[k] += sum[rs];
}

void apply(int k, int v) {
    mn[k] += v, tag[k] += v;
}

void pushdown(int k) {
    apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void build(int k, int l, int r, int p) {
    mn[k] = tag[k] = 0;
    if (l == r) {
        if (l % 2 == p) cnt[k] = 1, sum[k] = l - 1;
        else cnt[k] = sum[k] = 0;
        return;
    }
    build(ls, l, mid, p), build(rs, mid + 1, r, p), maintain(k);
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) return apply(k, v);
    if (tag[k]) pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

ll q1(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn[k] ? 0 : sum[k];
    if (tag[k]) pushdown(k);
    ll s = 0;
    if (mid >= ql) s = q1(ls, l, mid, ql, qr);
    if (mid < qr) s += q1(rs, mid + 1, r, ql, qr);
    return s;
}

int q2(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn[k] ? 0 : cnt[k];
    if (tag[k]) pushdown(k);
    int s = 0;
    if (mid >= ql) s = q2(ls, l, mid, ql, qr);
    if (mid < qr) s += q2(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        mark[l[i]]++, mark[r[i] + 1]--;
    }
    for (int p : {0, 1}) for (int q : {0, 1}) {
        build(1, 1, m, p);
        for (int i = 1; i <= m; i++) {
            V[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            if (l[i] > 1 && l[i] % 2 != q) {
                V[l[i]].push_back({1, l[i] - 1, 1});
                V[r[i] + 1].push_back({1, l[i] - 1, -1});
            }
            if (r[i] < m && p != r[i] % 2) {
                V[r[i] + 1].push_back({l[i], r[i], 1});
            }
            if (p != q) {
                V[l[i]].push_back({l[i], r[i], 1});
                V[r[i] + 1].push_back({l[i], r[i], -1});
            }
            if (l[i] > 1 && l[i] % 2 != r[i] % 2) {
                V[r[i] + 1].push_back({1, l[i] - 1, 1});
            }
        }
        for (int i = 1; i <= m; i++) {
            for (auto &p : V[i]) add(1, 1, m, p[0], p[1], p[2]);
            if (i % 2 == q) ans += 1LL * i * q2(1, 1, m, 1, i) - q1(1, 1, m, 1, i);
        }
    }
    for (int i = 1; i <= m; i++) {
        mark[i] += mark[i - 1];
    }
    for (int i = 1; i <= m; i++) if (!mark[i]) {
        int j = i;
        while (j <= m && !mark[j]) j++;
        for (int k = i; k < j; k++) {
            ans -= 1LL * (k - i + 1) * (k - i + 2) / 2;
        }
        i = j;
    }
    printf("%lld\n", ans);
    return 0;
}