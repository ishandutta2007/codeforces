#include<cstring>
#include<cstdio>
#include<cmath>
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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[5002],b[5002];
long long f[5002],ans,mx[5002],tmp[5002];
inline long long max(re long long x,re long long y){
	return x>y?x:y;
}
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=1;i<=n;++i)b[i]=read();
		memset(mx,-127,sizeof(mx));
		for(re int i=1;i<=n;++i){
			for(re int j=1;j<=i-1;++j){
				if((a[i]^a[j]))f[j]=mx[j]+abs(b[i]-b[j]);
				else f[j]=-1e18;
			}
			tmp[i]=0;
			for(re int j=i-1;~j;--j)tmp[j]=max(tmp[j+1],f[j]);
			for(re int j=1;j<i;++j)if(a[i]^a[j])mx[j]=max(mx[j],tmp[j+1]+abs(b[i]-b[j]));
			mx[i]=tmp[0];
		}
		ans=0;
		for(re int i=0;i<=n;++i)ans=max(ans,mx[i]);
		printf("%lld\n",ans);
	}
}