#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;
typedef long long ll;

map<ll, int> f;
map<ll, ll> cube, quad, f2;
vector<ll> notyet;

void pp4() {
    for(ll i = 1;; i++) {
        ll cand = i*i*i*i;
        quad[cand] = i;
        if(cand > 2000000000000000000LL) break;
    }
}

int p4(ll x) {
    if(quad.count(x)) {
        f[quad[x]] += 4;
        return 1;
    }
    return 0;
}

void pp3() {
    for(ll i = 1;; i++) {
        ll cand = i*i*i;
        cube[cand] = i;
        if(cand > 2000000000000000000LL) break;
    }
}

int p3(ll x) {
    if(cube.count(x)) {
        f[cube[x]] += 3;
        return 1;
    }
    return 0;
}

int p2(ll x) {
    ll sq = round(sqrtl((long double) x));

    for(ll i = sq-1; i <= sq+1; i++) {
        if(i*i == x) {
            f[i] += 2;
            return 1;
        }
    }

    return 0;
}

int n;
ll a[505], ans;

int main() {
    scanf("%d", &n);

    pp3();
    pp4();

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);

        if(p4(a[i]));
        else if(p3(a[i]));
        else if(p2(a[i]));
        else notyet.push_back(a[i]);
    }

    for(int i = 0; i < (int)notyet.size(); i++) {
        ll val = notyet[i];
        for(auto divi : f) {
            if(val % divi.first == 0) {
                f[divi.first]++;
                val /= divi.first;
                f[val]++;
                val = 1;
            }
        }
        if(val == 1) continue;

        for(int j = i + 1; j < (int)notyet.size(); j++) {
            ll v2 = notyet[j];
            if(val == v2) continue;
            ll g = __gcd(val, v2);
            if(g > 1) {
                f[g]++;
                val /= g;
                f[val]++;
                val = 1;
            }
        }

        if(val > 1) f2[val]++;
    }

    ans = 1;
    for(auto divi : f) {
        ans = ans * (divi.second + 1LL) % MOD;
    }

    for(auto divi : f2) {
        ans = ans * (divi.second + 1LL) % MOD * (divi.second + 1LL) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}