#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

pair<vector<ll>, vector<ll>> prime_factor_decomp(ll n) {
	vector<ll> p, e;
	ll m = n;
	for (ll i = 2; i * i <= n; i++) {
		if (m % i != 0) continue;
		int c = 0;
		while (m % i == 0) c++, m /= i;
		p.push_back(i);
		e.push_back(c);
	}
	if (m > 1) {
		p.push_back(m);
		e.push_back(1);
	}
	return make_pair(p, e);
}

ll _pow(ll a, ll n) {
	if(n==0) return 1;
	else {
		ll res = 1;
		ll buf = a;
		while(n>0) {
			if(n%2==1) {
				res *= buf;
				res %= MOD;
			}
			buf *= buf;
			buf %= MOD;
			n/=2;
		}
		return res;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<ll> inv(1010);
	FOR(i, 1, 1010) inv[i] = _pow(i, MOD - 2);
	pair<vector<ll>, vector<ll>> prim = prime_factor_decomp(n);
	ll m = prim.first.size();
	ll ans = 1;
	REP(i, m) {
		vector<vector<ll>> dp(k + 1, vector<ll>(prim.second[i] + 1, 0));
		REP(j, k + 1) REP(l, prim.second[i] + 1) {
			if(j == 0) dp[j][l] = _pow(prim.first[i], l);
			else {
				REP(q, l + 1) {
					dp[j][l] += inv[l + 1] * dp[j - 1][q]; dp[j][l] %= MOD;
				}
			}
		}
		ans *= dp[k][prim.second[i]]; ans %= MOD;
	}
	cout << (ans % MOD + MOD) % MOD << endl;
	return 0;
}

/* --------------------------------------- */