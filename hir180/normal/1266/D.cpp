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

const ll mod = 1000000007;
int n,m;
ll deg[100005];
vector<pair<ll,int>>L,R;
vector<pair<ll,P>>ans;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b; ll c; scanf("%d%d%lld",&a,&b,&c);
		deg[a]+=c;
		deg[b]-=c;
	}
	repn(i,n){
		if(deg[i] > 0) L.pb(mp(deg[i],i));
		else if(deg[i] < 0) R.pb(mp(-deg[i],i));
	}
	int id=0,id2=0;
	while(L.size()>id && R.size()>id2){
		ll V = min(L[id].fi,R[id2].fi);
		int x = L[id].sc, y = R[id2].sc;
		ans.pb(mp(V,mp(x,y)));
		if(L[id].fi == V) id++; else L[id].fi -= V;
		if(R[id2].fi == V) id2++; else R[id2].fi -= V;
	}
	printf("%d\n",ans.size());
	rep(i,ans.size()) printf("%d %d %lld\n",ans[i].sc.fi,ans[i].sc.sc,ans[i].fi);
}