#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,p[N],cnt,head[N],dp[N];
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
	dp[u]=p[u];
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs1(v,u);
		dp[u]+=max(dp[v],0);
	}
}
void dfs2(int u,int fa){
	if(fa){
		if(dp[u]<0)dp[u]+=max(dp[fa],0);
		else dp[u]=max(dp[u],dp[fa]);
	}
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs2(v,u);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
		if(!p[i])p[i]=-1;
	}
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		printf("%d ",dp[i]);
	}
	return 0;
}