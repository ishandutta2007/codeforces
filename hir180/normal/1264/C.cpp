#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 998244353;
int n,q;
ll a[200005];
ll rv[105];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
struct seg{
	ll seg1[(1<<19)],seg2[(1<<19)];
	void update1(int pos,ll A){
		pos += (1<<18)-1;
		seg1[pos] = 100LL*rv[A]%mod;
		seg2[pos] = -100LL*rv[A]%mod;
		seg2[pos] = (seg2[pos]%mod+mod)%mod;
	}
	void update2(){
		for(int i=(1<<18)-2;i>=0;i--){
			seg1[i] = seg1[i*2+1]*seg1[i*2+2]%mod;
			seg2[i] += seg2[i*2+1]*seg1[i*2+2]%mod;
			seg2[i] += seg2[i*2+2];
			seg2[i] = (seg2[i]%mod+mod)%mod;
		}
	}
	pair<ll,ll>query(int a,int b,int k,int l,int r){
		if(r < a || b < l) return mp(1LL,0LL);
		if(a <= l && r <= b ) return mp(seg1[k],seg2[k]);
		pair<ll,ll>L = query(a,b,k*2+1,l,(l+r)/2);
		pair<ll,ll>R = query(a,b,k*2+2,(l+r)/2+1,r);
		ll X = L.fi*R.fi%mod;
		ll Y = L.sc*R.fi+R.sc;
		Y = (Y%mod+mod)%mod;
		return mp(X,Y);
	}
}kaede;
set<int>pos;
ll ans;
int main(){
	for(int i=1;i<=100;i++) rv[i] = modpow(i,mod-2);
	
	scanf("%d%d",&n,&q);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) kaede.update1(i,a[i]);
	kaede.update2();
	pos.insert(0);
	pos.insert(n);
	ans = kaede.query(0,n-1,0,0,(1<<18)-1).sc;
	ans = ((ans*-1LL)%mod+mod)%mod;
	
	rep(i,q){
		int p; scanf("%d",&p); p--;
		if(pos.find(p) == pos.end()){
			auto it = pos.lower_bound(p); int ri = *it;
			it--; int le = *it;
			ans += kaede.query(le,ri-1,0,0,(1<<18)-1).sc;
			ans -= kaede.query(le,p-1,0,0,(1<<18)-1).sc;
			ans -= kaede.query(p,ri-1,0,0,(1<<18)-1).sc;
			ans = (ans%mod+mod)%mod;
			pos.insert(p);
			printf("%lld\n",ans);
		}
		else{
			auto it = pos.lower_bound(p); it++; int ri = *it;
			it--; it--; int le = *it;
			ans -= kaede.query(le,ri-1,0,0,(1<<18)-1).sc;
			ans += kaede.query(le,p-1,0,0,(1<<18)-1).sc;
			ans += kaede.query(p,ri-1,0,0,(1<<18)-1).sc;
			ans = (ans%mod+mod)%mod;
			pos.erase(pos.find(p));
			printf("%lld\n",ans);
		}
	}
}