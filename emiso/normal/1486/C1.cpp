#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n;

ll query(ll l, ll r) {
    assert(l < r);
    printf("? %lld %lld\n", l, r); fflush(stdout);
    ll x;
    scanf("%lld", &x);
    return x;
}

int main() {
    scanf("%lld", &n);

    ll l = 1, r = n, m, last = query(1, n), x, lb = -1;

    if(last == 1) lb = 1;
    else if(last == n) lb = 0;
    else {
        x = query(1, last);
        if(x == last) lb = 0;
        else lb = 1;
    }

    if(lb) {
        l = last + 1, r = n;
        while(l < r) {
            m = (l + r) / 2;
            x = query(last, m);
            if(x == last) r = m;
            else l = m + 1;
        }
    } else {
        l = 1, r = last - 1;
        while(l < r) {
            m = (l + r + 1) / 2;
            x = query(m, last);
            if(x == last) l = m;
            else r = m - 1;
        }
    }

    printf("! %lld\n", l); fflush(stdout);
    return 0;
}