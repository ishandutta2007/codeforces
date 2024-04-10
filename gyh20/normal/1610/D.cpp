#include<cstdio>
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
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,ans,f[32],g[32][2],fac[1000002],inv[1000002];
char s[1000002];
inline int C(re int x,re int y){
	return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;
}
int main(){
	n=read();
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for(re int i=1;i<=n;++i){
		re int x=read(),o=0;
		while(x%2==0)++o,x>>=1;
		++f[o];
	}
	g[0][0]=1,g[0][1]=ksm(2,f[0])-1;
	for(re int i=1;i<=30;++i){
		g[i][0]=g[i-1][0];
		g[i][1]=1ll*g[i-1][1]*ksm(2,f[i])%M;
		re int s=0;
		for(re int j=2;j<=f[i];j+=2)add(s,C(f[i],j));
		add(g[i][1],1ll*g[i-1][0]*s%M);
	}
	printf("%d",g[30][1]);
}