#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;

int main() {
    scanf("%lld %lld", &n, &k);
    // x <= n && k - x <= n
    ll lb = max(1LL, k - n);
    ll rb = min(n, k - 1);
    printf("%lld\n", max(0LL, (rb - lb + 1) / 2));
    return 0;
}