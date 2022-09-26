#include<bits/stdc++.h>
using namespace std;
#define N 855
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3fll;
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
		int nxt,to;
		ll val;
	}edge[N*N<<2];
	void add(int a,int b,ll c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,ll c){
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
	ll dfs(int u,ll limit){
		if(u==T)return limit;
		ll flow=0;
		for(int &i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				ll k=dfs(v,min(limit,edge[i].val));
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
	ll Dinic(){
		memcpy(pre,head,sizeof(pre));
		ll maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,infll);
			memcpy(head,pre,sizeof(pre));
		}
		return maxflow;
	}
}
ll all;
int n;
int main(){
	n=read();
	Maxflow::init(2*n+1,2*n+2);
	for(int i=1;i<=n;++i){
		Maxflow::adde(i+n,Maxflow::T,inf);
		int k=read();
		while(k--){
			int x=read();
			Maxflow::adde(i,x+n,infll);
		}
	}
	for(int i=1;i<=n;++i){
		int w=-read();
		all+=inf+w;
		Maxflow::adde(Maxflow::S,i,inf+w);
	}
	printf("%lld\n",-(all-Maxflow::Dinic()));
	return 0;
}