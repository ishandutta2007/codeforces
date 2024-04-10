#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[10002];
int t,n,m,ans,cnt,head[1000002],f[5002][5002],sz[5002],g[5002],h[5002][5002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	sz[x]=1,f[x][0]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);
			memset(g,0,sizeof(g));
			for(re int k=0;k<=sz[x];++k)
			for(re int j=0;j<=sz[e[i].to]&&j+k<=m;++j)
			add(g[max(j,k)],1ll*f[e[i].to][j]*f[x][k]%M);
			sz[x]+=sz[e[i].to];
			for(re int k=0;k<=sz[x];++k)f[x][k]=g[k];
		}
	re int sum=0;
	for(re int i=0;i<=m;++i)add(sum,f[x][i]);//printf("%d %d %d\n",x,i,f[x][i]);
	for(re int i=min(m,sz[x]+1);i;--i)f[x][i]=f[x][i-1];
	f[x][0]=sum;//printf("%d %d %d\n",x,0,f[x][0]);
}
signed main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),addd(x,y),addd(y,x);
	dfs(1,1);
	printf("%d",f[1][0]);
}