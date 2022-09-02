#include <bits/stdc++.h>
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
int n,m;
vector<P>edge[500005];
vector<P1>E[500005];
int par[500005],ran[500005];
void init(){ for(int i=0;i<500005;i++) par[i] = i; }
void INIT(int x){ par[x] = x; ran[x] = 0; }
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
P ed[500005];int q,e[500005],cs[500005];
vector<int>zip[500005]; bool used[500005];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b,c; scanf("%d%d%d",&a,&b,&c); cs[i] = c;
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
		E[c].pb(mp(i,mp(a,b)));
	}
	init();
	for(int i=1;i<=500000;i++){
		for(int j=0;j<E[i].size();j++){
			ed[E[i][j].fi] = mp(find(E[i][j].sc.fi),find(E[i][j].sc.sc));
		}
		for(int j=0;j<E[i].size();j++){
			unite(E[i][j].sc.fi,E[i][j].sc.sc);
		}
	}
	scanf("%d",&q);
	rep(i,q){
		int k; scanf("%d",&k);
		rep(j,k){
			scanf("%d",&e[j]);e[j]--;
			zip[cs[e[j]]].clear(); used[cs[e[j]]] = 0;
		}
		rep(j,k){
			zip[cs[e[j]]].pb(e[j]);
		}
		bool bad = 0;
		rep(j,k){
			if(used[cs[e[j]]]) continue; used[cs[e[j]]] = 1;
			rep(a,zip[cs[e[j]]].size()){
				int x = zip[cs[e[j]]][a];
				if(ed[x].fi == ed[x].sc){
					bad = 1; break;
				}
				INIT(ed[x].fi); INIT(ed[x].sc);
			}
			if(bad) break;
			rep(a,zip[cs[e[j]]].size()){
				int x = zip[cs[e[j]]][a];
				{
					if(find(ed[x].fi) == find(ed[x].sc)){
						bad = 1; break;
					}
					else unite(ed[x].fi,ed[x].sc);
				}
			}
			if(bad) break;
		}
		puts(bad?"NO":"YES");
	}
}