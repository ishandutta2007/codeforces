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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;} 
inline int Pw(re int x){return 1ll*x*x%M;}
int k,w,fac[1000002],inv[1000002];
inline int solve(re int n){
	re int s=1ll*(ksm(k,n)-1)*ksm(k-1,M-2)%M;
	for(re int i=n;i<=n+k;++i){
		re int o=i-n;
		if(o+o<=i)add(s,1ll*Pw(1ll*fac[k]*inv[k-o]%M)*ksm(k,i-o-o)%M);
		else add(s,1ll*fac[k]*inv[k-(o+o-i)]%M*Pw(1ll*fac[k-(o+o-i)]*inv[k-o]%M)%M);
	}
	return s;
}
int main(){
	k=read(),w=read();if(k==1)return puts("1"),0;
	for(re int i=fac[0]=1;i<=k;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[k]=ksm(fac[k],M-2);
	for(re int i=k-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	printf("%d",Mod(solve(w)-solve(w-1)+M));
}