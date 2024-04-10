//Let's join Kaede Takagaki Fun Club !!
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
int n;
ll a[400005];


int main(){
	ios::sync_with_stdio(false);
	g(n); repn(i,n) g(a[i]);
	
	ll ans = 0;
	for(ll m=24;m>=0;m--){
		vector<ll>vec(n);
		repn(i,n) vec[i-1] = a[i] % (2<<m);
		SORT(vec);
		//if(m == 1) dmp(vec);
		ll cnt = 0;
		auto add = [&](ll beg,ll en,int i){
			int lb = POSL(vec, beg);
			int ub = POSL(vec, en);
			ub = min(ub, i);
			if(lb < ub) cnt += ub-lb;
		};
		for(int i=0;i<n;i++){
			if(vec[i] < (1<<m)){
				ll beg = (1<<m)-vec[i];
				ll en = (2<<m)-vec[i];
				add(beg,en,i);
			}
			else{
				ll beg = 0;
				ll en = (2<<m)-vec[i];
				//if(m == 1 && i == 1) cout << beg << " " << en << endl;
				add(beg,en,i);
				beg = (3<<m)-vec[i];
				en = (4<<m)-vec[i];
				add(beg,en,i);
			}
		}
		if(cnt&1LL) ans ^= (1LL<<m);
	}
	o(ans);
}