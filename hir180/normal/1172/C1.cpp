#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}

const ll mod = 998244353;
int n,m;
ll a[200005],w[200005];
ll z,o;
ll dp[3005][3005];

ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&w[i]);
	rep(i,n){
		if(a[i] == 0) z += w[i];
		else o += w[i];
	}
	dp[0][0] = 1;
	rep(i,m){
		rep(j,i+1){
			//dp[j][i-j]
			if(dp[j][i-j] == 0) continue;
			ll cz = z-j;
			ll co = o+i-j;
			ll rev = (cz+co);
			rev = modpow(rev,mod-2);
			dp[j+1][i-j] += dp[j][i-j] * cz % mod * rev % mod;
			dp[j][i-j+1] += dp[j][i-j] * co % mod * rev % mod;
			dp[j+1][i-j] %= mod;
			dp[j][i-j+1] %= mod;
		}
	}
	ll v[2] = {};
	rep(i,m+1){
		if(dp[i][m-i] == 0) continue;
		v[0] += dp[i][m-i] * (z-i) % mod;
		v[1] += dp[i][m-i] * (o+m-i) % mod;
	}
	v[0] %= mod; v[1] %= mod;
	rep(i,n) {
		ll ans;
		if(a[i] == 0){
			ans = v[0] * modpow(z,mod-2) % mod * w[i] % mod;
		}
		else{
			ans = v[1] * modpow(o,mod-2) % mod * w[i] % mod;
		}
		printf("%lld\n",(ans%mod+mod)%mod);
	}
}