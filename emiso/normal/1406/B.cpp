#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    int zero = 0;
    vector<ll> pos, neg;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] == 0) zero++;
        if(a[i] < 0) neg.push_back(a[i]);
        if(a[i] > 0) pos.push_back(a[i]);
    }

    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());

    ans = LLONG_MIN;
    if(zero) ans = 0;
    if(pos.size() >= 5) ans = max(ans, pos[0] * pos[1] * pos[2] * pos[3] * pos[4]);
    if(pos.size() >= 4 && neg.size() >= 1) ans = max(ans, pos.end()[-1] * pos.end()[-2] * pos.end()[-3] * pos.end()[-4] * neg.back());
    if(pos.size() >= 3 && neg.size() >= 2) ans = max(ans, pos[0] * pos[1] * pos[2] * neg[0] * neg[1]);
    if(pos.size() >= 2 && neg.size() >= 3) ans = max(ans, pos.end()[-1] * pos.end()[-2] * neg.end()[-1] * neg.end()[-2] * neg.end()[-3]);
    if(pos.size() >= 1 && neg.size() >= 4) ans = max(ans, pos[0] * neg[0] * neg[1] * neg[2] * neg[3]);
    if(neg.size() >= 5) ans = max(ans, neg.end()[-1] * neg.end()[-2] * neg.end()[-3] * neg.end()[-4] * neg.end()[-5]);

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}