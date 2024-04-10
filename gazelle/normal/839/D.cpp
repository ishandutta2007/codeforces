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
#include<complex>

#define INF (long long)1000000000
#define MOD 1000000007
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

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
	int n;
	cin>>n;
	vector<int> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> cnt(1000001,0);
	REP(i,n) {
		for(ll j=1; j*j<=a[i]; ++j) {
			if(a[i]%j==0) {
				if(j!=1) ++cnt[j];
				if(a[i]/j!=1&&j!=a[i]/j) ++cnt[a[i]/j];
			}
		}
	}
	vector<ll> b(1000001);
	for(ll i=1000000; i>=2; --i) {
		if(cnt[i]==0) continue;
		ll res=(cnt[i]*_pow(2,cnt[i]-1))%MOD;
		for(ll j=2; i*j<=1000001; ++j) {
			res-=b[i*j];
			res=(res+MOD)%MOD;
		}
		b[i]=res;
	}
	ll ans=0;
	REP(i,1000001) {
		ans+=i*b[i];
		ans%=MOD;
	}
	cout<<ans<<endl;
}