#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<cstdio>
#define re register
const int M=1e9+7,iv=M+1>>1;
int a[3002],n,q,m;
double f[3002][3002],ans;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline double div2(re double x){return x/2;}
int main(){
	n=read(),q=read(),m=1;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)f[i][j]=a[i]>a[j];
	while(q--){
		re int x=read(),y=read();
		f[x][y]=f[y][x]=div2(f[x][y]+f[y][x]);
		for(re int i=1;i<=n;++i){
			if(i==x||i==y)continue;
			f[x][i]=f[y][i]=div2(f[x][i]+f[y][i]);
			f[i][x]=f[i][y]=div2(f[i][x]+f[i][y]);
		}
	}
	for(re int i=1;i<=n;++i)for(re int j=i+1;j<=n;++j)ans+=f[i][j];
	printf("%.6lf",ans);
}