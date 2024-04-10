#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,f[N];
ll dis[N];
vector<pair<ll,ll> > G[N],P;
class Link_Cut_Tree{
	struct node{
		int ch[2];
		int fa,cov,tim;	
		inline void Cover(int d){
			cov=tim=d;
		}
	}t[N];
	#define ls t[x].ch[0]
	#define rs t[x].ch[1]
	inline int Get(int x){return t[t[x].fa].ch[1]==x;}
	inline bool IsRoot(int x){return t[t[x].fa].ch[0]^x&&t[t[x].fa].ch[1]^x;}
	inline void Connect(int x,int fa,int p){t[x].fa=fa,t[fa].ch[p]=x;}
	inline void pushdown(int x){
		if(t[x].cov){
			t[ls].Cover(t[x].cov);
			t[rs].Cover(t[x].cov);
			t[x].cov=0;
		}	
	}
	inline void Rotate(int x){
		int fa=t[x].fa,gfa=t[fa].fa;
		int d1=Get(x),d2=Get(fa);
		if(!IsRoot(fa))Connect(x,gfa,d2);
		else t[x].fa=gfa;
		Connect(t[x].ch[d1^1],fa,d1);
		Connect(fa,x,d1^1);
	}
	void Splay(int x){
		static int st[N],top;
		int y=x;
		st[top=1]=y;
		while(!IsRoot(y))y=t[y].fa,st[++top]=y;
		while(top)pushdown(st[top--]);
		while(!IsRoot(x)){
			int y=t[x].fa;
			if(!IsRoot(y)){
				Rotate(Get(x)^Get(y)?x:y);
			}
			Rotate(x);
		}	
	}
public:
	void init(){
		for(int x=2;x<=n;++x){
			t[x].fa=f[x];
		}
		for(int x=1;x<=n;++x){
			if(!G[x].empty())rs=G[x].back().first;
		}
	}
	void Access(int x,int _t){
		int jb=x;
		for(int y=0;x;y=x,x=t[x].fa){
			Splay(x);
			if(y){
				P.emplace_back(!t[x].tim?1:t[x].tim+dis[x]+1,_t+dis[x]);
				rs=y;
			}
		}
		x=jb;
		Splay(x);
		t[ls].Cover(_t);
	}
}T;
void dfs(int u){
	for(auto [v,w]:G[u]){
		f[v]=u;
		dis[v]=dis[u]+w;
		dfs(v);	
	}
}
vector<bool> vis;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
	}
	dfs(1);
	T.init();
	while(m--){
		int s,t;
		cin>>s>>t;
		T.Access(s,t);	
	}
	ll now=1;
	int j=0;
	sort(P.begin(),P.end());
	vis.resize(P.size());
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	while(true){
		auto Insert=[&](ll t)->void{
			while(j<(int)P.size()&&P[j].first==t){
				q.emplace(P[j].second,j);
				++j;
			}
		};
		while(!q.empty()){
			int u=q.top().second;
			vis[u]=1;
			q.pop();
			if(now>P[u].second){
				int ans=0;
				for(int i=0;i<(int)P.size();++i){
					if(vis[i]&&P[i].second<P[u].second)++ans;
				}
				cout<<P[u].second<<' '<<ans<<'\n';
				return 0;
			}	
			++now;
			Insert(now);
		}
		if(j==P.size())break;
		now=max(now,P[j].first);
		Insert(now);
	}
	cout<<-1<<' '<<P.size()<<'\n';
	return 0;
}