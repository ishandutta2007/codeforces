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
//#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,p,k,a[300005];
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
int main(){
	scanf("%d%d%d",&n,&p,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(p <= 1000){
		int ans = 0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
			ll x = (a[i]+a[j])%p;
			ll y = (1LL*a[i]*a[i]+1LL*a[j]*a[j])%p;
			x = x*y%p;
			x = (x+p)%p;
			if(x == k) ans++;
		}
		printf("%d\n",ans);
	}
	else{
		mod = p;
		map<ll,int>C;
		for(int i=1;i<=n;i++){
			ll x = 1LL*a[i]*a[i]%mod*a[i]%mod*a[i]%mod;
			x -= 1LL*a[i]*k%mod;
			x = (x%mod+mod)%mod;
			C[x]++;
		}
		int ans = 0;
		for(auto x:C){
			ans += x.sc * (x.sc-1) / 2;
		}
		printf("%d\n",ans);
	}
}