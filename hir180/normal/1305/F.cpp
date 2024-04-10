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
#define mod 1000000007
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

int n;
ll a[200005];
vector<int>pr;
bool bad[1000005];

int main(){
	for(int i=2;i<=1000000;i++){
		if(bad[i]) continue;
		pr.pb(i);
		for(int j=2;i*j<=1000000;j++) bad[i*j] = 1;
	}
	scanf("%d",&n);
	rep(i,n)  scanf("%lld",&a[i]);
	mt19937 mt(61471);
	vector<int>cand;
	if(n <= 50){
		rep(i,n) cand.pb(i);
	}
	else{
		rep(x,50) cand.pb(mt()%n);
	}
	
	ll ans = 1e18;
	for(auto test:cand){
		vector<ll>vec;
		ll v = a[test];
		if(v > 1) vec.pb(v-1);
		vec.pb(v);
		vec.pb(v+1);
		vector<ll>cp;
		
		for(auto x:vec){
			for(int i=0;i<pr.size();i++){
				if(x%pr[i] != 0) continue;
				cp.pb(pr[i]);
				while(x%pr[i] == 0) x /= pr[i];
			}
			if(x != 1) cp.pb(x);
		}
		
		for(auto x:cp){
			ll cur = 0;
			rep(i,n){
				ll rem = a[i]%x;
				ll add = 1e18;
				if(rem != a[i]) add = min(add,rem);
				add = min(add,x-rem);
				
				cur += add;
				if(cur >= ans) break;
			}
			ans = min(ans,cur);
		}
	}
	cout << ans << endl;
}