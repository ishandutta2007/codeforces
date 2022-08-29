#include<cstdio>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int n,m,a[22],inv[22],ans;
inline int C(int x,int y){
	if(x<y)return 0;
	re int s=1;
	for(re int i=x-y+1;i<=x;++i)s=i%M*s%M;
	for(re int i=1;i<=y;++i)s=1ll*s*inv[i]%M;
	return s;
}
signed main(){
	n=read(),m=read(),inv[1]=1;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=2;i<=n;++i)inv[i]=1ll*inv[M%i]*(M-M/i)%M;
	for(re int S=0;S<(1<<n);++S){
		re int o=0,k=m;
		for(re int i=0;i<n;++i)if((S>>i)&1)o^=1,k-=a[i+1]+1;
		if(o)add(ans,M-C(k+n-1,n-1));else add(ans,C(k+n-1,n-1));
	}
	printf("%lld",ans);
}