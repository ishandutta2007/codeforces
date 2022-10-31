#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], sum;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    ans = n-1;
    for(int i = 1; i <= n; i++) {
        if(sum % i) continue;
        ll target = sum / i, flag = 1;
        for(int j = 0, cur = 0; flag && j < n; j++) {
            cur += a[j];
            if(cur > target) flag = 0;
            if(cur == target) cur = 0;
        }
        if(flag) ans = n - i;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}