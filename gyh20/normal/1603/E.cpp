#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,M,ans,fac[202],inv[202];
map<int,int>f[202];
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
inline int calc(re int x){
	for(re int i=0;i<=n;++i)f[i].clear();
	for(re int i=x;i<=n*x&&i<=x*x;i+=x)f[i/x][i]=inv[i/x];
	for(re int i=x+1;i<=n+1;++i)
		for(re int o=n;o;--o){
			for(auto z:f[o]){
				if(z.first+n+1+(n-o-1)*i>(n+1)*x)continue;
					for(re int k=1;k+o<=n&&z.first+k*i<=i*x;++k)
						add(f[o+k][z.first+k*i],1ll*z.second*inv[k]%M);
			}
		}
	re int s=0;
	for(auto z:f[n])add(s,z.second);
	return s;
} 
int main(){
	n=read(),M=read();
	if(n==1)return puts("2"),0;
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for(re int i=max(2,n-40);i<=n+1;++i)add(ans,calc(i));
	printf("%d",1ll*ans*fac[n]%M);
}