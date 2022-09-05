#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010, V = 100000;
int n, a[maxn];
ll cnt[maxn], s1[maxn], s2[maxn];
map<int, int> mp, mp2;

ll get(ll n) {
    if (n & 1) return n * ((n + 1) / 2);
    return n / 2 * (n + 1);
}

// (ai + b) / c
ll F(ll a, ll b, ll c, ll n) {
    if (!a || !n) return b / c * (n + 1);
    if (a >= c || b >= c) return a / c * get(n) + b / c * (n + 1) + F(a % c, b % c, c, n);
    ll m = (a * n + b) / c;
    return n * m - F(c, c - b - 1, a, m - 1);
}

// ax + by <= c
ll S(ll a, ll b, ll c) {
    if (c < 0) return 0;
    return c / a + 1 + F(a, c % a, b, c / a);
}

// ax + by <= c (x < la, y < lb)
ll solve(ll a, ll la, ll b, ll lb, ll c) {
    return S(a, b, c) - S(a, b, c - a * la) - S(a, b, c - b * lb) + S(a, b, c - a * la - b * lb);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        mp2.clear();
        for (auto p : mp) mp2[__gcd(a[i], p.first)] = p.second;
        swap(mp, mp2), mp[a[i]] = i;
        int lst = 0;
        for (auto p : mp) cnt[p.first] += p.second - lst, lst = p.second;
    }
    for (int i = 1; i <= V; i++) {
        s1[i] = s1[i - 1] + cnt[i];
        s2[i] = s2[i - 1] + cnt[i] * i;
    }
    auto chk = [&](ll x) {
        ll ans = 0;
        auto upd = [&](int l, int r) {
            if (l == r || !cnt[r]) return;
            ans += solve(l, cnt[l], r, cnt[r], x - (s2[r - 1] - s2[l]) - l - r);
        };
        for (int l = 1, r = 1; l <= V; l++) if (cnt[l]) {
            ll t = min(cnt[l], x / l);
            ans += cnt[l] * t - t * (t - 1) / 2;
            r = max(r, l + 1), ans += cnt[l] * (s1[r - 1] - s1[l]);
            for (; r <= V && s2[r] - s2[l] <= x; r++) upd(l, r);
            upd(l, r);
        }
        return ans;
    };
    ll len = 1LL * n * (n + 1) / 2;
    len = len * (len + 1) / 2;
    ll l = 1, r = s2[V], ans;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        chk(mid) >= (len + 1) / 2 ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}