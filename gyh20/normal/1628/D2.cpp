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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,f[2002][2002],k,fac[1000002],inv[1000002];
inline int C(re int n,re int m){
	if(n<m)return 0;
	return 1ll*fac[n]*inv[m]%M*inv[n-m]%M;
} 
int main(){
	t=read();
	n=1e6;
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M; 
	while(t--){
		n=read(),m=read(),k=read(),m=n-m;
		if(m==0){
			printf("%lld\n",1ll*n*k%M);
			continue;
		}
		re int ans=0;
			for(re int j=1;j<n;++j)
				add(ans,1ll*ksm((M+1>>1),n-j)*C(n-j-1,m-1)%M*k%M*j%M);
		printf("%d\n",ans);
	}
}