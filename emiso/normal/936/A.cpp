#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll k, d, t, q, nd;
double ans;

int main() {
    scanf("%lld %lld %lld", &k, &d, &t);
    nd = d;
    if(nd < k) {
        if(k % nd == 0) nd = k;
        else nd = k - (k % nd) + nd;
    }

    t *= 2;
    q = 2*k + (nd - k);

    ans = (t / q) * nd;
    t %= q;

    if(t <= 2*k) ans += t / 2.0;
    else {
        ans += k;
        t -= 2*k;
        ans += t;
    }

    printf("%.12f\n", ans);
    return 0;
}