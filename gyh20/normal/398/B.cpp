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
double f[2002][2002];
int h[2002],z[2002],n,m,a,b;
int main(){
	n=read(),m=read(),a=b=n;
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read();
		if(!h[x])h[x]=1,--a;
		if(!z[y])z[y]=1,--b;
	}
	for(re int i=1;i<=n;++i)f[i][0]=f[0][i]=f[i-1][0]+1.0*n/i;
	for(re int i=1;i<=a;++i)for(re int j=1;j<=b;++j)f[i][j]=(n*n+f[i-1][j]*i*(n-j)+f[i][j-1]*j*(n-i)+f[i-1][j-1]*i*j)/(i*n+j*n-i*j);
	printf("%.6lf",f[a][b]);
}