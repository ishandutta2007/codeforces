#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    ans = INT_MAX;
    for(int f = 1; f <= 100; f++) {
        ll tmp = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] != f) {
                tmp++;
                i += k - 1;
            }
        }
        ans = min(ans, tmp);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}