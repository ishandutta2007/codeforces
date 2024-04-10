#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], k;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);
    k--;

    if(n % 2 == 0) {
        ans = k % n + 1;
    } else {
        ans = (k + k / (n / 2)) % n + 1;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}