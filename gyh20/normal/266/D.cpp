#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int f[202][202],n,m,inf=1e9,g[202][202],p[202],X,ans;
inline bool cmp(re int x,re int y){return f[X][x]>f[X][y];}
int main(){
	n=read(),m=read(),ans=1e9;
	for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)f[i][j]=g[i][j]=inf;
	for(re int i=1;i<=n;++i)f[i][i]=0;
	for(re int i=1;i<=m;++i){
		re int x=read(),y=read(),z=read();
		f[x][y]=f[y][x]=g[x][y]=g[y][x]=z;
	}
	for(re int k=1;k<=n;++k)for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<=n;++j)p[j]=j;
		X=i,sort(p+1,p+n+1,cmp),ans=min(ans,f[i][p[1]]<<1);
		for(re int j=i+1;j<=n;++j){
			for(re int k=2,pos=1;k<=n;++k)
				if(f[j][p[k]]>f[j][p[pos]])
					ans=min(ans,f[i][p[k]]+f[j][p[pos]]+g[i][j]),pos=k;
		}
	}
	printf("%d",ans>>1);
	if(ans&1)printf(".5");
}