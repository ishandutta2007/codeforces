#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
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
int dep[N],mxdep[N],son[N],f[N],n;
int cnt,head[N];
int ans[N],*dp[N],_dp[N<<1],*p=_dp;
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	cnt++;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs1(int u,int fa){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		mxdep[v]=dep[v]=dep[u]+1,f[v]=u;
		dfs1(v,u);
		if(mxdep[v]>mxdep[u]){
			mxdep[u]=mxdep[v],son[u]=v;
		}
	}
}
inline void Assign(int u){
	dp[u]=p;p+=mxdep[u]-dep[u]+1;
}
void dfs2(int u){
	if(son[u]){
		dp[son[u]]=dp[u]+1;
		dfs2(son[u]);
		ans[u]=ans[son[u]]+1;
	}
	dp[u][0]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==f[u]||v==son[u])continue;
		Assign(v);
		dfs2(v);
		for(int j=1;j<=mxdep[v]-dep[v]+1;++j){
			dp[u][j]+=dp[v][j-1];
			if(dp[u][j]>dp[u][ans[u]]||(dp[u][j]==dp[u][ans[u]]&&j<ans[u])){
				ans[u]=j;
			}
		}
	}
	if(dp[u][ans[u]]==1)ans[u]=0;
}

int main(){
	n=read();
	for(int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	mxdep[1]=dep[1]=1;
	dfs1(1,0);
	Assign(1);
	dfs2(1);
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}