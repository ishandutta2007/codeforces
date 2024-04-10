#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,f[602][602],g[602],v[602];
signed main(){
	n=read(),m=read();
	memset(f,0x3f,sizeof(f));
	for(re int i=1,x,y,z;i<=m;++i){
		x=read(),y=read(),z=read();
		f[x][y]=min(f[x][y],z);
	}
	for(re int i=0;i<n;++i){
		memset(g,0x3f,sizeof(g));
		memset(v,0,sizeof(v));
		for(re int k=0;k<n;++k)g[k]=min(g[k],f[i][k]);
		for(re int ii=0;ii<n;++ii){
			re int mn=1e18,pos=0;
			for(re int j=0;j<n;++j)if((g[j]<mn)&&(!v[j]))mn=g[j],pos=j;
			v[pos]=1;
			re int o=mn;
			g[(pos+1)%n]=min(g[(pos+1)%n],o+1);
			for(re int k=0;k<n;++k){
				re int To=(k+mn)%n;
				g[To]=min(g[To],g[pos]+f[pos][k]);
			}
		}
		for(re int j=0;j<n;++j)printf("%lld ",i==j?0:g[j]);
		puts("");
	}
}