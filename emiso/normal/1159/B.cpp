#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, a[1000100], ans = INT_MAX;

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i + 1 < n; i++) {
        if(i) ans = min(ans, min(a[0], a[i]) / i);
        ans = min(ans, min(a[n-1], a[i]) / (n-1-i));
    }

    printf("%lld\n", ans);
    return 0;
}