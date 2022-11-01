#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ll sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    for(int ch = 0; ch < 2; ch++) {
        ll d = 0;
        for(int i = ch; i < n; i += 2)
            d += a[i] - 1;
        if(2LL * d <= sum) {
            for(int i = 0; i < n; i++) {
                if(i % 2 == ch) printf("1 ");
                else printf("%d ", a[i]);
            }
            puts("");
            break;
        }
    }

    if(--t) goto st;
    return 0;
}