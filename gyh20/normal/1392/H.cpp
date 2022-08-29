#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,fac[4000002],inv[4000002],I[4000002],E,f[2000002];
const int M=998244353;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int main(){n=4e6;
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;I[1]=1;
	for(re int i=2;i<=n;++i)I[i]=1ll*I[M%i]*(M-M/i)%M;
	n=read(),m=read();
	for(re int i=1;i<=n;++i)if(i&1)add(E,1ll*C(n,i)*(i+m)%M*I[i]%M);else add(E,M-1ll*C(n,i)*(i+m)%M*I[i]%M);
	f[0]=1;
	for(re int i=1;i<=n;++i)f[i]=1ll*f[i-1]*i%M*I[i+m]%M+1;
	printf("%lld",1ll*f[n]*E%M);
}