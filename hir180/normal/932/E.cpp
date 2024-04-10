#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k;
ll C[5005][5005],mul[5005];
struct L_interpolation{
	int deg;
	vector<pair<ll,ll> >pts;
	ll ff[1000005];
	//must call init first!!!!
	//vec-x (: )
	void init(int n,vector<pair<ll,ll> >vec){
		SORT(vec);
		ERASE(vec);
		assert(vec.size() > n);
		vec.resize(n+1);
		this->deg = n;
		this->pts = vec;
		ff[0] = 1;
		for(int i=1;i<1000005;i++) ff[i] = ff[i-1]*1LL*i%mod;
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
	//return f(x)
	//O(N log N)
	ll f(ll x){
		vector<ll>up;
		ll M = 1;
		rep(i,deg+1){
			if(pts[i].fi == x) return pts[i].sc;
			up.pb(x-pts[i].fi);
			M *= (x-pts[i].fi);
			M %= mod;
		}
		//vec.size() <= 1 -> broken
		ll d = pts[1].fi-pts[0].fi,ret = 0;
		rep(i,deg+1){
			ll add = pts[i].sc;
			add = add*M%mod;
			add = add*(this->modpow((x-pts[i].fi)%mod,mod-2))%mod;
			//plus i * minus n-i
			add = add*(this->modpow(this->modpow(d,deg),mod-2))%mod;
			add = add*(this->modpow(ff[i],mod-2))%mod;
			add = add*(this->modpow(ff[deg-i],mod-2))%mod;
			if((deg-i)%2 == 1) add = (mod-add)%mod;
			else add = (add+mod)%mod;
			ret += add;
		}
		return ret%mod;
	}
}kaede;
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
	cin>>n>>k;
	rep(i,5005) rep(j,i+1){
		if(j==0||j==i) C[i][j] = 1;
		else C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
	}
	rep(i,5005){
		mul[i] = 1;
		rep(j,k) mul[i] = mul[i]*1LL*i%mod;
	}
	vector<pair<ll,ll> >vec;
	for(int i=1;i<=k+3;i++){
		ll sum = 0;
		for(int j=0;j<=i;j++){
			sum += C[i][j]*mul[j]%mod;
		}
		sum %= mod;
		sum = sum*modpow(modpow(2,i),mod-2)%mod;
		vec.pb(mp(1LL*i,sum%mod));
	}
	kaede.init(k+2,vec);
	cout<<kaede.f(n)*modpow(2,n)%mod<<endl;
}