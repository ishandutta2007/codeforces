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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
void dmp(vector<int>&a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
}
#define SZ 200005
vector<int>edge[200005];

P ar[SZ*2]={};
int pos[SZ]={},id=0,up[SZ],dep[SZ];
P mn[20][SZ*2]={};
int sz[SZ*2]={};
struct LCA{
	//SZ
	//edge[]
	
	void dfs(int v,int u,int d){
		pos[v] = id; up[v] = u; dep[v] = d;
		ar[id++] = mp(d,v);
		for(int i=0;i<edge[v].size();i++){
			if(edge[v][i] == u) continue;
			dfs(edge[v][i],v,d+1);
			ar[id++] = mp(d,v);
		}
	}
	void prepare(){
		dfs(1,-1,0);
		for(int i=0;i<id;i++) mn[0][i] = ar[i];
		for(int j=0;j<19;j++){
			for(int i=0;i<id;i++){
				if(i+(1<<j) >= id) mn[j+1][i] = mn[j][i];
				else mn[j+1][i] = min(mn[j][i], mn[j][i+(1<<j)]);
			}
		}
		for(int i=1;i<SZ*2;i++){
			for(int j=0;j<20;j++){
				if((1<<j) <= i && i <= (2<<j)){
					sz[i] = j;
					break;
				}
			}
		}
	}
	int get(int a,int b){
		int len = max(pos[a],pos[b]) - min(pos[a],pos[b]) + 1;
		int ty = sz[len];
		P p = min(mn[ty][min(pos[a],pos[b])], mn[ty][max(pos[a],pos[b])-(1<<ty)+1]);
		return p.second;
	}
}kaede;
//
// -> dfslca

int n,q;
int mapp[200005];
int viv[200005], imv[200005], vlen[200005];

bool cmp(const int&a, const int&b){
	return pos[a] < pos[b];
}
vector<vector<P>>G;
//impsubtree
//G[v] <- ()
//imp.size() log
void compress_tree(vector<int>imp){
	sort(imp.begin(),imp.end(),cmp);
	ERASE(imp);
	int sz = imp.size();
	rep(i,sz-1){
		imp.pb(kaede.get(imp[i], imp[i+1]));
	}
	sort(imp.begin(),imp.end(),cmp);
	ERASE(imp);
	
	int nxt = 0;
	//dmp(imp);
	for(auto a:imp) mapp[a] = nxt++;
	G.clear();
	G.resize(nxt, vector<P>());
	for(int i=1;i<nxt;i++){
		int par = kaede.get(imp[i-1],imp[i]);
		G[mapp[par]].pb(mp(mapp[imp[i]], dep[imp[i]] - dep[par]));
		G[mapp[imp[i]]].pb(mp(mapp[par], dep[imp[i]] - dep[par]));
	}
	return;
}

P1 dist[200005];
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	kaede.prepare();
	repn(i,n) mapp[i] = i;
	scanf("%d",&q);
	rep(i,q){
		int k,m; scanf("%d%d",&k,&m);
		vector<int>imp;
		rep(j,k){
			scanf("%d %d",&viv[j],&vlen[j]); imp.pb(viv[j]);
		}
		rep(j,m){
			scanf("%d",&imv[j]); imp.pb(imv[j]);
		}
		compress_tree(imp);
		int sz = G.size();
		//, virus, 
		rep(i,sz) dist[i] = mp(INF,mp(INF,INF));
		typedef pair<P1,int> PP;
		priority_queue<PP,vector<PP>,greater<PP>>que;
		
		rep(j,k){
			int x = mapp[viv[j]];
			dist[x] = mp(0,mp(j,0));
			que.push(mp(dist[x],x));
		}
		
		while(!que.empty()){
			PP sp = que.top(); que.pop();
			P1 p = sp.fi;
			int id = sp.sc;
			if(dist[id] != p) continue;
			int t = p.fi;
			int cur_len = p.sc.sc;
			rep(i,G[id].size()){
				int to = G[id][i].fi;
				if(dist[to].fi == 0 && dist[to].sc.sc == 0) continue;
				int len = G[id][i].sc;
				int addt = (cur_len+len) / vlen[p.sc.fi];
				int addl = (cur_len+len) % vlen[p.sc.fi];
				if(addl == 0){
				    addl = vlen[p.sc.fi];
				    addt --;
				}
				if(dist[to] > mp(t+addt,mp(p.sc.fi,addl))){
					dist[to] = mp(t+addt,mp(p.sc.fi,addl));
					que.push(mp(dist[to],to));
				}
			}
		}
		
		rep(j,m){
			printf("%d\n",dist[mapp[imv[j]]].sc.fi+1);
		}
	}
}