#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, ans, a[MN], f[110];

int main() {
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i] % k]++;
    }

    ans = f[0] / 2 * 2;
    if(k % 2 == 0) ans += f[k/2] / 2 * 2;

    for(int i = 1, j = k-1; i < j; i++, j--) {
        ans += min(f[i], f[j]) * 2;
    }

    printf("%lld\n", ans);
    return 0;
}