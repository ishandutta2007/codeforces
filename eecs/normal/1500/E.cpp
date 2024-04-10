#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, q, type[maxn];
ll s[maxn], a[maxn];
struct node { int cnt; ll sum, psum; } t[maxn << 3], null;

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void modify(int k, int l, int r, int p, int c, ll v) {
    if (l == r) { t[k].cnt += c, t[k].sum += v, t[k].psum += v; return; }
    mid >= p ? modify(ls, l, mid, p, c, v) : modify(rs, mid + 1, r, p, c, v);
    t[k].cnt = t[ls].cnt + t[rs].cnt, t[k].sum = t[ls].sum + t[rs].sum;
    t[k].psum = t[ls].psum + t[rs].psum + t[ls].cnt * t[rs].sum;
}

ll pre_sum(int k, int l, int r, int p) {
    if (l == r) return t[k].sum;
    if (t[ls].cnt >= p) return pre_sum(ls, l, mid, p);
    return t[ls].sum + pre_sum(rs, mid + 1, r, p - t[ls].cnt);
}

ll calc_pre(int k, int l, int r, int p) {
    if (l == r) return t[k].sum;
    if (t[ls].cnt >= p) return calc_pre(ls, l, mid, p);
    return t[ls].sum * (p + 1) - t[ls].psum + calc_pre(rs, mid + 1, r, p - t[ls].cnt);
}

ll suf_sum(int k, int l, int r, int p) {
    if (!p) return 0;
    if (l == r) return t[k].sum;
    if (t[rs].cnt >= p) return suf_sum(rs, mid + 1, r, p);
    return t[rs].sum + suf_sum(ls, l, mid, p - t[rs].cnt);
}

ll calc_suf(int k, int l, int r, int p) {
    if (!p) return 0;
    if (l == r) return t[k].sum;
    if (t[rs].cnt >= p) return calc_suf(rs, mid + 1, r, p);
    return (p - t[rs].cnt) * t[rs].sum + t[rs].psum + calc_suf(ls, l, mid, p - t[rs].cnt);
}

int main() {
    scanf("%d %d", &n, &q);
    vector<ll> V;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]), V.push_back(s[i]);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d %lld", &type[i], &a[i]), V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        s[i] = lower_bound(V.begin(), V.end(), s[i]) - V.begin() + 1;
        modify(1, 1, V.size(), s[i], 1, V[s[i] - 1]);
    }
    auto solve = [&]() {
        int l = 0, r = (n - 1) >> 1, pos = -1;
        while (l <= r) {
            pre_sum(1, 1, V.size(), mid + 1) > suf_sum(1, 1, V.size(), mid) ?
                l = (pos = mid) + 1 : r = mid - 1;
        }
        ll ans = (calc_pre(1, 1, V.size(), pos + 1) - calc_suf(1, 1, V.size(), pos)) << 1;
        if (pos << 1 == n - 1) ans -= pre_sum(1, 1, V.size(), pos + 1) - suf_sum(1, 1, V.size(), pos);
        return t[1].sum - ans;
    };
    printf("%lld\n", solve());
    for (int i = 1; i <= q; i++) {
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
        if (type[i] == 1) n++, modify(1, 1, V.size(), a[i], 1, V[a[i] - 1]);
        else n--, modify(1, 1, V.size(), a[i], -1, -V[a[i] - 1]);
        printf("%lld\n", solve());
    }
    return 0;
}