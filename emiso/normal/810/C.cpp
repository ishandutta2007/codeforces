#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll n, a[MN], expo[MN], dp, ans, d[MN];

ll pow_(ll a,ll b) {
    ll ret=1;
    for(;b > 0; b >>= 1){
        if(b % 2)
            ret = (ret * a) % MOD;
        a = (a*a) % MOD;
    }
    return ret;
}
//char s[MN]; string str;

void calc() {
    expo[0] = 1;
    for(int i=1; i<300300; i++) {
        expo[i] = (expo[i-1] * 2) % MOD;
    }
}

int main() {

    calc();

    scanf("%lld", &n);

    for(int i=1; i<=n; i++) {
        scanf("%lld",&a[i]);
    } sort(a+1, a+n+1);

    for(int i=2; i<=n; i++) {
        d[i-1] = a[i] - a[i-1];
    }

    ll tmp = 0;
    for(int i=1; i<n; i++) {
        tmp = (tmp + d[i]) % MOD;
        dp += (tmp * expo[i-1]) % MOD;
    }

    ans += dp;
    for(int i=2; i<n; i++) {
        dp = (dp - d[i-1] + MOD) % MOD;

        dp  = (dp * pow_(2, MOD - 2)) % MOD;

        ll mult = (d[i-1] * expo[n-i]) % MOD;

        dp = (dp - mult + MOD) % MOD;
        dp = (dp + d[i-1]) % MOD;

        ans = (ans + dp) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}