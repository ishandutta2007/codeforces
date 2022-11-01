#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], tot, desired;

int main() {
    scanf("%lld", &n);
    desired = 4*n + (n/2);
    if(n % 2) desired++;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        tot += a[i];
    }
    sort(a, a + n);

    for(int i = 0; i < n && tot < desired; i++) {
        tot -= a[i];
        tot += 5;
        ans++;
    }

    printf("%lld\n", ans);
    return 0;
}