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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int f[602][402],n,K,B,C[6002],inv[6002],fac[6002],g[2002];
inline int solve(re int n,re int K){
	memset(f,0,sizeof(f));
	re int ans=0;
	K=min(K,n-1),B=min(n,2*K);
	for(re int i=f[2][1]=f[0][0]=C[0]=inv[0]=fac[0]=1;i<=B;++i)C[i]=1ll*(n-i+1)*ksm(i,M-2)%M*C[i-1]%M,inv[i]=1ll*inv[i-1]*ksm(i,M-2)%M,fac[i]=1ll*fac[i-1]*i%M;
	for(re int i=3;i<=B;++i)
		for(re int j=1;j<=K;++j)
			f[i][j]=(1ll*f[i-1][j]*(i-1)+1ll*(i-1)*f[i-2][j-1])%M;
	for(re int s=0;s<=B;++s)for(re int i=0;i<=K;++i)if(s-i<=K)add(ans,1ll*C[s]*f[s][i]%M);
	return ans;
}
int main(){
	int n,K;
	n=read(),K=read();
	re int lst=1;g[0]=1;
	for(re int i=1;i<=K;++i){
		re int x=solve(n,i);
		x=(x-g[i-1]+M)%M;
		g[i]=x;
		printf("%d ",g[i]);
	}
}