#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 300030
const ll mod=998244353;
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
ll dp[N][2][2];
int n,cnt,head[N];
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
	dp[u][1][0]=dp[u][1][1]=1;
	ll tmp=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
		dp[u][1][0]=dp[u][1][0]*(dp[v][0][0]+dp[v][0][1]+dp[v][1][0]+dp[v][1][1])%mod;
		dp[u][1][1]=dp[u][1][1]*(dp[v][0][0]+dp[v][0][1]+dp[v][1][0])%mod;
		tmp=tmp*(dp[v][0][0]+dp[v][0][1])%mod;
	}
	dp[u][0][1]=(dp[u][1][1]-tmp+mod)%mod;
	dp[u][0][0]=dp[u][1][0];
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%lld\n",(dp[1][0][0]+dp[1][0][1]-1+mod)%mod);
	return 0;
}