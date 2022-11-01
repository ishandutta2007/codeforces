#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n, ans = -1, x, y;

struct srv {
    ll x, id;

    bool operator <(const srv &o) const {
        return x < o.x;
    }
} c[MN];

ll solve(int swp) {
    ll l = 2*n, r = -n;
    pll a1, a2;

    for(int i = 0; i < n; i++) {
        ll k1 = x / c[i].x + (x % c[i].x != 0);
        if(i + k1 > n) continue;
        if(l > i + k1) {
            l = i + k1;
            a1 = {i, k1};
        }
    }

    for(int i = 0; i < n; i++) {
        ll k2 = y / c[i].x + (y % c[i].x != 0);
        if(i + k2 > n) continue;

        if(r < i + k2) {
            r = i;
            a2 = {i, k2};
        }
    }

    if(l <= r) {
        printf("Yes\n");

        if(!swp) {
            printf("%lld %lld\n", a1.second, a2.second);

            for(int j = a1.first; j < a1.first + a1.second; j++) {
                printf("%lld ", c[j].id);
            } puts("");

            for(int j = a2.first; j < a2.first + a2.second; j++) {
                printf("%lld ", c[j].id);
            } puts("");

        } else {
            printf("%lld %lld\n", a2.second, a1.second);

            for(int j = a2.first; j < a2.first + a2.second; j++) {
                printf("%lld ", c[j].id);
            } puts("");

            for(int j = a1.first; j < a1.first + a1.second; j++) {
                printf("%lld ", c[j].id);
            } puts("");
        }

        exit(0);
    }

    return -1;
}

int main() {
    scanf("%lld %lld %lld", &n, &x, &y);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &c[i].x);
        c[i].id = i + 1;
    } sort(c, c + n);

    ans = solve(0);
    swap(x, y);
    ans = solve(1);

    printf("No\n");
    return 0;
}