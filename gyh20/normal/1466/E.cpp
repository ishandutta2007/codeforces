#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define re register
#define in inline
#define int long long
using namespace std;
in int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
const int M=1e9+7;
int n,a[500002],f[500002],sum[62],ans;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
signed main(){
	int t;
	scanf("%lld",&t);
	while(t--){
		memset(sum,0,sizeof(sum));
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=1;i<=n;++i){
			for(re int j=60;~j;--j)if(a[i]&(1ll<<j))++sum[j];
		}
		for(re int i=1;i<=n;++i){
			f[i]=0;
			for(re int j=0;j<=60;++j){
				if(a[i]&(1ll<<j)){
					f[i]+=(1ll<<j)%M*n%M;
				}
				else f[i]+=(1ll<<j)%M*sum[j]%M;
			}
			f[i]%=M;
		}
		memset(sum,0,sizeof(sum));
		for(re int i=1;i<=n;++i){
			for(re int j=60;~j;--j)if(a[i]&(1ll<<j))add(sum[j],f[i]);
		}
		for(re int i=1;i<=n;++i){
			for(re int j=60;~j;--j)if(a[i]&(1ll<<j))add(ans,1ll*(1ll<<j)%M*sum[j]%M);
		}
		printf("%lld\n",ans%M);
	}
}