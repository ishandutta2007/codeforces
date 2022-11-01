#include <bits/stdc++.h>

#define MN 401000

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll mul_mod(ll a, ll b, ll MOD) {
    ll x = a*b, y = (long double)a*b/MOD-0.5;
    return (x - y*MOD)%MOD;
}

/*
ll mul_mod(ll a, ll b, ll MOD) {
    ll ret = 0;
    a %= MOD;
    while(b) {
        if(b % 2) ret = (ret + a) % MOD;
        a = (a * 2) % MOD;
        b /= 2;
    }
    return ret;
} */

struct myhash {
	ll chash[MN][2];
	ll mult[MN][2];
	ll b1, M1, b2, M2;

	myhash(ll b1 = 1000000021, ll M1 = 1200000000000000013LL, ll b2 = 1000000009, ll M2 = 1200000000000000011LL) :
		b1(b1), M1(M1), b2(b2), M2(M2) { calc();}

	void calc() {
		mult[0][0] = mult[0][1] = 1;
		for(ll i=1; i < MN; i++) {
			mult[i][0] = mul_mod(mult[i-1][0], b1, M1);
			mult[i][1] = mul_mod(mult[i-1][1], b2, M2);
		}
	}

	// Preprocess new string in global string st
	void compute(vector<ll> &st) {
		chash[0][0] = chash[0][1] = st[0] + 1;
		for(int i=1; i<(int)st.size();i++) {
			chash[i][0] = (mul_mod(chash[i-1][0], b1, M1) + st[i] + 1) % M1;
			chash[i][1] = (mul_mod(chash[i-1][1], b2, M2) + st[i] + 1) % M2;
		}
	}

	// Hash of substring [l, r] INCLUSIVE
	pll substr(ll l, ll r) {
		if(!l) return make_pair(chash[r][0], chash[r][1]);

		ll p1 = (chash[r][0] - mul_mod(chash[l-1][0], mult[r-l+1][0], M1) + M1)%M1;
		ll p2 = (chash[r][1] - mul_mod(chash[l-1][1], mult[r-l+1][1], M2) + M2)%M2;
		return make_pair(p1, p2);
	}
} h1, h2;

ll n, m, a[MN];
vector<ll> diff;

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(i) diff.push_back((a[i] - a[i-1] + m) % m);
    }
    diff.push_back((a[0] - a[n-1] + m) % m);
    for(int i = 0, sz = diff.size(); i < sz; i++)
        diff.push_back(diff[i]);

    h1.compute(diff);
    reverse(diff.begin(), diff.end());
    h2.compute(diff);
    reverse(diff.begin(), diff.end());

    ll acum = 0;
    for(int i = 0; i < n; i++) acum += diff[i];
    assert(acum % m == 0);

    vector<ll> ans;
    for(int i = n; i < diff.size(); i++) {
        acum += diff[i];
        if(h1.substr(0, i) == h2.substr(diff.size() - i - 1, diff.size()-1)) {
            ans.push_back((2LL*a[0] + acum) % m);
        }
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%lld%c", ans[i], (i + 1 == ans.size()) ? '\n' :  ' ');
    }
    return 0;
}