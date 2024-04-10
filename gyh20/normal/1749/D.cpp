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
int t,n,m,a[1000002],A,B,f[1000002],stk[1000002],tp,sum,X;
signed main(){
	n=read(),m=read();A=m;
	for(re int i=2;i<=n;++i)for(re int j=i+i;j<=n;j+=i)a[j]=1;a[1]=1;
	X=1;
	for(re int i=1;i<=n;++i){
		if(!a[i])X=min(X*i,m+1);
		f[i]=m/X;f[i]%=M;
	}m=A;
	int pro=1,ans=0;
	for(re int i=1;i<=n;++i)pro=1ll*pro*f[i]%M,add(ans,pro),add(sum,ksm(m%M,i));
	ans=Mod(sum-ans+M);
	printf("%lld",ans);
}