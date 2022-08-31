#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,f[82][82],M,pw[82],C[82][82],inv[82],fac[82],ans,val1[82][82][82],val2[82][82][82];
inline int Mod(re int x){return x>=M?x-M:x;}
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
inline int Comb(re int x,re int y){
	if(x<y)return 0;
	re int s=inv[y];
	for(re int i=x-y+1;i<=x;++i)s=1ll*s*i%M;
	return s;
}
int main(){
	n=read(),m=read(),M=read();
	for(re int i=pw[0]=1;i<=m;++i)pw[i]=Mod(pw[i-1]+pw[i-1]);
	for(re int i=fac[0]=inv[0]=1;i<=80;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for(re int i=C[0][0]=1;i<=80;++i)
		for(re int j=C[i][0]=1;j<=i;++j)
			C[i][j]=Mod(C[i-1][j]+C[i-1][j-1]);
	f[0][0]=1;
	for(re int i=1;i<=n;++i)
		for(re int a=0;a<=i;++a)
			for(re int b=0;b<=m;++b)
				val1[i][a][b]=1ll*C[i][a]*ksm(pw[b],i-a)%M*fac[i-a]%M*inv[b]%M,
				val2[i][a][b]=1ll*Comb(a==0?pw[b]:pw[b]-1,i-a)*inv[b]%M;
	for(re int i=1;i<=n;++i)
		for(re int j=0;j<=m;++j){
			f[i][j]=ksm(pw[j],i),f[i][j]=1ll*f[i][j]*inv[j]%M;
			for(re int a=0;a<=i;++a)
				for(re int b=0;b<j;++b){
					if(i==n&&(n&1)&&a==i-1)continue;
					if(a==1&&n!=1)continue;
					add(f[i][j],M-1ll*f[a][b]*val1[i][a][b]%M*val2[i][a][j-b]%M);
				}
			f[i][j]=1ll*f[i][j]*fac[j]%M;
			if(i==n)add(ans,1ll*C[m][j]*f[i][j]%M);
		}
	printf("%d",ans);
}