#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    k = (k - n%k + k) % k;
    printf("%lld\n", (k + n - 1) / n + 1);
    if(--t) goto st;
    return 0;
}