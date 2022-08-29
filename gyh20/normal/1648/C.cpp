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
int t,n,m,a[1000002],b[1000002],ans,A,B,c[200002],fac[200002],inv[200002],N[2000002],Inv[200002];
char s[1000002];
inline void Add(re int x,re int y){
	for(;x<=200000;x+=x&(-x))c[x]+=y;
}
inline int ask(re int x,re int s=0){
	for(;x;x^=x&(-x))s+=c[x];
	return s;
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read(),Add(a[i],1),++N[a[i]];
	for(re int i=1;i<=m;++i)b[i]=read();
	for(re int i=fac[0]=inv[0]=1;i<=max(n,m);++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2),Inv[i]=ksm(i,M-2);
	re int s=fac[n];
	for(re int i=1;i<=200000;++i)s=1ll*s*inv[N[i]]%M;
	re int k=min(n,m);
	re bool ia=1;
	for(re int i=1;i<=k;++i){
		re int x=ask(b[i]-1);
		re int ss=1ll*s*x%M*Inv[n-i+1]%M;
		add(ans,ss);
		if(!N[b[i]]){
			ia=0;break;
		}
		s=1ll*s*Inv[n-i+1]%M;
		s=1ll*s*N[b[i]]%M,--N[b[i]],Add(b[i],-1);
	}
	if(ia&&n<m)add(ans,1);
	printf("%d",ans);
}