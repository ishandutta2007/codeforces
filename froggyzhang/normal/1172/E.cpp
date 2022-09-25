#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
int n,m,c[N];
ll ans[N];
vector<pair<int,int> > q[N];
vector<int> G[N];
class Link_Cut_Tree{
	struct node{
		int ch[2],fa,c,sz,sl,sr,cnt;
		ll s2,val[2];
	}t[N];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline void Connect(int x,int fa,int p){t[x].fa=fa,t[fa].ch[p]=x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline int Get(int x){return t[t[x].fa].ch[1]==x;}
	inline void update(int x){
		t[x].cnt=t[ls].cnt+t[rs].cnt+t[x].c;
		t[x].sr=t[rs].sr+(t[rs].cnt||t[x].c?0:t[x].sz+1+t[ls].sr);
		t[x].sl=t[ls].sl+(t[ls].cnt||t[x].c?0:t[x].sz+1+t[rs].sl);
		t[x].s2=t[ls].s2+t[rs].s2+t[x].val[t[x].c];
		if(!t[x].c)t[x].s2+=2*(1LL*t[ls].sr*t[rs].sl+1LL*(t[x].sz+1)*(t[ls].sr+t[rs].sl));
	}
	inline void Rotate(int x){	
		int fa=t[x].fa,gfa=t[fa].fa;
		int d1=Get(x),d2=Get(fa);	
		if(!IsRoot(fa))Connect(x,gfa,d2);
		else t[x].fa=gfa;
		Connect(t[x].ch[d1^1],fa,d1);
		Connect(fa,x,d1^1);
		update(fa),update(x);
	}
	void Splay(int x){
		while(!IsRoot(x)){
			int y=t[x].fa;
			if(!IsRoot(y)){
				Rotate(Get(x)^Get(y)?x:y);
			}
			Rotate(x);
		}	
	}
	void Access(int x){
		for(int y=0;x;y=x,x=t[x].fa){
			Splay(x);
			t[x].val[0]+=t[rs].s2+2LL*t[rs].sl*(t[x].sz+1);
			t[x].val[1]+=t[rs].s2;
			t[x].sz+=t[rs].sl;
			rs=y;
			t[x].sz-=t[rs].sl;
			t[x].val[0]-=t[rs].s2+2LL*t[rs].sl*(t[x].sz+1);
			t[x].val[1]-=t[rs].s2;
			update(x);
		}
	}
	void dfs(int u,int fa){
		t[u].fa=fa;
		t[u].val[0]=1;
		for(auto v:G[u]){
			if(v==fa)continue;
			dfs(v,u);
			t[u].val[0]+=t[v].s2+2LL*t[v].sl*(t[u].sz+1);
			t[u].val[1]+=t[v].s2;
			t[u].sz+=t[v].sl;
		}
		update(u);
	}
public:
	void Change(int x){
		Access(x),Splay(x);
		t[x].c^=1;
		update(x);
	}
	ll get_ans(){
		Splay(1);
		return t[1].s2;	
	}
	void init(){
		dfs(1,0);	
	}
}T;
set<int> S;
void Solve(int col){
	for(auto x:S){
		T.Change(x);	
	}
	S.clear();
	ll las=1LL*n*n;
	ans[0]+=las;
	for(int i=0;i<(int)q[col].size();++i){
		auto [t,u]=q[col][i];
		if(u<0)u=-u,S.erase(u);
		else S.insert(u);
		T.Change(u);
		ll w=T.get_ans();
		ans[t]+=w-las;
		las=w;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		q[c[i]].emplace_back(0,i);
	}
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	T.init();
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		q[c[x]].emplace_back(i,-x);
		q[c[x]=y].emplace_back(i,x);
	}
	for(int i=1;i<=n;++i){
		Solve(i);
	}
	for(int i=1;i<=m;++i){
		ans[i]+=ans[i-1];
	}
	for(int i=0;i<=m;++i){
		cout<<1LL*n*n*n-ans[i]<<'\n';
	}
	return 0;
}