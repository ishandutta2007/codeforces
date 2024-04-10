#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T;
ll n, k;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &n, &k);
        ll cur = 1, ans = 0;
        while (cur < k) cur += cur, ans++;
        if (cur < n) ans += (n - cur + k - 1) / k;
        printf("%lld\n", ans);
    }
    return 0;
}