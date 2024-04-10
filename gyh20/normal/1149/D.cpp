#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,A,B,fa[72],X[402],Y[402],W[402],sz[202],pos[202],tot,f[72][1<<18],g[72][72];
inline void gmn(re int&x,re int y){y<x&&(x=y);}
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
int main(){
	n=read(),m=read(),A=read(),B=read(),memset(f,0x3f,sizeof(f)),memset(g,0x3f,sizeof(g));
	for(re int i=1;i<=n;++i)g[i][i]=0;
	for(re int i=1;i<=m;++i)X[i]=read(),Y[i]=read(),W[i]=read();
	for(re int i=1;i<=m;++i)X[i+m]=Y[i],Y[i+m]=X[i],W[i+m]=W[i];
	for(re int i=1;i<=n;++i)fa[i]=i;
	for(re int i=1;i<=m;++i)if(W[i]==A)fa[root(X[i])]=root(Y[i]);
	for(re int i=1;i<=n;++i)++sz[root(i)];
	for(re int i=1;i<=n;++i)if(sz[i]>3)pos[i]=tot++;f[1][(sz[root(1)]>3)?(1<<pos[root(1)]):0]=0;m+=m;
	for(re int i=1;i<=m;++i)
		if(W[i]==A||(sz[root(Y[i])]<=3&&root(X[i])^root(Y[i])))
			g[X[i]][Y[i]]=W[i];
	for(re int k=1;k<=n;++k)
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=n;++j)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(re int k=0;k<(1<<tot);++k){
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=n;++j)
				f[j][k]=min(f[j][k],f[i][k]+g[i][j]);
		for(re int l=1;l<=m;++l){
			re int j=X[l];
			if(f[j][k]<=1000000000)
				if(W[l]==B&&sz[root(Y[l])]>3){
					re int o=pos[root(Y[l])];
					if(k&(1<<o))continue;
					gmn(f[Y[l]][k|(1<<o)],f[j][k]+B);
				}
		}
	}
	for(re int i=1;i<=n;++i){
		re int ans=1e9;
		for(re int j=0;j<(1<<tot);++j)gmn(ans,f[i][j]);
		printf("%d ",ans);
	}
}