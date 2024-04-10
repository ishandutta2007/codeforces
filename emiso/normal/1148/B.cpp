#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ta, tb, k, ans, a[MN], b[MN], last, ra[MN];

int main() {
    scanf("%lld %lld %lld %lld %lld", &n, &m, &ta, &tb, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ra[i] = a[i] + ta;
    }
    ra[n] = 1000100000;
    sort(ra, ra + n);

    for(int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }

    for(int i = 0; i <= n; i++) {
        if(i > k) break;
        int idx = lower_bound(b, b + m, ra[i]) - b;
        idx += (k - i);
        if(idx < m) {
            if(ans >= 0 && b[idx] + tb > ans) ans = b[idx] + tb;
        } else ans = -1;
    }

    printf("%lld\n", ans);
    return 0;
}