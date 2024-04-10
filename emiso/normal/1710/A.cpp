#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, m, k, ans, a[MN];
//char s[MN]; string str;

void solve(ll n, ll m) {
    priority_queue<ll> pq;
    ll cur = 0, g3 = 0;

    for (int i = 0; i < k; i++) {
        if (a[i] >= 2 * n) {
            ll tmp = (a[i] / n);
            cur += tmp;
            assert(tmp >= 2);
            g3 += tmp - 2;
        }
    }

    if (cur >= m) {
        if (m % 2 == 0) ans = 1;
        else if (g3) ans = 1;
    }
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld %lld", &n, &m, &k);

    for(int i = 0; i < k; i++) {
        scanf("%lld", &a[i]);
    }

    solve(n, m);
    solve(m, n);

    puts(ans ? "Yes" : "No");
    if(--t) goto st;
    return 0;
}