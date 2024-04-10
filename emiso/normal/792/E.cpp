#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, a[505], ans = LLONG_MAX;
vector<ll> possib;

int main() {
    scanf("%lld", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(ll x = 1, la; x <= a[0]; x = la + 1) {
        la = a[0] / (a[0] / x);
        possib.push_back(a[0] / x);
    }

    for(ll x = 1; x * x <= a[0]; x++) {
        if(a[0] % x == 0) {
            possib.push_back(x - 1);
            if(x * x < a[0])
                possib.push_back(a[0] / x - 1);
        }
    }

    for(ll x : possib) {
        ll tmp = 0, f = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] % (x + 1) == 0)  tmp += a[i] / (x + 1);
            else if(x && x <= a[i] && a[i] / (a[i] / x) == x)  tmp += (a[i] / (x + 1)) + 1;
            else f++;
        }
        if(f) continue;

        ans = min(ans, tmp);
    }

    printf("%lld\n", ans);
    return 0;
}