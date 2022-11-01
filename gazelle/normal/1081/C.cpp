#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
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
using P=pair<ll,ll>;
#define MOD 998244353LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

#define MAX_N 1000000
long long extgcd(long long a, long long b, long long& x, long long& y) {
	long long d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}
long long mod_inverse(long long a, long long m) {
	long long x, y;
	if(extgcd(a, m, x, y) == 1) return (m + x % m) % m;
	else return -1;
}
vector<long long> fact(MAX_N+1, INF);
long long mod_fact(long long n, long long& e) {
	if(fact[0] == INF) {
		fact[0]=1;
		if(MAX_N != 0) fact[1]=1;
		for(ll i = 2; i <= MAX_N; ++i) {
			fact[i] = (fact[i-1] * i) % MOD;
		}
	}
	e = 0;
	if(n == 0) return 1;
	long long res = mod_fact(n / MOD, e);
	e += n / MOD;
	if((n / MOD) % 2 != 0) return (res * (MOD - fact[n % MOD])) % MOD;
	return (res * fact[n % MOD]) % MOD;
}
// return nCk
long long mod_comb(long long n, long long k) {
	if(n < 0 || k < 0 || n < k) return 0;
	long long e1, e2, e3;
	long long a1 = mod_fact(n, e1), a2 = mod_fact(k, e2), a3 = mod_fact(n - k, e3);
	if(e1 > e2 + e3) return 0;
	return (a1 * mod_inverse((a2 * a3) % MOD, MOD)) % MOD;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = m;
	REP(i, k) {
		ans *= m - 1;
		ans %= MOD;
	}
	ans *= mod_comb(n - (k + 1) + k, k);
	cout << ans % MOD << endl;
	return 0;
}

/* --------------------------------------- */