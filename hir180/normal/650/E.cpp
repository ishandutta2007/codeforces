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

struct LinkCutTree{
	struct LC_node{
		LC_node *pp,*lp,*rp; //
		int id; //
		LC_node(){
			pp = lp = rp = (LC_node *)NULL;
			id = -1;
		}
		//splay (=)
		bool is_root(){
			return !pp || (pp->lp != this && pp->rp != this);
		}
		
		//
		void rotr(){
			LC_node *q = pp, *r = q->pp;
			//rpNULL
			if((q->lp = rp)) rp->pp = q;
			rp = q; q->pp = this;
			//rNULL
			if((pp = r)){
				if(r->lp == q) r->lp = this;
				if(r->rp == q) r->rp = this;
			}
		}
		//
		void rotl(){
			LC_node *q = pp, *r = q->pp;
			//lpNULL
			if((q->rp = lp)) lp->pp = q;
			lp = q; q->pp = this;
			//rNULL
			if((pp = r)){
				if(r->lp == q) r->lp = this;
				if(r->rp == q) r->rp = this;
			}
		}
		//
		void splay(){
			while(!is_root()){
				LC_node *q = pp;
				//rootzig
				if(q->is_root()){
					if(q->lp == this){
						rotr();
					}
					else{
						rotl();
					}
				}
				else{
					LC_node *r = q->pp;
					if(r->lp == q){
						if(q->lp == this){
							//zig-zig
							q->rotr();
							rotr();
						}
						else{
							//zig-zag
							rotl();
							rotr();
						}
					}
					else{
						if(q->rp == this){
							//zig-zig
							q->rotl();
							rotl();
						}
						else{
							//zig-zag
							rotr();
							rotl();
						}
					}
				}
			}
		}
	};
	LC_node pool[500005];
	//
	//x
	LC_node *expose(int a){
		LC_node *x = &pool[a];
		LC_node *rp = (LC_node *)NULL;
		for(LC_node *p = x;p;p = p->pp){
			//splay
			p->splay();
			//
			p->rp = rp;
			//
			rp = p;
		}
		x->splay();
		//
		return x;
	}
	//c
	void cut(int a){
		LC_node *c = &pool[a];
		//cexpose
		expose(a);
		//c
		LC_node *p = c->lp;
		c->lp = NULL;
		p->pp = NULL;
	}
	//cp
	void link(int a,int b){
		LC_node *c = &pool[a];
		LC_node *p = &pool[b];
		//top
		expose(a);
		expose(b);
		//
		c->pp = p;
		p->rp = c;
	}
	//c
	int up(int a){
		LC_node *c = &pool[a];
		//cexpose
		expose(a);
		//c
		LC_node *p = c->lp;
		return p->id;
	}
	int LCA(int a,int b){
		LC_node *xU = &pool[a], *xV = &pool[b];
		expose(a); expose(b);
		LC_node *U = xU; //
		if(U->pp == (LC_node*)NULL){
			//
			return -1;
		}
		//u (todo: )
		//vuv
		//splay tree1
		while(U->pp->pp && !U->is_root()){
			U = U->pp;
		}
		//2splay tree
		if(U->is_root()){
			return U->pp->id;
		}
		//u
		else{
			return a;
		}
	}
}kaede;
int n,q;
vector<int>edge[500005];
vector<int>edge2[500005];
map<P,int>M;
vector<P1>goal;
vector<P2>ans;
int par[500005],ran[500005];
void init(){ for(int i=0;i<500005;i++) par[i] = i; }
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
void dfs(int v,int u,int d){
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,d+1); kaede.link(edge[v][i],v);
		if(find(edge[v][i]) != find(v)){
		    //cout << edge[v][i] << " " << v << endl;
			goal.pb(mp(d+1,mp(edge[v][i],v)));
		}
	}
}
int must[500005];
int from[500005];
void dfs2(int v,int u,int d){
	for(int i=0;i<edge2[v].size();i++){
		if(edge2[v][i] == u) continue;
		dfs2(edge2[v][i],v,d+1);
		if(find(edge2[v][i]) != find(v)){
			must[find(edge2[v][i])] = v;
			from[find(edge2[v][i])] = edge2[v][i];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		kaede.pool[i].id = i;
	}
	for(int i=1;i<n;i++){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
		M[mp(min(a,b),max(a,b))]++;
	}
	for(int i=1;i<n;i++){
		int a,b; scanf("%d%d",&a,&b);
		edge2[a].pb(b);
		edge2[b].pb(a);
		M[mp(min(a,b),max(a,b))]++;
	}
	init();
	for(auto it=M.begin();it!=M.end();++it){
		if(it->sc == 2){
			unite((it->fi).fi,(it->fi).sc);
		}
	}
	dfs(1,-1,0);
	dfs2(1,-1,0);
	sort(goal.begin(),goal.end(),greater<P1>());
	for(int i=0;i<goal.size();i++){
		int cur = goal[i].sc.fi, up = goal[i].sc.sc;
		int cur_name = find(cur);
		assert(must[cur_name] && from[cur_name]);
		int A = must[cur_name], B = from[cur_name];
		int now_up = kaede.up(cur);
		//(up,cur) -> (A,B)
		kaede.cut(cur);
		kaede.link(B,A);
		ans.pb(mp(mp(up,cur),mp(A,B)));
	}
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d %d %d %d\n",ans[i].fi.fi,ans[i].fi.sc,ans[i].sc.fi,ans[i].sc.sc);
	}
}