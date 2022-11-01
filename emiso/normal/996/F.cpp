#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, r, sum, a[1000100], x;
int p;

int main() {
    scanf("%lld %lld", &n, &r);
    n = (1LL << n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    printf("%.9f\n", 1.0 * sum / n);
    for(int i = 0; i < r; i++) {
        scanf("%d %lld", &p, &x);
        sum -= a[p];
        a[p] = x;
        sum += a[p];
        printf("%.9f\n", 1.0 * sum / n);
    }

    return 0;
}