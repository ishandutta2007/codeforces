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
int n,fac[100002],inv[100002],m,a[100002],I[100002],ans,b[100002],c[100002],sum,f[100002];
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void mul(re int x){
	for(re int i=n;i;--i)add(b[i],1ll*b[i-1]*x%M);
}
int main(){
	n=read(),m=read(),b[0]=1;
	for(re int i=1;i<=n;++i)a[i]=read(),mul(a[i]),add(sum,a[i]);
	for(re int i=fac[0]=1;i<=n+1;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	for(re int i=1;i<=n;++i)I[i]=1ll*inv[i]*fac[i-1]%M;
	for(re int i=n-1;~i;--i)(f[i]=((n-i)&1)?1ll*ksm(ksm(n,n-i-1),M-2)%M:M-1ll*ksm(ksm(n,n-i-1),M-2)%M);
	re int ss=m;
	for(re int i=n-1;~i;--i){
		add(ans,1ll*ss*f[i]%M*b[i]%M);
		ss=1ll*ss*(m-n+i)%M;
	}
	printf("%lld",1ll*ans*I[n]%M);
}