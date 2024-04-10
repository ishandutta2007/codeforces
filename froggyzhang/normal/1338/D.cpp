#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int n,dp[N][2],ans,cnt,head[N],d[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int fa){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
		ans=max(ans,dp[u][1]+dp[v][0]+1);
		ans=max(ans,dp[u][0]+d[u]-2+max(dp[v][0],dp[v][1]));
		dp[u][0]=max(dp[u][0],max(dp[v][0],dp[v][1]));
		dp[u][1]=max(dp[u][1],dp[v][0]);
	}
	++dp[u][1];
	dp[u][0]+=max(0,d[u]-2);
	ans=max(ans,max(dp[u][0],dp[u][1]));
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
		++d[u],++d[v];
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}