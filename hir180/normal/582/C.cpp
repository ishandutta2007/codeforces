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
#define per(i,x) for(int i=x-1;i>=0;i--)
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
int n,a[400005];
vector<int>cand;
ll ans;
int rui[200005];
int mx[200005];
int mxcnt[400005];
int succ[400005];
int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) a[n+i] = a[i];
	for(int i=1;i*i<=n;i++){
		if(n%i != 0) continue;
		cand.pb(i);
		if(i*i != n) cand.pb(n/i);
	}
	SORT(cand);
	for(auto g:cand){
		int ng = n/g;
		for(int i=1;i<=ng;i++){
			rui[i] = rui[i-1] + (__gcd(ng,i) == 1);
		}
		memset(mx,0,sizeof(mx));
		rep(i,n){
			mx[i%g] = max(mx[i%g], a[i]);
		}
		rep(i,2*n){
			mxcnt[i] = mxcnt[i-1];
			if(mx[i%g] == a[i]){
				mxcnt[i]++;
			}
		}
		succ[2*n] = 0;
		for(int pos=2*n-g;pos>=0;pos--){
			if(mxcnt[pos+g-1] - (pos==0?0:mxcnt[pos-1]) != g){
				succ[pos] = 0;
			}
			else{
				succ[pos] = succ[pos+g]+1;
			}
		}
		rep(beg,n){
			int num = min(succ[beg], ng-1);
			ans += rui[num];
		}
	}
	cout << ans << endl;
}