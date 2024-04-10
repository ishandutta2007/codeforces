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
ll mod;
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll a[100005];
int n;
vector<pair<ll,ll>>cand;
set<ll>S;

int main(){
	scanf("%lld%d",&mod,&n);
	ll sum = 0;
	rep(i,n){
		scanf("%lld",&a[i]);
		sum = (sum+a[i])%mod;
		S.insert(a[i]);
	}
	if(mod == n){
		puts("0 1");
		return 0;
	}
	if(n == 1){
		printf("%lld 0\n",a[0]);
		return 0;
	}
	
	ll rev = modpow((1LL*n*(n-1)/2)%mod, mod-2);
	rep(i,n){
		ll d = (sum-1LL*n*a[i])%mod*rev%mod;
		if(d < 0) d += mod;
		if(d == 0) continue;
		cand.pb(mp(a[i],d));
	}
	mt19937 mt;
	mt.seed(614);
	
	if(mod <= 2*n){
		vector<int>ex;
		rep(i,mod){
			if(S.find(i) == S.end()) ex.pb(i);
		}
		shuffle(ex.begin(), ex.end(), mt);
		rep(i,cand.size()){
			ll R = modpow(cand[i].sc,mod-2);
			rep(j,ex.size()) {
				ll ch = (ex[j]-cand[i].fi)*R%mod;
				if(ch < 0) ch += mod;
				if(ch < n) goto fail;
			}
			cout << cand[i].fi << " " << cand[i].sc << endl;
			return 0;
			fail:;
		}
	}
	else{
	    shuffle(cand.begin(), cand.end(), mt);
	    shuffle(a, a+n, mt);
		//random
		rep(i,cand.size()){
		    ll R = modpow(cand[i].sc,mod-2);
		    ll x = cand[i].fi, y = cand[i].sc;
		    rep(j,n){
		        ll ch = (a[j]-x)*R%mod;
		        if(ch < 0) ch += mod;
		        if(ch >= n) goto fail2;
		    }
			cout << cand[i].fi << " " << cand[i].sc << endl;
			return 0;
			fail2:;
		}
	}
	puts("-1");
}