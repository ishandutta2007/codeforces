#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
int t,n,a[1000002],phi[1000002],ans1,ans2,fac[1000002],inv[1000002],ia;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int calc2(re int x){
	re int s=fac[n/x];
	for(re int i=1;i<=n;++i)if(a[i]%x)return 0;else s=1ll*s*inv[a[i]/x]%M;
	return s;
}
inline int calc1(re int x){
	re int o=calc2(x);
	if(!o)return 0;
	re int s=1ll*(n/x)*o%M;
	for(re int i=1;i<=n;++i)
		if(a[i]>=x+x){
			re int y=a[i]/x;
			add(s,M-1ll*o*inv[n/x]%M*fac[n/x-2]%M*fac[a[i]/x]%M*inv[a[i]/x-2]%M*(n/x)%M);
		}
	s=1ll*s*x%M;
	return s;
}
int main(){
	n=1e6;
	for(re int i=fac[0]=inv[0]=1;i<=n;++i){
		phi[i]+=i,fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
		for(re int j=i+i;j<=n;j+=i)phi[j]-=phi[i];
	}
	t=read();
	while(t--){
		n=read(),ans1=ans2=0;
		for(re int i=1;i<=n;++i)a[i]=0;ia=1;
		for(re int i=1;i<=n;++i)++a[read()];
		for(re int i=1;i<=n;++i)if(a[i]==n)ia=0;
		if(!ia){puts("1");continue;}
		for(re int i=1;i<=n;++i)if(n%i==0)add(ans1,1ll*calc1(i)*phi[i]%M),add(ans2,1ll*calc2(i)*phi[i]%M);
		ans1=1ll*ans1*ksm(n,M-2)%M,ans2=1ll*ans2*ksm(n,M-2)%M;
		ans1=1ll*ans1*ksm(ans2,M-2)%M,printf("%d\n",ans1);
	}
}