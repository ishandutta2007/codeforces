#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, a[maxn];
ll m;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%lld", &m);
    auto F = [&](int x, int y) {
        int z = x / (y + 1), r = x % (y + 1);
        return 1LL * z * z * (y + 1 - r) + 1LL * (z + 1) * (z + 1) * r;
    };
    auto chk = [&](ll w) {
        ll s = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = 1, r = a[i + 1] - a[i] - 1, p = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (F(a[i + 1] - a[i], mid - 1) - F(a[i + 1] - a[i], mid) >= w) l = (p = mid) + 1;
                else r = mid - 1;
            }
            s += F(a[i + 1] - a[i], p), cnt += p;
        }
        return make_pair(s, cnt);
    };
    ll l = 0, r = 1e18, k;
    while (l <= r) {
        ll mid = (l + r) / 2;
        chk(mid).first <= m ? l = (k = mid) + 1 : r = mid - 1;
    }
    auto res = chk(k + 1);
    printf("%d\n", res.second + (res.first - m + k - 1) / k);
    return 0;
}