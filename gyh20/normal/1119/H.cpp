#include<bits/stdc++.h>
#define re register
#define int unsigned int
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
	}return s;
}
int n,m,f1[1<<20],f2[1<<20],f3[1<<20],k,X,Y,Z,O,f[1<<20];
inline int Mod(re int x){return x>=M?x-M:x;}
inline void FWT(re int*f,re int n){
	for(re int i=1;i<n;i<<=1)
		for(re int j=i;j<n;++j)
			if(j&i){
				re int x=f[j^i],y=f[j];
				f[j^i]=y+x,f[j]=x-y;
			}
}
inline void IFWT(re int*f,re int n){
	for(re int i=1;i<n;i<<=1)
		for(re int j=i;j<n;++j)
			if(j&i){
				re int x=f[j^i],y=f[j];
				f[j^i]=Mod(y+x),f[j]=Mod(x-y+M);
			}
	re int iv=ksm(n,M-2);
	for(re int i=0;i<n;++i)f[i]=1ll*f[i]*iv%M;
} 
signed main(){
	n=read(),m=0,k=1<<read(),X=read()%M,Y=read()%M,Z=read()%M; 
	for(re int i=1;i<=n;++i){
		re int x=read(),y=read(),z=read();
		y^=x,z^=x,O^=x,++f1[y],++f2[z],++f3[y^z];
	}
	FWT(f1,k),FWT(f2,k),FWT(f3,k);
	for(re int i=0;i<k;++i){
		re int a=(n+f1[i]+f2[i]+f3[i])>>2,b=(n-a-a+f1[i])>>1,c=(n-a-a+f2[i])>>1,d=(n-a-a+f3[i])>>1;
		f[i]=(1ll*ksm(X+Y+Z,a)*ksm(X+Y-Z+M,b)%M*ksm(X-Y+Z+M,c)%M*ksm(X-Y-Z+M+M,d)%M+M)%M;
	}
	IFWT(f,k);
	for(re int i=0;i<k;++i)printf("%u ",f[i^O]);
}