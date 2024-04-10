#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int M;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ss=1;
	while(y){
		if(y&1)ss=1ll*ss*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ss;
}
int n,k,f[27][250002],fac[250002],inv[250002],ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),k=read(),M=read();
	if(n&1)return printf("%d",ksm(k,n)),0;
	for(re int i=fac[0]=1;i<=max(n,k);++i)fac[i]=1ll*i*fac[i-1]%M;
	inv[max(n,k)]=ksm(fac[max(n,k)],M-2);
	for(re int i=max(n,k)-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	f[0][0]=1;
	for(re int i=0;i+1<=k;++i)
		for(re int j=0;j<n;++j)
			if(f[i][j]){
				re int s=(n^j)&(-(n^j));
				for(re int ss=n^s^j;;ss=(ss-1)&(n^s^j)){
					re int tmp=s^ss;
					add(f[i+1][j^tmp],1ll*f[i][j]*inv[tmp]%M);
					if(!ss)break;
				}
			}
	for(re int i=0;i<=k;++i)add(ans,1ll*f[i][n]*fac[k]%M*inv[k-i]%M);
	printf("%lld",(ksm(k,n)-1ll*ans*fac[n]%M+M)%M);
}