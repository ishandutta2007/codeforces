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
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],k,f[100002][42],g[100002][42];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y,re int d){
	if((d/k)&1)ans^=a[x];
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)dfs(e[i].to,x,d+1);
}
inline void dfs1(re int x,re int y){
	f[x][0]=a[x];
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs1(e[i].to,x);
			for(re int j=0;j<k*2;++j)f[x][j+1]^=f[e[i].to][j];
			f[x][0]^=f[x][k*2],f[x][k*2]=0;
		}
}
inline void dfs2(re int x,re int y){
	if(y){
	for(re int j=0;j<k*2;++j)g[x][j+1]^=g[y][j];
	g[x][0]^=g[x][k*2],g[x][k*2]=0;
	g[x][1]^=a[y];
	for(re int j=0;j<k*2;++j)f[y][j+1]^=f[x][j];
	f[y][0]^=f[y][k*2],f[y][k*2]=0;
	for(re int j=0;j<k*2;++j)g[x][j+1]^=f[y][j];
	g[x][0]^=g[x][k*2],g[x][k*2]=0;
	for(re int j=0;j<k*2;++j)f[y][j+1]^=f[x][j];
	f[y][0]^=f[y][k*2],f[y][k*2]=0;
	}
	g[x][0]^=a[x];
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs2(e[i].to,x);
}
signed main(){
	n=read(),k=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	for(re int i=1;i<=n;++i)a[i]=read();
	dfs1(1,1),dfs2(1,0);
	for(re int i=1;i<=n;++i){
		ans=0;
		for(re int j=k;j<k*2;++j)ans^=f[i][j]^g[i][j];
		if(ans)printf("1 ");
		else printf("0 "); 
	}
}