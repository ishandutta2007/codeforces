#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;

int main() {
    scanf("%lld %lld", &n, &k);
    for (ll i = 0; ; i++) {
        if (i * (i + 1) / 2 - (n - i) == k) {
            printf("%lld\n", n - i); break;
        }
    }
    return 0;
}