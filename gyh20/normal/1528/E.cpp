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
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
} 
int n,m,f[1000002],ans,sum[1000002];
int main(){
	f[0]=1,sum[0]=1,n=read();
	for(re int i=1;i<=n;++i){
		f[i]=(1ll*f[i-1]*f[i-1]+f[i-1])%M*(M+1>>1)%M,add(f[i],f[i-1]);
		if(i>=2)add(f[i],1ll*f[i-1]*sum[i-2]%M);
		sum[i]=Mod(sum[i-1]+f[i]);
	}ans=f[n-1];
	add(ans,(1ll*f[n-1]*f[n-1]%M*f[n-1]+3ll*f[n-1]*f[n-1]+2ll*f[n-1])%M*ksm(6,M-2)%M);
	if(n>1)add(ans,1ll*(f[n-1]+1)*f[n-1]%M*sum[n-2]%M*(M+1>>1)%M);
	for(re int i=0;i<n-1;++i){
		add(ans,1ll*f[n-1]*f[i]%M*sum[i-1]%M);
		add(ans,1ll*f[n-1]*(f[i]+1)%M*f[i]%M*(M+1>>1)%M);
	}
	for(re int i=0;i<n;++i){
		re int s=1ll*f[n-1]*f[i]%M;
		if(i==n-1)add(s,f[n-1]),s=1ll*s*(M+1>>1)%M;
		add(ans,s);
	}add(ans,ans);add(ans,M-1);
	for(re int i=0;i<n-1;++i)add(ans,1ll*(f[i]-1)*(f[n-i-1]-f[n-i-2]+M)%M);
	printf("%d",ans);
}