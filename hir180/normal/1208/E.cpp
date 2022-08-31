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
void o(T a){
	cout << a << '\n';
}
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int n,w;
ll ans[1000005];
int a[1000005];

struct RMQ{
	int seg[(1<<21)];
	int sz;
	void init(int n){
		sz = 1;
		while(sz < n+5) sz <<= 1;
		rep(i,2*sz) seg[i] = -INF-7;
	}
	void update(int k,int a){
		k+=sz-1; seg[k]=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return -INF-7;
		if(a<=l && r<=b) return seg[k];
		else{
			int vl=query(a,b,k*2+1,l,(l+r)/2);
			int vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return max(vl,vr);
		}
	}
	int query(int a,int b){
		return query(a,b,0,0,sz-1);
	}
}kaede;

int main(){
	ios::sync_with_stdio(false);
	g(n); g(w);
	rep(i,n){
		int t; g(t);
		kaede.init(t);
		P mx = mp(-INF-7, -INF);
		rep(j,t){
			g(a[j]);
			kaede.update(j, a[j]);
			mx = max(mx,mp(a[j],j));
		}
		int len = w-t;
		int id = mx.sc;
		for(int i=0;i<id;i++){
			int R = i;
			int L = i-len; L = max(L, 0);
			ll v =  kaede.query(L,R);
			if(len <= i && i <= w-1-len);
			else v = max(v,0ll);
			ans[i] += v;
			ans[i+1] -= v;
		}
		for(int i=w-1;i>len+id;i--){
			int L = i;
			int R = i+len; R = min(R, w-1);
			ll v =  kaede.query(L-(w-t),R-(w-t));
			if(len <= i && i <= w-1-len);
			else v = max(v,0ll);
			ans[i] += v;
			ans[i+1] -= v;
		}
		if(mx.fi >= 0){
			ans[id] += mx.fi;
			ans[id+len+1] -= mx.fi;
		}
		else{
			int L = max(id, len);
			int R = min(id+len, w-1-len);
			if(L > R) continue;
			ans[L] += mx.fi;
			ans[R+1] -= mx.fi;
		}
	}
	for(int i=1;i<w;i++) ans[i] += ans[i-1];
	rep(i,w) o(ans[i]);
}