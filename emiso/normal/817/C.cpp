#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, s;

ll sum(ll x) {
    ll ret = 0;
    while(x) {
        ret += (x % 10);
        x /= 10;
    }
    return ret;
}

int main() {
    scanf("%lld %lld", &n, &s);

    ll l = 1, r = n + 1;
    while(l < r) {
        ll m = (l + r) / 2;
        if(m - sum(m) >= s)
            r = m;
        else l = m + 1;
    }

    printf("%lld\n", n - r + 1);
    return 0;
}