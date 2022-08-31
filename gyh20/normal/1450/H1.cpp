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
int n,m,c[202][2],fac[400002],inv[400002],ans;
char s[200002];
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
int main(){
	n=4e5;
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	n=read(),m=read();
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i)++c[s[i]][i&1];
	re int dlt=c['b'][1]-c['b'][0];
	for(re int i=0;i<=c['?'][0]+c['?'][1];++i)if(((c['b'][1]-c['b'][0]+1919810)&1)==((i+c['?'][0]+1919810)&1))add(ans,1ll*C(c['?'][0]+c['?'][1],i)*(abs(dlt+i-c['?'][0])/2)%M);
	printf("%d",1ll*ans*ksm(M+1>>1,c['?'][0]+c['?'][1]-1)%M);
}