#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
} 
int n,m,t,a[100002],mx,ans,cnt,du[200002],rt,dp[200002],num,head[200002];
struct edge{
	int to,next;
}e[200002];
inline void add(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
inline int dfs(re int x,re int y,re int z){
	if(du[x]==1){
		ans+=z;
		++num;dp[x]=-1;
		return 1;
	}dp[x]=0;re int nnn=0;
	for(re int i=head[x];i;i=e[i].next){
	if(e[i].to^y){
		

	nnn|=dfs(e[i].to,x,z^1),dp[x]+=dp[e[i].to]+1;}}
	if(nnn)++dp[x];
	return 0;
}
signed main(){
	n=read();
	for(re int i=1,x,y;i<n;++i){
		x=read();y=read();++du[x];++du[y];
		add(x,y);add(y,x);
	}
	for(re int i=1;i<=n;++i)if(du[i]>1)rt=i;
	dfs(rt,rt,1);
	printf("%d %d\n",ans%num?3:1,dp[rt]);
}