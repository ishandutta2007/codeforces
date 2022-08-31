#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
int n,m,f[3002][3002],g[3002],sum[3002][3002],c[3002][3002],head[3002],cnt,ans,C;
struct edge{int to,next;}e[6002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void dfs(re int x){
	for(re int i=1;i<=n;++i)f[x][i]=1;
	for(re int i=head[x];i;i=e[i].next){
		dfs(e[i].to);
		for(re int j=1;j<=n;++j)f[x][j]=1ll*f[x][j]*sum[e[i].to][j]%M;
	}
	for(re int i=1;i<=n;++i)sum[x][i]=sum[x][i-1],add(sum[x][i],f[x][i]);
}
int main(){
	n=read(),m=read();
	for(re int i=2;i<=n;++i)addd(read(),i);
	dfs(1);
	for(re int i=c[0][0]=1;i<=n;++i)for(re int j=c[i][0]=1;j<=i;++j)c[i][j]=c[i-1][j-1],add(c[i][j],c[i-1][j]);
	for(re int i=1;i<=n;++i){
		g[i]=f[1][i];
		for(re int j=1;j<i;++j)add(g[i],M-1ll*c[i-1][j-1]*g[j]%M);
	}
	C=1;
	for(re int i=1;i<=min(n,m);++i){
		C=1ll*C*ksm(i,M-2)%M;
		re int tmp=C;
		for(re int j=m-i+1;j<=m;++j)tmp=1ll*tmp*j%M;
		add(ans,1ll*g[i]*tmp%M);
	}
	printf("%d",ans);
}