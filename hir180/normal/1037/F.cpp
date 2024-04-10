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
#define ld long double
const ll mod = 1000000007;
int n,k;
ll a[1000005];
ll calc(ll x){
	if(x < k) return 0;
	ll dv = (x-1) / (k-1);
	ll ret = 1LL*(x)*dv - 1LL*(k-1)*dv*(dv+1)/2;
	return (ret%mod);
}
set<int>pos;
vector<pair<ll,int>>vec;
ll ans;
int main(){
	scanf("%d%d",&n,&k);
	repn(i,n) {scanf("%lld",&a[i]); vec.pb(mp(a[i],i));}
	sort(vec.begin(),vec.end(),greater<pair<ll,int>>());
	pos.insert(0); pos.insert(n+1);
	rep(i,vec.size()){
		auto it = pos.lower_bound(vec[i].sc);
		int x = *it; it-- ; int y = *it;
		ll add = calc(x-y-1);
		add -= calc(x-vec[i].sc-1) + calc(vec[i].sc-y-1);
		pos.insert(vec[i].sc);
		ans += add * vec[i].fi % mod;
	}
	cout << (ans%mod+mod)%mod << endl;
}