#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 998244353ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> dp(n,0);
	for(ll i=n-1; i>=0; i--) {
		if(a[i]<=0) continue;
		if(n-1-i>=a[i]) dp[i]+=mod_comb(n-1-i,a[i]);
		dp[i]%=MOD;
		FOR(j,i+1,n) {
			if(j-i-1>=a[i]) {
				dp[i]+=mod_comb(j-1-i,a[i])*dp[j];
				dp[i]%=MOD;
			}
		}
	}
	ll ans=0;
	REP(i,n) {
		ans+=dp[i];
		ans%=MOD;
	}
	cout<<ans<<endl;
}