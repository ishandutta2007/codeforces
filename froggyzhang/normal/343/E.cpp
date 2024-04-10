#include<bits/stdc++.h>
using namespace std;
#define N 1010
const int inf=0x3f3f3f3f; 
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N],pre[N];
	struct Edge{
		int nxt,to,val;
	}edge[N<<3];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void ST(int _S,int _T){
		S=_S,T=_T;
	}
	void init(int _S,int _T){
		ecnt=1;
		memset(head,0,sizeof(head));
		S=_S,T=_T;
	}
	queue<int> q;
	bool bfs(){
		memset(dep,0,sizeof(dep));
		q.push(S);
		dep[S]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].val&&!dep[v]){
					dep[v]=dep[u]+1;
					q.push(v);
				}
			}
		}
		return dep[T]>0;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		for(int &i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
			if(!limit)break;
		}
		if(!flow)dep[u]=inf;
		return flow;
	}
	void prepare(){
		for(int i=2;i<=ecnt;i+=2){
			edge[i].val+=edge[i^1].val;
			edge[i^1].val=0;
		}
	}
	int Dinic(){
		prepare();
		memcpy(pre,head,sizeof(pre));
		int maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
			memcpy(head,pre,sizeof(pre));
		}
		return maxflow;
	}
}
int n,m,vis[N],ecnt,ans,rt,head[N];
vector<int> all,qwq;
struct Edge{
	int nxt,to,val;
}edge[N<<2];
void add(int a,int b,int c){
	edge[++ecnt]={head[a],b,c};
	head[a]=ecnt;
}
void build(vector<int> &vec){
	if(vec.size()==1)return;
	int u=vec[0],v=vec[1];
	Maxflow::ST(u,v);
	int flow=Maxflow::Dinic();
	add(u,v,flow),add(v,u,flow);
	ans+=flow;
	vector<int> A,B;
	for(auto x:vec){
		if(Maxflow::dep[x])B.push_back(x);
		else A.push_back(x);
	}
	build(A),build(B);
}
void Find(int u,int fa){
	for(int i=head[u];i;i=edge[i].nxt){		
		int v=edge[i].to;
		if(vis[i]||v==fa)continue;
		if(!rt||edge[i].val<edge[rt].val)rt=i;
		Find(v,u);
	}
}
void Solve(int md){
	int x=edge[md].to;
	int y=edge[md^1].to;
	vis[md]=vis[md^1]=1;
	rt=0;
	Find(x,y);
	if(!rt)qwq.push_back(x);
	else Solve(rt);
	rt=0;
	Find(y,x);
	if(!rt)qwq.push_back(y);
	else Solve(rt);
}
int main(){
	n=read(),m=read();
	Maxflow::init(0,0);
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		Maxflow::adde(u,v,w);
		Maxflow::adde(v,u,w);
	}
	for(int i=1;i<=n;++i)all.push_back(i);
	ecnt=1;
	build(all);
	Find(1,0);
	Solve(rt);
	printf("%d\n",ans);
	for(auto x:qwq)printf("%d ",x);
	printf("\n");
	return 0;
}