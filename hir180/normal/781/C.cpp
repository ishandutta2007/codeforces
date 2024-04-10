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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,k;
vector<int>edge[200005];
int par[200005],ran[200005];
void init(){ for(int i=0;i<200005;i++) par[i] = i; }
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
vector<int>L;
void dfs(int v,int u){
	L.pb(v);
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v); L.pb(v);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k); 
	init();
	for(int i=0;i<m;i++){
		int x,y; scanf("%d%d",&x,&y);
		if(!same(x,y)){
			unite(x,y);
			edge[x].pb(y);
			edge[y].pb(x);
		}
	}
	dfs(1,-1); 
	int ok = (2*n+k-1)/k;
	int nxt = 0;
	for(int i=0;i<k;i++){
		if(nxt+ok < L.size()){
			printf("%d ",ok);
			for(int j=nxt;j<nxt+ok;j++){
				printf("%d ",L[j]);
			}
			puts("");
			nxt += ok;
		}
		else if(nxt<L.size()){
			printf("%d ",L.size()-nxt);
			for(int j=nxt;j<L.size();j++){
				printf("%d ",L[j]);
			}
			puts("");
			nxt = L.size();
		}
		else{
			puts("1 1");
		}
	}
	return 0;
}