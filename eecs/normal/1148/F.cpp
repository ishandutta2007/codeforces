#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, val[maxn];
ll ans, mask[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %lld", &val[i], &mask[i]);
    }
    ll s = accumulate(val + 1, val + n + 1, 0LL);
    for (int i = 0; i < 62; i++) {
        ll sum = 0;
        for (int j = 1; j <= n; j++) {
            if (mask[j] == (1LL << i)) sum += val[j];
        }
        if (sum && (sum > 0) == (s > 0)) {
            ans |= 1LL << i;
            for (int j = 1; j <= n; j++) {
                if (mask[j] >> i & 1) val[j] *= -1;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (mask[j] >> i & 1) mask[j] ^= 1LL << i;
        }
    }
    printf("%lld\n", ans);
    ll _s = accumulate(val + 1, val + n + 1, 0LL);
    assert((s > 0) != (_s > 0));
    return 0;
}