#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
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
int t,n,m,a[1000002],ans,A,B,fac[1000002],inv[1000002],P[1000002],f[1000002];
char s[1000002];
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
int main(){
	n=1e6;
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	P[0]=1;
	for(re int i=2;i<=n;i+=2)P[i]=2ll*P[i-2]*(i-1)%M;
	f[0]=1;
	for(re int i=1;i<=n;++i){
		f[i]=f[i-1];
		if(i>=2)add(f[i],1ll*f[i-2]*(i-1)%M);
	}
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=0;i+i<=n;++i)
			if(i%2==0){
				re int s=1;
				s=1ll*s*P[i]%M,s=1ll*s*f[n-i-i]%M;
				s=1ll*s*C(n-i,i)%M;
				add(ans,s);
			}
		printf("%d\n",ans);
	}
}