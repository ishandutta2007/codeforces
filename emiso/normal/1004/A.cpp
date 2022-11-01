#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, d, ans, a[MN];

int main() {
    scanf("%lld %lld", &n, &d);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 1; i < n; i++) {
        ll x = a[i-1] + d;
        if(a[i] - x >= d) ans++;

        x = a[i] - d;
        if(x != a[i-1] + d && x - a[i-1] >= d) ans++;
    }

    printf("%lld\n", 2 + ans);
    return 0;
}