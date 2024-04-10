#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, a[maxn], cnt[maxn], mu[maxn], coef[maxn];
ll ans;
vector<int> d[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (++cnt[a[i]] > 1) ans = max(ans, 1LL * a[i]);
    }
    int U = 100000;
    for (int i = mu[1] = 1; i <= U; i++) {
        for (int j = i; j <= U; j += i) d[j].push_back(i);
        for (int j = i + i; j <= U; j += i) mu[j] -= mu[i];
    }
    auto ins = [&](int x, int type = 1) {
        for (int i : d[x]) coef[i] += mu[i] * type;
    };
    auto test = [&](int x) {
        int s = 0;
        for (int i : d[x]) s += coef[i];
        return s;
    };
    for (int g = 1; g <= U; g++) {
        int m = U / g;
        auto chk = [&](ll lim) {
            fill(coef + 1, coef + m + 1, 0);
            int num = 0;
            for (int i = 1, j = m; i <= m; i++) {
                for (; 1LL * i * j >= lim; j--) {
                    if (cnt[j * g]) ins(j), num++;
                }
                if (cnt[i * g] && test(i)) return 1;
            }
            return 0;
        };
        ll l = 2, r = 1LL * (m - 1) * m, mx = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;
            chk(mid) ? l = (mx = mid) + 1 : r = mid - 1;
        }
        ans = max(ans, mx * g);
    }
    printf("%lld\n", ans);
    return 0;
}