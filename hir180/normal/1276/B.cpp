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

struct U{
	int par[200005],ran[200005];
	void init(int n){ for(int i=0;i<n;i++) par[i] = i, ran[i] = 0; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}A,B,AB;
int n,m,a,b;
vector<P>edge;
int ra[200005],rb[200005];
int ca[200005],cb[200005];
map<P,int>M;
void solve(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	edge.clear();
	A.init(n+2); B.init(n+2); AB.init(n+2);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge.pb(P(a,b));
	}
	repn(i,n) ca[i] = cb[i] = 0;
	ll ans = 0;
	rep(i,m){
		if(edge[i].fi == a || edge[i].sc == a) continue;
		A.unite(edge[i].fi,edge[i].sc);
	}
	repn(i,n) if(i!=a&&i!=b) {ra[i] = A.find(i); ca[A.find(i)]++; }
	rep(i,m){
		if(edge[i].fi == b || edge[i].sc == b) continue;
		B.unite(edge[i].fi,edge[i].sc);
	}
	repn(i,n) if(i!=a&&i!=b) {rb[i] = B.find(i); cb[B.find(i)]++; }
	
	M.clear();
	repn(i,n) if(i!=a&&i!=b) M[mp(ra[i],rb[i])]++;
	
	for(auto A:M){
		ans += 1LL * A.sc * (n-2-ca[A.fi.fi]-cb[A.fi.sc]+A.sc);
	}
	printf("%lld\n",ans/2);
}
int main(){
	int t; scanf("%d",&t);
	while(t--) solve();
}