#include<cstdio>
#include<vector>
#include<cstring>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,head[300002],cnt,a[300002],sum;
long long dp[300002],ans;
struct edge{int to,next;}e[600002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs1(re int x,re int y){
	dp[x]=a[x];
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs1(e[i].to,x),dp[x]+=max(0ll,dp[e[i].to]);
	ans=max(ans,dp[x]);
}
inline void dfs2(re int x,re int y){
	dp[x]=a[x];
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs2(e[i].to,x),dp[x]+=max(0ll,dp[e[i].to]);
	if(dp[x]==ans)++sum,dp[x]=-1e18;
}
int main(){
	n=read(),ans=-1e18;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs1(1,1),dfs2(1,1);
	printf("%lld %d",ans*sum,sum);
}