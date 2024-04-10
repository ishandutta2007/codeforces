#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to;
		ll val;
	}edge[N<<3];
	void add(int a,int b,ll c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,ll c){
		add(a,b,c),add(b,a,0);
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
	ll dfs(int u,ll limit){
		if(u==T)return limit;
		ll flow=0;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				ll k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
		}
		if(!flow)dep[u]=-233;
		return flow;
	}
	ll Dinic(){
		ll maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
		}
		return maxflow;
	}
}
int n,now,t[N];
ll sum;
map<pair<int,int>,int> id;
const int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
	n=read();
	Maxflow::init(2*n+1,2*n+2);
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),w=read();
		id[make_pair(x,y)]=i;
		Maxflow::adde(2*i-1,2*i,w);
		if(x&1)t[i]+=1;
		if(y&1)t[i]+=2;
		if(t[i]==1)Maxflow::adde(Maxflow::S,2*i-1,inf);
		if(t[i]==3)Maxflow::adde(2*i,Maxflow::T,inf);
		sum+=w;
	}
	for(auto [pt,u]:id){
		int x=pt.first,y=pt.second;
		for(int i=0;i<4;++i){
			int nx=x+d[i][0],ny=y+d[i][1];
			if(!id.count(make_pair(nx,ny)))continue;
			int v=id[make_pair(nx,ny)];
			if(t[u]==1&&t[v]==0||t[u]==0&&t[v]==2||t[u]==2&&t[v]==3){
				Maxflow::adde(2*u,2*v-1,inf);
			}
		}
	}
	printf("%lld\n",sum-Maxflow::Dinic());
	return 0;
}