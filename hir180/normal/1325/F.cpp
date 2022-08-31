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

int n,m;
vector<int>G[100005],edge[100005];
int dep[100005];
bool used[100005];
vector<P>ad;
int up[100005];

void dfs(int v){
	if(used[v]) return ;
	used[v] = 1;
	rep(i,G[v].size()){
		int to = G[v][i];
		if(used[to]){
			ad.pb(mp(v,to));
		}
		else{
			edge[v].pb(to);
			dfs(to);
		}
	}
}
void dfs2(int v,int u,int d){
	dep[v] = d; up[v] = u;
	rep(i,edge[v].size()) dfs2(edge[v][i],v,d+1);
}
vector<int>V[10005];
int main(){
	g(n); g(m);
	rep(i,m){
		int a,b; g(a); g(b);
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1);
	dfs2(1,-1,0);
	int lim;
	for(lim=1;lim*lim<n;lim++);
	rep(i,ad.size()){
		int a = ad[i].fi, b = ad[i].sc;
		if(dep[a] > dep[b]) swap(a,b);
		if(dep[b]-dep[a] == 1) continue;
		if(dep[b]-dep[a] >= lim-1){
			vector<int>ans;
			while(1){
				ans.pb(b);
				if(a == b){
					break;
				}
				b = up[b];
			}
			o(2);
			o(ans.size());
			for(auto at:ans) o(at);
			return 0;
		}
	}
	repn(i,n) V[dep[i]%(lim-1)].pb(i);
	rep(i,lim){
		if(V[i].size() >= lim){
		    o(1);
		    rep(x,lim) o(V[i][x]);
			return 0;
		}
	}
	assert(0);
}