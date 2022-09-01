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
 
 
struct SAT{
	#define maxv 2000050
	int N;
	vector<int>edge[maxv*2];
	vector<int>redge[maxv*2];
	
	int new_var(){
		assert(N < maxv);
		N++;
		return N*2-2;
	}
	
	int rev(int a){ return (a^1); }
	
	//u -> v 
	void add_edge(int u,int v){
		if(u<0||v<0) return;
		edge[u].pb(v);
		edge[rev(v)].pb(rev(u));
		redge[v].pb(u);
		redge[rev(u)].pb(rev(v));
	}
	
	//uvtrue
	int make_and(int u,int v){
		if(u<0) return v;
		if(v<0) return u;
		int ret = new_var();
		add_edge(ret,u);
		add_edge(ret,v);
		return ret;
	}
	
	//uvtrue
	int make_or(int u,int v){
		if(u<0) return v;
		if(v<0) return u;
		int ret = new_var();
		add_edge(u,ret);
		add_edge(v,ret);
		return ret;
	}
	
	//uvtrue
	int make_only(int u,int v){
		if(u<0) return v;
		if(v<0) return u;
		add_edge(u,rev(v));
		return make_or(u,v);
	}
	
	//
	//scc
	vector<int>used, vert, comp;
	int id;
	void dfs(int v){
		if(used[v]) return;
		used[v] = 1;
		for(int i=0;i<edge[v].size();i++){
			if(!used[edge[v][i]]){
				dfs(edge[v][i]);
			}
		}
		vert[id++] = v;
	}
	void sfd(int v){
		if(used[v]) return;
		used[v] = 1; comp[v] = id;
		for(int i=0;i<redge[v].size();i++){
			if(!used[redge[v][i]]){
				sfd(redge[v][i]);
			}
		}
	}
	vector<int>ans;
	bool solve(){
		used.resize(maxv*2, 0);
		vert.resize(maxv*2, 0);
		comp.resize(maxv*2, 0);
		id = 0;
		for(int i=0;i<maxv*2;i++){
			if(!used[i]){
				dfs(i);
			}
		}
		fill(used.begin(),used.end(),0);
		id = 0;
		for(int i=maxv*2-1;i>=0;i--){
			if(!used[vert[i]]){
				sfd(vert[i]);
				id++;
			}
		}
		ans.resize(maxv*2,0);
		for(int i=0;i<maxv;i++){
			if(comp[i*2] == comp[i*2+1]){
				return false;
			}
			if(comp[i*2] > comp[i*2+1]){
				ans[i*2] = 1;
			}
			else{
				ans[i*2+1] = 1;
			}
		}
		return true;
	}
}solver;
 
