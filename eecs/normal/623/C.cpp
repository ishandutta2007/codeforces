#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll pre_mn[maxn], pre_mx[maxn], pre_sqr[maxn], suf_mn[maxn], suf_mx[maxn], suf_sqr[maxn];
pair<ll, ll> p[maxn];

inline ll sqr(ll x) { return x * x; }

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + n + 1);
    ll mn1 = sqr(p[n].first - p[1].first);
    pre_mn[0] = LLONG_MAX, pre_mx[0] = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        pre_mn[i] = min(pre_mn[i - 1], p[i].second);
        pre_mx[i] = max(pre_mx[i - 1], p[i].second);
        pre_sqr[i] = max(pre_sqr[i - 1], sqr(p[i].second));
    }
    suf_mn[n + 1] = LLONG_MAX, suf_mx[n + 1] = LLONG_MIN;
    for (int i = n; i; i--) {
        suf_mn[i] = min(suf_mn[i + 1], p[i].second);
        suf_mx[i] = max(suf_mx[i + 1], p[i].second);
        suf_sqr[i] = max(suf_sqr[i + 1], sqr(p[i].second));
    }
    ll mn2 = sqr(pre_mx[n] - pre_mn[n]);
    auto chk = [&](ll x) {
        int L = n, R = 1;
        for (int i = 1; i <= n; i++) if (sqr(p[i].first) <= x) {
            L = min(L, i), R = i;
        }
        if (L > R) return 0;
        for (int i = L; i <= R; i++) {
            int l = 1, r = i, j = i + 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sqr(p[i].first - p[mid].first) <= x && abs(p[mid].first) <= abs(p[i].first)) r = (j = mid) - 1;
                else l = mid + 1;
            }
            if (i == n && j == 1 || j > i) continue;
            ll foo = min(pre_mn[j - 1], suf_mn[i + 1]);
            ll bar = max(pre_mx[j - 1], suf_mx[i + 1]);
            if (sqr(bar - foo) <= x && max(sqr(p[i].first), sqr(p[j].first)) +
                max(pre_sqr[j - 1], suf_sqr[i + 1]) <= x) return 1;   
        }
        for (int i = R; i >= L; i--) {
            int l = i, r = n, j = i + 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sqr(p[i].first - p[mid].first) <= x && abs(p[mid].first) <= abs(p[i].first)) l = (j = mid) + 1;
                else r = mid - 1;
            }
            if (i == 1 && j == n || i > j) continue;
            ll foo = min(pre_mn[i - 1], suf_mn[j + 1]);
            ll bar = max(pre_mx[i - 1], suf_mx[j + 1]);
            if (sqr(bar - foo) <= x && max(sqr(p[i].first), sqr(p[j].first)) +
                max(pre_sqr[i - 1], suf_sqr[j + 1]) <= x) return 1;   
        }
        return 0;
    };
    ll l = 0, r = 1e18, ans = 1e18;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%lld\n", min({ans, mn1, mn2}));
    return 0;
}