#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,t,a[1000002],ans;
signed main(){
	t=read();
	while(t--){
		n=read(),ans=1e18;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=1;i<=n;++i)
			for(re int j=i+1;j<=n;++j)
				for(re int k=j+1;k<=n;++k){
					int o=max(a[i],max(a[j],a[k])),p=min(a[i],min(a[j],a[k]));
					ans=min(ans,o-p);
				}
		printf("%lld\n",ans);
	}
}