#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x, y, c, lo, hi;

ll f(ll s) {
    ll ret = s * s + (s+1) * (s+1);

    ll l1, l2, l3, l4;
    l1 = max(0LL, s + x - n);
    l2 = max(0LL, s + y - n);

    l3 = max(0LL, s - x + 1);
    l4 = max(0LL, s - y + 1);

    ret -= l1 * l1;
    ret -= l2 * l2;
    ret -= l3 * l3;
    ret -= l4 * l4;

    ll c1, c2, c3, c4;
    c1 = max(0LL, 1 + s - abs(x - n - 1) - abs(y - n - 1));
    c2 = max(0LL, 1 + s - x - abs(y - n - 1));
    c3 = max(0LL, 1 + s - x - y);
    c4 = max(0LL, 1 + s - abs(x - n - 1) - y);

    ret += c1 * (c1 + 1) / 2;
    ret += c2 * (c2 + 1) / 2;
    ret += c3 * (c3 + 1) / 2;
    ret += c4 * (c4 + 1) / 2;

    //printf("%lld %lld\n", s,  s * s + (s+1) * (s+1));
    //printf("%lld %lld %lld %lld\n", l1, l2, l3, l4);
    //printf("%lld %lld %lld %lld\n", c1, c2, c3, c4);

    return ret;
}

int main(){
    lo = 0, hi = 100000000LL;
    cin >> n >> x >> y >> c;
    while(lo < hi){
        ll mid = (lo+hi)>>1;
        ll qt = f(mid);
        if(qt >= c)hi = mid;
        else lo = mid+1;
        //cout << qt << endl;
    }
    cout << lo << endl;
    return 0;
}