#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    ll maxi = LLONG_MIN;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        maxi = max(maxi, a[i]);
    }

    k--;
    ll nmaxi = LLONG_MIN;
    for(int i = 0; i < n; i++) {
        a[i] = maxi - a[i];
        nmaxi = max(nmaxi, a[i]);
    }

    k %= 2;
    if(k) {
        for(int i = 0; i < n; i++) {
            a[i] = nmaxi - a[i];
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    puts("");
    if(--t) goto st;
    return 0;
}