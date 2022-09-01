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
struct uf{
	int par[100005],ran[100005];
	set<int>S[100005];
	void init(){ for(int i=0;i<100005;i++) par[i] = i; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]){
			par[x] = y;
			if(S[x].size() > S[y].size()) swap(S[x],S[y]);
			for(auto a:S[x]) S[y].insert(a);}
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
			if(S[x].size() < S[y].size()) swap(S[x],S[y]);
			for(auto a:S[y]) S[x].insert(a);
		}
	}
	void put(int x,int y){
		S[find(x)].insert(y);
	}
	bool same(int x,int y){ return find(x)==find(y); }
	bool findd(int x,int y){
		x = find(x);
		return S[x].find(y) != S[x].end();
	}
}kaede;
int n,m,c,q;
set<P>edge[100005];
vector<P>G[100005];
int rev[100005];
int main(){
	scanf("%d%d%d%d",&n,&m,&c,&q);
	kaede.init();
	for(int i=0;i<m;i++){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge[a].insert(mp(c,b));
		edge[b].insert(mp(c,a));
		G[a].pb(mp(c,b));
		G[b].pb(mp(c,a));
	}
	memset(rev,-1,sizeof(rev));
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			int to = G[i][j].sc;
			kaede.put(i,to);
		}
	}
	for(int i=1;i<=n;i++){
		SORT(G[i]);
		for(int j=1;j<G[i].size();j++){
			if(G[i][j-1].fi == G[i][j].fi){
				kaede.unite(G[i][j-1].sc,G[i][j].sc); //cout << G[i][j-1].sc << " " << G[i][j].sc << endl;
			}
		}
	}
	for(int i=0;i<q;i++){
		char ch; scanf(" %c",&ch);
		if(ch == '+'){
			int x,y,z; scanf("%d%d%d",&x,&y,&z);
			auto it = edge[x].lower_bound(mp(z,-1));
			if(it != edge[x].end() && (*it).fi == z){
				kaede.unite((*it).sc,y);
			}
			it = edge[y].lower_bound(mp(z,-1));
			if(it != edge[y].end() && (*it).fi == z){
				kaede.unite((*it).sc,x);
			}
			edge[x].insert(mp(z,y));
			edge[y].insert(mp(z,x));
			G[x].pb(mp(z,y));
			G[y].pb(mp(z,x));
			kaede.put(x,y);
			kaede.put(y,x);
		}
		else{
			int x,y; scanf("%d%d",&x,&y);
			if(kaede.same(x,y) || kaede.findd(x,y)){
				puts("Yes");
			}
			else{
				puts("No");
			}
		}
	}
}