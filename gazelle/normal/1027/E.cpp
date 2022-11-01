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
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,K;
	cin>>n>>K;
	vector<ll> val(n+1,0);
		ll dp[n][n+1][2];
	for(ll k=1; k<=n; k++) {
		REP(i,n) REP(j,n+1) REP(c,2) dp[i][j][c]=0;
		dp[0][1][0]=1;
		dp[0][1][1]=1;
		FOR(i,1,n) FOR(j,1,k+1) REP(c,2) {
			if(j==1) {
				FOR(l,1,k+1) dp[i][j][c]+=dp[i-1][l][!c];
			} else dp[i][j][c]+=dp[i-1][j-1][c];
			dp[i][j][c]%=MOD;
		}
		FOR(i,1,k+1) REP(c,2) val[k]+=dp[n-1][i][c];
		val[k]=val[k]%MOD+MOD;
		val[k]%=MOD;
	}
	ll ans=0;
	FOR(i,1,n+1) {
		ans+=(((val[i]-val[i-1])%MOD+MOD)%MOD)*val[min((K-1)/i,n)];
		ans%=MOD;
	}
	ans*=_pow(2,MOD-2);
	cout<<(ans%MOD+MOD)%MOD<<endl;
}