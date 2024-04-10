#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],dep[202],siz[202],tim,dfn[202],f[202][202],fa[202];
char s[1000002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	dep[x]=dep[y]+1,siz[x]=1,dfn[x]=++tim,fa[x]=y;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x),siz[x]+=siz[e[i].to];
}
signed main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),addd(x,y),addd(y,x);
	for(re int i=0;i<=n;++i)f[0][i]=1;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j){
			f[i][j]=(1ll*ksm(2,M-2)*f[i-1][j]+1ll*ksm(2,M-2)*f[i][j-1])%M;
		}
	for(re int i=1;i<=n;++i){
		dep[i]=0,tim=0,dfs(i,i);
		for(re int j=1;j<=n;++j)
			for(re int k=j+1;k<=n;++k){
				
				if(dfn[j]>=dfn[k]&&dfn[j]<dfn[k]+siz[k])add(ans,1);
				else if(dfn[k]>=dfn[j]&&dfn[k]<dfn[j]+siz[j])continue;
				else {
					re int x=j,y=k;
					while(x^y){
						if(dep[x]>dep[y])x=fa[x];
						else y=fa[y];
					}
					add(ans,f[dep[k]-dep[x]][dep[j]-dep[x]]);	
				}
			}
	}
	printf("%lld",1ll*ans*ksm(n,M-2)%M);
}