#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, m, q, l[maxn], r[maxn], x[maxn], a[maxn];
ll T, sl[maxn], sr[maxn], sa[maxn], tmp[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    sort(l + 1, l + n + 1), sort(r + 1, r + n + 1);
    for (int i = 1; i <= n; i++) {
        sl[i] = sl[i - 1] + l[i];
        sr[i] = sr[i - 1] + r[i];
    }
    scanf("%d", &q);
    memset(x, -1, sizeof(x));
    while (q--) {
        int p; scanf("%d", &p);
        scanf("%d", &x[m - p + 1]);
    }
    scanf("%lld", &T);
    auto chk = [&](int cnt, int val) {
        bool info = 0;
        ll rem = T;
        for (int i = 1; i <= m; i++) {
            a[i] = max(a[i - 1], x[i]), rem -= a[i];
            if (i >= m - cnt + 1 && ~x[i]) info = 1;
        }
        if (info) {
            if (a[m] < val) return 0;
            for (int i = m - cnt + 1; i <= m; i++) {
                if (~x[i] && a[i] ^ a[m]) return 0;
                rem -= a[m] - a[i], a[i] = a[m];
            }
        } else {
            for (int i = m - cnt + 1; i <= m; i++) {
                if (a[i] < val) rem -= val - a[i], a[i] = val;
            }
            copy(a + 1, a + m + 1, tmp + 1);
        }
        if (rem < 0) return 0;
        auto upd = [&]() {
            for (int i = 1, j = 0; i <= m && rem; i++) {
                if (~x[i] || i >= m - cnt + 1) {
                    ll foo = a[i] - a[j + 1], bar = foo * (i - j - 1);
                    if (bar > rem) {
                        foo = rem / (i - j - 1), bar = foo * (i - j - 1);
                        for (int k = i - rem + bar; k < i; k++) a[k]++;
                        rem = 0;
                    } else {
                        rem -= bar;
                    }
                    for (int k = j + 1; k < i; k++) a[k] += foo;
                    j = i;
                }
            }
        };
        ll o = rem;
        upd();
        if (info) {
            if (rem) return 0;
        } else if (rem) {
            copy(tmp + 1, tmp + m + 1, a + 1);
            int pos = cnt;
            while (pos < m && !~x[m - pos]) pos++;
            ll inc = (rem - 1) / pos + 1;
            if (a[m] + inc > n) return 0;
            for (int i = m - cnt + 1; i <= m; i++) a[i] += inc;
            if ((rem = o - inc * cnt) < 0) return 0;
            upd();
            if (rem) return 0;
        }
        for (int i = 1; i <= m; i++) {
            sa[i] = sa[i - 1] + a[i];
        }
        for (int i = 0, j = m; i <= n; i++) {
            while (j && a[j] >= n - i) j--;
            if (sl[i] + sa[j] + 1LL * (n - i) * (m - j) < sl[n]) return 0;
            if (sr[i] + sa[j] + 1LL * (n - i) * (m - j) < T) return 0;
        }
        return 1;
    };
    int l = 1, r = m, ans1 = -1, ans2;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid, 0) ? l = (ans1 = mid) + 1 : r = mid - 1;
    }
    if (!~ans1) puts("-1 -1"), exit(0);
    printf("%d ", ans1), l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(ans1, mid) ? l = (ans2 = mid) + 1 : r = mid - 1;
    }
    printf("%d\n", ans2);
    return 0;
}