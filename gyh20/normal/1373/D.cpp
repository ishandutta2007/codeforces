#include<bits/stdc++.h>
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
using namespace std;
int t,n,m,a[1000002],x,b[1000002];
long long ans;
inline long long work(re int l,re int r){
	if(r<l)return 0;
	for(re int i=l;i<=r;i+=2)if(!(i&1))b[(i+1)>>1]=a[i]-a[i+1];else b[(i+1)>>1]=a[i+1]-a[i];
	re long long sum=0,mx=0;
	for(re int i=1;i<=(r>>1);++i){
		sum+=b[i];
		sum=max(sum,0ll);
		mx=max(mx,sum);
	}
	return mx;
}
signed main(){
	t=read();
	while(t--){
		n=read();ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=1;i<=n;++i)if((i&1))ans+=a[i];
		if(n&1)printf("%lld\n",ans+max(work(1,n-1),work(2,n)));
		else printf("%lld\n",ans+max(work(1,n),work(2,n-1)));
	}
}