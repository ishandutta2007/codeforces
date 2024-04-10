//Let's join Kaede Takagaki Fan Club !!
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
#define all(x) x.begin(),x.end()
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
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll w, l, a[100005], rui[100005];
ll get(ll cnt){
	int a = lower_bound(rui+1, rui+w+1, cnt) - rui;
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> w >> l;
	for(int i=1;i<w;i++) cin >> a[i];
	a[w] = 1e18;
	repn(i,w) rui[i] = rui[i-1] + a[i];
	
	ll lb = 0, ub = INF+7;
	while(ub-lb > 1){
		ll mid = (lb+ub)/2;
		bool ok = 1;
		if(get(mid) > l) ok = 0;
		ll cnt = 0;
		for(int i=1;i<w;i++){
			cnt += a[i];
			if(get(cnt+mid) > l+i) ok = 0;
		}
		if(ok) lb = mid; else ub = mid;
	}
	o(lb);
}