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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,cnt,inv[3000002],fac[3000002],f[3],ans[3000002],g[3];
inline int C(re int x,re int y){if(x<y)return 0;return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;;}
signed main(){
	n=read(),m=3*n+1;
	for(re int i=fac[0]=1;i<=m;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[m]=ksm(fac[m],M-2);
	for(re int i=m-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	n*=3;
	re int i3=ksm(3,M-2);
	for(re int i=0;i<=n;++i)++f[i%3];
	for(re int i=1;i<=n;++i){
		re int sum=C(n+1,i+1);
		re int b=sum;
		add(b,M-f[2]);
		add(b,M-f[1]),add(b,M-f[1]);
		b=1ll*b*i3%M;
		re int a,c;
		c=b,add(c,f[1]);
		a=c,add(a,f[2]);
		ans[i]=a,f[0]=a,f[1]=b,f[2]=c;
	}
	m=read();
	while(m--)printf("%d\n",ans[read()]);
	
}