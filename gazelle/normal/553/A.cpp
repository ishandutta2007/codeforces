#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

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
	ll k;
	cin>>k;
	vector<ll> c(k);
	REP(i,k) cin>>c[i];
	ll ans=1;
	ll sum=c[0];
	FOR(i,1,k) {
		sum+=c[i];
		ll buf=0;
		FOR(j,1,c[i]+1) {
			buf+=mod_comb(sum-1-j,c[i]-j);
			buf%=MOD;
		}
		ans*=buf;
		ans%=MOD;
	}
	cout<<ans<<endl;
}