#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 433
const int inf=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
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
int n,m,a[N][N],L[N][N],R[N][N],cnt,S,T,tot,black;
char mp[N][N];
int head[N*N],dep[N*N];
struct Edge{
	int nxt,to,val;
}edge[N*N<<2];
void Add(int a,int b,int c){
	edge[++cnt]={head[a],b,c};
	head[a]=cnt;
}
void adde(int a,int b,int c){
	Add(a,b,c),Add(b,a,0);
}
bool bfs(){
	memset(dep,0,sizeof(dep));
	dep[S]=1;
	queue<int> q;
	q.push(S);
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
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(dep[v]==dep[u]+1&&edge[i].val){
			int k=dfs(v,min(edge[i].val,limit));
			edge[i].val-=k;
			edge[i^1].val+=k;
			limit-=k;
			flow+=k;
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
int main(){
	n=read(),m=read(),S=400*400+1,T=S+1,cnt=1;
	for(int i=1;i<=n;++i){
		scanf("%s",mp[i]+1);
		for(int j=1;j<=m;++j){
			a[i][j]=(mp[i][j]=='#');
			black+=a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!a[i][j])continue;
			if(a[i+1][j])L[i][j]=++tot,adde(S,L[i][j],1);
			if(a[i][j+1])R[i][j]=++tot,adde(R[i][j],T,1);
			if(L[i][j]&&R[i][j])adde(L[i][j],R[i][j],1);
			if(L[i][j]&&R[i][j-1])adde(L[i][j],R[i][j-1],1);
			if(L[i-1][j]&&R[i][j])adde(L[i-1][j],R[i][j],1);
			if(L[i-1][j]&&R[i][j-1])adde(L[i-1][j],R[i][j-1],1);
		}
	}
	printf("%d\n",black-(tot-Dinic()));
	return 0;
}