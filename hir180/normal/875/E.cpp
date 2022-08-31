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
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}



int n, s1, s2;
int x[100005];


int main(){
	ios::sync_with_stdio(false);
	g(n); g(s1); g(s2);
	rep(i,n){
		g(x[i]);
	}
	int lb = abs(s1-s2)-1, ub = INF+2;
	while(ub-lb > 1){
		int mid = (lb+ub)/2;
		set<int>prv;
		if(abs(s1-x[0]) <= mid) prv.insert(s1);
		if(abs(s2-x[0]) <= mid) prv.insert(s2);
		int one = x[0];
		
		for(int i=1;i<n && prv.size();i++){
			auto it = prv.begin();
			while(it != prv.end() && *it < x[i]-mid) it = prv.erase(it);
			it = prv.upper_bound(x[i]+mid);
			while(it != prv.end()) it = prv.erase(it);
			
			if(abs(one-x[i]) <= mid) prv.insert(one);
			one = x[i];
		}
		if(prv.size()) ub = mid;
		else lb = mid;
	}
	o(ub);
}