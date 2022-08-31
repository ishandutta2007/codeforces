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
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
int n,m,a[1000002],fac[300002],inv[300002];
long long ans;
int main(){
	n=read()*2;
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	re int ss=1ll*fac[n]*inv[n>>1]%M*inv[n>>1]%M;
	for(re int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(re int i=1;i<=(n>>1);++i)ans-=1ll*a[i]*ss%M,ans%=M,ans+=M,ans%=M;
	for(re int i=(n>>1)+1;i<=n;++i)ans+=1ll*a[i]*ss%M,ans%=M;
	printf("%lld",ans);
}