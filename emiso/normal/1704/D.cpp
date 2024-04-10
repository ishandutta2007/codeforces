#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, m, ans, a[MN];
vector<ll> v[MN];

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    ll mx = LLONG_MIN, mxi = -1, mn = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        v[i].resize(m);
        a[i] = 0;
        for (int j = 0; j < m; j++) {
            scanf("%lld", &v[i][j]);
            a[i] += j * v[i][j];
        }
        mn = min(mn, a[i]);
        if (mx < a[i]) {
            mx = a[i];
            mxi = i;
        }
    }

    printf("%lld %lld\n", mxi + 1, mx - mn);
    if(--t) goto st;
    return 0;
}