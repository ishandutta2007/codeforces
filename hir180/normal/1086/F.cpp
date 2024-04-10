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
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n,t;
const ll mod = 998244353;
vector<ll>za;

ll x[55],y[55];
ll smsum(ll a){
	return (a * (a+1) / 2) % mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll dbsum(ll a){
	return a*(a+1)%mod*(2*a+1)%mod*modpow(6LL,mod-2)%mod;
}
ll calc(ll T){
    if(T == 0) return n;
    vector<ll>zax,zay;
    rep(i,n){
		zax.pb(x[i]-T); zax.pb(x[i]+T+1);
		zay.pb(y[i]-T); zay.pb(y[i]+T+1);
	}
	SORT(zax); ERASE(zax);
	SORT(zay); ERASE(zay);
	
	bool ex[105][105]={};
	rep(i,n){
		int a = POSL(zax,x[i]-T); int aa = POSL(zax,x[i]+T+1);
		int b = POSL(zay,y[i]-T); int bb = POSL(zay,y[i]+T+1);
		for(int c=a;c<aa;c++) for(int d=b;d<bb;d++) ex[c][d] = 1;
	}
	
	ll ret = 0;
	rep(i,zax.size()) rep(j,zay.size()){
		if(ex[i][j]){
			ret += (zax[i+1]-zax[i]) * (zay[j+1]-zay[j]) % mod;
		}
	}
	return ret%mod;
}
int main(){
	cin >> n >> t;
	rep(i,n){
		cin >> x[i] >> y[i];
	}
	za.pb(1);
	za.pb(t+1);
	rep(i,n) rep(j,n){
		if(i < j){
			ll mx = max(abs(x[i]-x[j]),abs(y[i]-y[j]));
			za.pb((mx+1)/2);
		}
	}
	
	SORT(za); ERASE(za);
	
	ll ans = 0;
	for(int i=0;i<za.size();i++){
		if(za[i] == t+1) break;
		//sum ax^2 + bx over [za[i], za[i+1])
		
		if(za[i+1]-za[i] <= 4){
			ans += (calc(za[i]) - calc(za[i]-1)) * za[i] % mod;
			for(ll x=za[i]+1;x<za[i+1];x++){
				ans += (calc(x)-calc(x-1)) * x % mod;
			}
		}
		else{
			ans += (calc(za[i]) - calc(za[i]-1)) * za[i] % mod;
			
			ll pre = (calc(za[i]+1) - calc(za[i]));
			ll nxt = (calc(za[i]+2) - calc(za[i]+1));
			
			ll a = (nxt-pre);
			ll b = pre - a * (za[i]+1) % mod;
			
			//ax^2+bx  [za[i]+1, za[i+1]) 
			
			ans += a * (dbsum(za[i+1]-1) - dbsum(za[i])) % mod;
			ans += b * (smsum(za[i+1]-1) - smsum(za[i])) % mod;
		}
	}
	
	cout << (ans%mod+mod)%mod << endl;
}