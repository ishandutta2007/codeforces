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

int n;
ll m;
vector<ll>mod;
int q;
vector<int>pos;
ll a[100005];
ll modpow(ll x,ll n,ll modd){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%modd;
		x=x*x%modd;
		n>>=1;
	}
	return res;
}
//first ... [aa...b] mod [id]
//second ... min([aa...b], 30)
pair<ll,ll> calc(int aa,int b,int id){
	if(id == mod.size()-1){
		//mod[id] = 1;
		ll ret = min(30LL,a[b]);
		for(int i=b-1;i>=aa;i--){
			//a[i] ^ ret
			if(a[i] >= 30 || ret >= 5){
				ret = 30;
				break;
			}
			else{
				ret = modpow(a[i],ret,INF);
				if(ret >= 30){
					ret = 30; break;
				}
			}
		}
		return mp(0, ret);
	}
	else if(aa == b){
		return mp(a[aa] % mod[id], min(30LL, a[aa]));
	}
	else{
		pair<ll,ll> ret = calc(aa+1,b,id+1);
		while(ret.fi < ret.sc) ret.fi += mod[id+1];
		
		if(a[aa] >= 30 || ret.sc >= 5) ret.sc = 30;
		else{
			ret.sc = modpow(a[aa], ret.sc, INF);
			if(ret.sc >= 30) ret.sc = 30;
		}
		return mp(modpow(a[aa],ret.fi,mod[id]), ret.sc);
	}
}
int main(){
	scanf("%d%lld",&n,&m);
	repn(i,n) scanf("%lld",&a[i]);
	repn(i,n) if(a[i] == 1) pos.pb(i);
	
	ll c = m;
	while(1){
		mod.pb(c);
		if(c == 1) break;
		vector<int>pr;
		int d = c;
		for(int i=2;i*i<=d;i++){
			if(d%i != 0) continue;
			while(d%i == 0) d/=i;
			pr.pb(i);
		}
		if(d != 1) pr.pb(d);
		
		rep(i,pr.size()) c = c / pr[i] * (pr[i]-1);
	}
	
	scanf("%d",&q);
	while(q--){
		int l,r; scanf("%d%d",&l,&r);
		if(a[l] == 1){
			printf("%lld\n",1%m);
		}
		else{
			int x = POSL(pos,l);
			if(x < pos.size() && pos[x] <= r) r = pos[x]-1;
			pair<ll,ll>ret = calc(l,r,0);
			printf("%lld\n",ret.fi);
		}
	}
}