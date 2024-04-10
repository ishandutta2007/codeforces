#include<bits/stdc++.h>
using namespace std;
#define N 400020
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
int T;
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to,val;
	}edge[N<<2];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void init(int _S,int _T){
		ecnt=1;
		for(int i=1;i<=_T;++i)head[i]=0;
		S=_S,T=_T;
	}
	queue<int> q;
	bool bfs(){
		for(int i=1;i<=T;++i)dep[i]=0;
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
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
		}
		if(!flow)dep[u]=inf;
		return flow;
	}
	int Dinic(){
		int maxflow=0;
		while(bfs()){
			maxflow+=dfs(S,inf);
		}
		return maxflow;
	}
}
int n;
char a[N],b[N];
void Solve(){
	n=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	Maxflow::init(2*n+1,2*n+2);
	for(int i=1;i<=n;++i){
		Maxflow::adde(i+n,Maxflow::T,1);
		if(b[i]=='1'){
			Maxflow::adde(Maxflow::S,i,1);
			if(a[i]=='0')Maxflow::adde(i,i+n,1);
			if(i>1&&a[i-1]=='1')Maxflow::adde(i,i-1+n,1);
			if(i<n&&a[i+1]=='1')Maxflow::adde(i,i+1+n,1);
		}
	}
	printf("%d\n",Maxflow::Dinic());
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}