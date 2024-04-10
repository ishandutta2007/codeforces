/* trying!*/
/* Never lose with no try*/
/* Author : SAB*/
#include "bits/stdc++.h"
using namespace std;
const int N = 1001234, LOG=20;
typedef long long int ll;
#define pb push_back
#define pii pair <int , int>
#define F first
#define S second
#define bit(x,y) ((x >> y) & 1)
#define kill(x) return cout << x << '\n', 0
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define debug(x) cerr << (#x) << ' ' << (x) << '\n'
#define debug2(x) cerr << (#x) << '{' << x.F << ' ' << x.S << '}' << ' '
#define int ll 
int n, a[N], par[N], sz[N];
ll res;
vector<pii> edge;
int Find(int v){return (par[v]==v?v:par[v]=Find(par[v]));}
void Unite(int v, int u){
	if((u=Find(u))==(v=Find(v)))
		return;
	if(sz[u]>sz[v])
		swap(u,v);
	sz[v]+=sz[u];
	par[u]=v;
}
int32_t main(){
        ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		sz[i]=1, par[i]=i;
	}
	for(int i =1; i < n;i++){
		int v, u;
		cin >> v >> u;
		edge.pb({v,u});
	}
	sort(all(edge),[](pii c, pii d){
		return (min(a[c.F],a[c.S]) > min(a[d.F],a[d.S]));
	});
	for(auto x : edge){
		int v = x.F, u = x.S;
		int w = min(a[v],a[u]);
		v = Find(v), u=Find(u);
		res -= (1ll*sz[u]*sz[v]*w);
		Unite(v,u);
	}
	for(int i = 1;i <= n;i++){
		sz[i]=1, par[i]=i;
	}
	sort(all(edge),[](pii c, pii d){
		return (max(a[c.F],a[c.S]) < max(a[d.F],a[d.S]));
	});
	for(auto x : edge){
		int v = x.F, u = x.S;
		int w = max(a[v],a[u]);
		v = Find(v), u=Find(u);
		res += (1ll*sz[u]*sz[v]*w);
		Unite(v,u);
	}
	cout << res;
}