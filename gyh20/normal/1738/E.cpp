#include<bits/stdc++.h>
#define re register
#define int long long
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
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp,S[1000002],fac[1000002],inv[1000002];
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
char s[1000002];
signed main(){
	t=read();
	n=1e5;
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	while(t--){
		n=read(),ans=1;
		map<int,int>V;
		for(re int i=1;i<=n;++i)a[i]=read();
		S[n]=a[n];
		for(re int i=n-1;i;--i)S[i]=a[i]+S[i+1];
		for(re int i=1;i<=n;++i)++V[S[i]];
		int sum=0;S[n+1]=0;
		for(re int i=1;i<=n;++i){
			sum+=a[i];
			re int j=i;
			while(j<n&&a[j+1]==0)++j;
			for(re int k=i;k<=j;++k)--V[S[k]];
			if(sum==S[j+1]){
				ans=1ll*ans*ksm(2,j-i+1-(j==n))%M;
				break;
			}
			if(V[sum]>0){
				re int s=0;
				for(re int ii=0;ii<=min(V[sum],j-i+1);++ii)add(s,1ll*C(V[sum],ii)*C(j-i+1,ii)%M);
				ans=1ll*ans*s%M;
			}
			i=j;
		}
		printf("%lld\n",ans);
	}
}