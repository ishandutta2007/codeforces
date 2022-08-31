#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q;
ll st;
ll a[110], b[100010];
ll c[100010], c2[100010];
inline void add(int x, ll k) {
    for (; x <= m; x += x & -x) c[x] += k;
}
inline void add2(int x, ll k) {
    for (; x <= m; x += x & -x) c2[x] += k;
}
inline ll query2(int x) {
    ll ans = 0;
    for (; x; x -= x & -x) ans += c2[x];
    return ans;
}
inline pair < int, ll > query(ll k) {
    int ans = 0;
    ll sum = 0;
    for (int i = 17; i --> 0; ) if ((1 << i | ans) <= m) {
        if (sum + c[1 << i | ans] <= k) sum += c[ans |= 1 << i];
    }
    return {ans, sum};
}
ll ans = 0;
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < m; i++) scanf("%lld", b + i), ans += b[i] - b[0];
    st = a[0] + b[0];
    for (int i = n; i --> 1; ) a[i] = a[i] - a[i - 1];
    for (int i = m; i --> 1; ) b[i] = b[i] - b[i - 1];
    n--, m--;
    a[0] = b[0] = 0;
    for (int i = 1; i <= m; i++) add(i, b[i] - b[i - 1]), add2(i, (b[i] - b[i - 1]) * i);
    for (int i = 1; i <= q; i++) {
        int opt, k, d;
        scanf("%d%d%d", &opt, &k, &d);
        if (opt == 1) {
            if (k == n + 1) k--, st += d;
            for (int i = n - k + 1; i <= n; i++) a[i] += d;
        }
        else {
            if (k == m + 1) k--, st += d;
            ans += 1ll * k * (k + 1) / 2 * d;
            add(m - k + 1, d);
            add2(m - k + 1, 1ll * d * (m - k + 1));
        }
        ll cans = ans + st * (n + m + 1);
        for (int i = 1; i <= n; i++) {
            auto cur = query(a[i]);
            cans += cur.second * (cur.first + 1) - query2(cur.first);
            cans += (m - cur.first + n - i + 1) * a[i];
        }
        printf("%lld\n", cans);
    }
}