int n,m;
int base[10005];
vector<int>G[100005];
int dep[100005];
int up[100005][20];
int cnt[100005];
void dfs(int v,int u){
	up[v][0] = u;
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	cnt[v] = 1;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i] == u) continue;
		dfs(G[v][i],v);
		cnt[v] += cnt[G[v][i]];
	}
}
int hld_cmp[100005],hld_num[100005],hld_sz[100005];
void make_hld(int v,int u,int up,int id){
	hld_cmp[v] = up;
	hld_num[v] = id;
	hld_sz[up] = max(hld_sz[up],id);
	for(int i=0;i<G[v].size();i++){
		if(G[v][i] == u) continue;
		if(cnt[G[v][i]]*2 >= cnt[v]){
			make_hld(G[v][i],v,up,id+1);
		}
		else{
			make_hld(G[v][i],v,G[v][i],1);
		}
	}
}
struct segtree{
	vector<int>seg;
	int sz=0;
	void init(int SZ){
		while(SZ+5 >= (1<<sz)) sz++;
		seg.resize((2<<sz),-1);
	}
	void query(int a,int b,int k,int l,int r,int node){
		if(r<a || b<l) return;
		if(a<=l && r<=b){
			seg[k] = solver.make_only(seg[k],node);
			return;
		}
		query(a,b,k*2+1,l,(l+r)/2,node);
		query(a,b,k*2+2,(l+r)/2+1,r,node);
	}
	void query(int a,int b,int node){
		return query(a,b,0,0,(1<<sz)-1,node);
	}
	void final(){
		for(int i=(1<<sz)-2;i>=0;i--){
			seg[i] = solver.make_only(seg[i],solver.make_or(seg[i*2+1],seg[i*2+2]));
		}
	}
}hld[100005];
int lca(int u,int v){
	if(dep[u] > dep[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if((1<<i) <= (dep[v]-dep[u])){
			v = up[v][i];
		}
	}
	if(u == v) return u;
	for(int i=19;i>=0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int u,v; scanf("%d%d",&u,&v);
		G[u].pb(v); G[v].pb(u);
	}
	dfs(1,-1);
	rep(j,19){
		for(int i=1;i<=n;i++){
			if(up[i][j] == -1) up[i][j+1] = -1;
			else up[i][j+1] = up[up[i][j]][j];
		}
	}
	make_hld(1,-1,1,1);
	for(int i=1;i<=n;i++){
		if(hld_sz[i] == 0) continue;
		hld[i].init(hld_sz[i]);
	}
	scanf("%d",&m);
	
	for(int i=1;i<=m;i++){
		base[i] = solver.new_var(); 
		//base[i] -> 1
		int p,q,r;
		scanf("%d%d",&p,&q);
		r = lca(p,q); //cout << r  << endl;
		while(r != p){
			int upp = hld_cmp[p], nxt;
			if(dep[r]<dep[upp]){
				hld[upp].query(0,hld_num[p]-1,base[i]);
				nxt = up[upp][0];
			}
			else{
				hld[upp].query(hld_num[r],hld_num[p]-1,base[i]);
				nxt = r;
			}
			p = nxt;
		}
		while(r != q){
			int upp = hld_cmp[q], nxt;
		//	cout<<q << " " << r << " d " << upp << endl;
			if(dep[r]<dep[upp]){
				hld[upp].query(0,hld_num[q]-1,base[i]);
		//		cout << 0 << " " << hld_num[q]-1 << " " << base[i] << endl;
				nxt = up[upp][0];
			}
			else{
				hld[upp].query(hld_num[r],hld_num[q]-1,base[i]);
	//			cout << hld_num[r] << " " << hld_num[q]-1 << " " << base[i] << endl;
				nxt = r;
			}
			q = nxt;
		}
		
		base[i] = solver.rev(base[i]); //cout << base[i] << endl;
		scanf("%d%d",&p,&q);
		r = lca(p,q);
		while(r != p){
			int upp = hld_cmp[p], nxt;
			if(dep[r]<dep[upp]){
				hld[upp].query(0,hld_num[p]-1,base[i]);
			//	cout << 0 << " " << hld_num[p]-1 << " " << base[i] << endl;
				nxt = up[upp][0];
			}
			else{
				hld[upp].query(hld_num[r],hld_num[p]-1,base[i]);
		//		cout << hld_num[r] << " " << hld_num[p]-1 << endl;
				nxt = r;
			}
			p = nxt;
		}
		while(r != q){
			int upp = hld_cmp[q], nxt;
			if(dep[r]<dep[upp]){
				hld[upp].query(0,hld_num[q]-1,base[i]);
			//	cout << 0 << " " << hld_num[q]-1 << " " << base[i] << endl;
				nxt = up[upp][0];
			}
			else{
				hld[upp].query(hld_num[r],hld_num[q]-1,base[i]);
			//	cout << hld_num[r] << " " << hld_num[q]-1 << " " << base[i] << endl;
				nxt = r;
			}
			q = nxt;
		}
		
		base[i] = solver.rev(base[i]);
		
	}
	for(int i=1;i<=n;i++){
		if(hld_sz[i] == 0) continue;
		hld[i].final();
	}
	
	if(solver.solve()){
		puts("YES");
		for(int i=1;i<=m;i++){
			printf("%d\n",2-solver.ans[base[i]]);
		}
	}
	else{
		puts("NO");
	}
}