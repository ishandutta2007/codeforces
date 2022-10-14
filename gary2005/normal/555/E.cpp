/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+20;
int n,m,q,low[MAXN],cnt,depth[MAXN],tree[MAXN],fa[MAXN][19],id[MAXN];
int val[MAXN][2];
bool vis[MAXN];
stack<int> s;
vector<int> g[MAXN];
void dfs(int now,int pre,int deep=1){
	s.push(now);
	depth[now]=deep;
	vis[now]=1;
	low[now]=now;
	for(auto it:g[now]){
		if(it!=pre)
		{
			if(vis[it]){
				if(depth[it]<depth[low[now]]) low[now]=it;
			}
			else{
				dfs(it,now,deep+1);
				if(depth[low[it]]<depth[low[now]]) low[now]=low[it];
			}	
		}
		else pre=0;
	}
	if(low[now]==now){
		cnt++;
		while(!s.empty()){
			int index=s.top();
			s.pop();
			id[index]=cnt;
			if(index==now) break;
		} 
	}
}
void dfs2(int now,int pre,int deep=0){
	depth[now]=deep;
	fa[now][0]=pre;
	rb(i,1,18)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	tree[now]=cnt;
	for(auto it:g[now]){
		if(it!=pre)
		{
			dfs2(it,now,deep+1);
		}
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	rl(i,18,0)
	if(fa[v][i]&&depth[fa[v][i]]>=depth[u]) v=fa[v][i];
	if(u==v) return v;
	rl(i,18,0) if(fa[u][i]&&fa[v][i]&&fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void calc(int now,int pre){
	for(auto it:g[now]){
		if(it!=pre){
			calc(it,now);
			val[now][0]+=val[it][0];
			val[now][1]+=val[it][1];
		}
	}
	if(val[now][0]&&val[now][1]){
		cout<<"No"<<endl;
		exit(0);
	}
}
int main(){
	fastio;
	cin>>n>>m>>q;
	vector<mp> edges;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		edges.PB(II(u,v));
		g[u].PB(v);
		g[v].PB(u);
	}
	rb(i,1,n) if(!vis[i]) dfs(i,0);
	rb(i,1,n) g[i].clear();
	rep(i,m){
		int u,v;
		u=edges[i].FIR;
		v=edges[i].SEC;
		u=id[u];
		v=id[v];
		if(u!=v)
		g[u].PB(v),g[v].PB(u);
	}
	n=cnt;
	rb(i,1,n) {
		sort(ALL(g[i]));
		g[i].erase(unique(ALL(g[i])),g[i].end());
	}
	cnt=0;
	rb(i,1,n){
		if(!tree[i]){
			cnt++;
			dfs2(i,0);	
		}
	}
	rb(i,1,q){
		int u,v;
		R2(u,v);
		u=id[u];
		v=id[v];
		assert(u>=0);
		assert(v>=0);
		if(tree[u]!=tree[v]){
			cout<<"No";
			return 0;
		}
		int L=lca(u,v);
		val[u][0]++;
		val[v][1]++;
		val[L][0]--;
		val[L][1]--;
	}
	rb(i,1,n){
		if(fa[i][0]==0){
			calc(i,0);
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}