#include <bits/stdc++.h>

#define MOD 1000000007
#define MN 2010

using namespace std;
typedef long long ll;

ll n, dp[MN][MN][2];

ll expo(ll b, ll e) {
    if(!e) return 1;
    b %= MOD;
    if(e & 1) return b * expo(b * b, e >> 1) % MOD;
    return expo(b * b, e >> 1);
}

ll inv_mod(ll x) {return expo(x, MOD - 2);}

void add(ll &x, ll d) {
    x += d;
    while(x >= MOD) x -= MOD;
}

ll solve(int rem, int sal, int skip) {
    if(sal < 0) return -1;
    if(rem == 0) return sal ? -1 : 0;

    ll &x = dp[rem][sal][skip];
    if(x != -2) return x;
    x = -1;

    ll ln = solve(rem-1, sal+1, 0), ly = solve(rem-1, sal+1, 1),
        rn = solve(rem-1, sal-1, 0), ry = solve(rem-1, sal-1, 1),
        y = 0;

    if(ln >= 0) {
        add(y, ln);
        if(rn >= 0) add(y, rn);
    }
    else if(rn >= 0) add(y, rn);
    else y = -1;

    if(!skip) {
        ll pl = 0, pr = 0;
        if(ly >= 0) {
            add(pl, ly + 1);
            if(rn >= 0) add(pl, rn);
        }
        else if(rn >= 0) add(pl, rn);
        else pl = -1;

        if(ln >= 0) {
            add(pr, ln);
            if(ry >= 0) add(pr, ry + 1);
        }
        else if(ry >= 0) add(pr, ry + 1);
        else pr = -1;

        x = max(x, pl);
        x = max(x, pr);
    }
    x = max(x, y);

    return x;
}

int main() {
    scanf("%lld", &n);
    fill_n(**dp, MN*MN*2, -2LL);
    printf("%lld\n", solve(2*n, 0, 0));
    return 0;
}