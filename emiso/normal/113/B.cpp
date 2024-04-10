#include <bits/stdc++.h>

#define MAXN 250250

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct myhash {
    int sz;
	ll **chash, **mult;
	ll b1, M1, b2, M2;

	myhash(string &st, ll b1 = 311, ll M1 = 1000000021, ll b2 = 317, ll M2 = 1000000009) :  b1(b1), M1(M1), b2(b2), M2(M2) {
	    sz = st.size();
        chash = new ll*[sz];
        mult  = new ll*[sz];
        for(int i = 0; i < sz; i++) {
            chash[i] = new ll[2];
            mult[i] = new ll[2];
        }
        calc();
        compute(st);
    }
	void calc() {
		mult[0][0] = mult[0][1] = 1;
		for(ll i=1; i < sz; i++) {
			mult[i][0] = (mult[i-1][0] * b1)%M1;
			mult[i][1] = (mult[i-1][1] * b2)%M2;
		}
	}
	void compute(string &st) {
		chash[0][0] = chash[0][1] = st[0] + 1;
		for(int i=1; i<(int)st.size();i++) {
			chash[i][0] = ((chash[i-1][0]*b1)%M1 + st[i] + 1)%M1;
			chash[i][1] = ((chash[i-1][1]*b2)%M2 + st[i] + 1)%M2;
		}
	}
	pll substr(ll l, ll r) {
		if(!l) return make_pair(chash[r][0], chash[r][1]);

		ll p1 = (chash[r][0] - (chash[l-1][0] * mult[r-l+1][0])%M1 + M1)%M1;
		ll p2 = (chash[r][1] - (chash[l-1][1] * mult[r-l+1][1])%M2 + M2)%M2;
		return make_pair(p1, p2);
	}
};

char s[MAXN];
string t, trev, a, b;
pll aval, bval;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
const ll SEED = (ll)(new ll);
const ll RANDOM = TIME ^ SEED;
const ll MOD = (int)1e9+7;
const ll MUL = (int)1e6+3;

struct chash{
    ll operator()(ll x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }
};
gp_hash_table<ll, int, chash> ans;

int main() {
    scanf("%s", s);
    t = s;
    trev = string(t.rbegin(), t.rend());
    myhash l(t), r(trev);

    scanf("%s", s);
    a = s;
    myhash ha(a);
    aval = ha.substr(0, a.size()-1);

    scanf("%s", s);
    b = s;
    reverse(b.begin(), b.end());
    myhash hb(b);
    bval = hb.substr(0, b.size()-1);

    for(int i = 0; i + a.size() - 1 < t.size(); i++) {
        if(l.substr(i, i + a.size()-1) != aval) continue;
        for(int j = i; j < t.size(); j++) {
            if(i + max(a.size(), b.size()) > j + 1) continue;
            if(r.substr(t.size()-j-1, t.size()-j-1+b.size()-1) != bval) continue;

            pll tmp = l.substr(i, j);
            ans[tmp.first * 1000001000 + tmp.second] = 1;
        }
    }

    printf("%d\n", ans.size());
	return 0;
}