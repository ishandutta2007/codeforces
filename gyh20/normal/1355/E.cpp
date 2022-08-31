#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,ans,a,b,c,d,x,y,h[100002],sum[100002],ave,kkk,kkkk;
signed main(){ans=1e18;
	n=read();a=read();b=read();c=read();
	for(re int i=1;i<=n;++i)h[i]=read();
	sort(h+1,h+n+1);
	for(re int i=1;i<=n;++i)sum[i]=sum[i-1]+h[i];ans=0;
		ave=sum[n]/n;
		for(re int i=1;i<=n;++i)if(h[i]<=ave)ans+=ave-h[i];
		ans*=c;ans+=(sum[n]-ave*n)*b;
		x=ans;ans=0;
		++ave;
		for(re int i=1;i<=n;++i)if(h[i]>=ave)ans+=h[i]-ave;
		ans*=c;ans+=(ave*n-sum[n])*a;ans=min(ans,x);
		for(re int i=1;i<=n;++i){
			x=h[i]*(i-1)-sum[i-1];
			y=sum[n]-sum[i]-h[i]*(n-i);
			if(x<y)ans=min(ans,c*x+(y-x)*b);
			else ans=min(ans,c*y+(x-y)*a);
		}
		for(re int i=1;i<=n;++i)kkk+=h[n]-h[i];
		ans=min(ans,kkk*a);
		for(re int i=1;i<=n;++i)kkkk+=h[i]-h[1];
		ans=min(ans,kkkk*b);
		for(re int i=1;i<=n;++i){
			x=h[i]*(i-1)-sum[i-1];
			y=sum[n]-sum[i]-h[i]*(n-i);
			ans=min(ans,a*x+b*y);
		}
		printf("%lld",ans);
}