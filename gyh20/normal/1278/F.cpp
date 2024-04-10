#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,A,B,fac[5002],inv[5002],k,S[5002][5002],ans;
int main(){
	n=read(),m=read(),k=read(),A=ksm(m,M-2),B=M+1-A;
	for(re int i=fac[0]=inv[0]=1;i<=k;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for(re int i=S[0][0]=1;i<=k;++i)
		for(re int j=1;j<=i;++j)
			S[i][j]=(1ll*S[i-1][j]*j+S[i-1][j-1])%M;
	for(re int i=0;i<=k&&i<=n;++i){
		re int s=1;
		for(re int j=n;j>n-i;--j)s=1ll*s*j%M;
		add(ans,1ll*S[k][i]*s%M*ksm(A,i)%M*ksm(A+B,n-i)%M);
	}
	printf("%d",ans);
}