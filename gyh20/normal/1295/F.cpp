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
int n,m,t,a[1000002],ans,L[52],R[52],p[102],f[52],g[52],inv[52],fac[52],iv=1;
inline int C(re int x,re int y){
	int s=inv[y];
	for(re int i=x-y+1;i<=x;++i)s=1ll*s*i%M;
	return s;
}
int main(){
	n=read();
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2); 
	for(re int i=1;i<=n;++i)L[i]=read()-i,R[i]=read()-i,L[i]=-L[i],R[i]=-R[i],swap(L[i],R[i]),--L[i],p[++m]=L[i],p[++m]=R[i],iv=1ll*iv*(R[i]-L[i])%M;iv=ksm(iv,M-2);
	sort(p+1,p+m+1),m=unique(p+1,p+m+1)-p-1;
	f[0]=1;
	for(re int i=1;i<m;++i){
		for(re int j=1;j<=n;++j){
			g[j]=f[j];
			for(re int k=j,ck=1;k;--k){
				ck&=L[k]<=p[i]&&R[k]>=p[i+1];
				if(!ck)break;
				add(g[j],1ll*f[k-1]*C(p[i+1]-p[i],j-k+1)%M);
			}
		}
		for(re int j=1;j<=n;++j)f[j]=g[j];
	}
	printf("%d",1ll*iv*f[n]%M);
}