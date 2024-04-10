#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t; 
}
int n,a[1000005],r1,r2,r3,d,dp[1000005][2],ans,f[1000005];
signed main(){
	n=read(),r1=read(),r2=read(),r3=read(),d=read();
	dp[1][1]=dp[1][0]=0;
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=2;i<=n+1;++i){
		dp[i][0]=dp[i-1][1]+min(r1*(a[i-1]+1),r2)+(i==n+1?0:d);
		dp[i][0]=min(dp[i][0],dp[i-1][0]+min(min(r1*(a[i-1]+1),r2)+r1+d+d,r1*a[i-1]+r3+d+(i==n+1?0:d))+(i==n+1?0:d));
		dp[i][1]=min(dp[i-1][1]+r1*a[i-1]+r3+(i==n+1?0:d),dp[i-1][0]+min(min(r1*(a[i-1]+1),r2)+r1+d+r1+d,r1*a[i-1]+r3+d+r1+(i==n+1?0:d))+(i==n+1?0:d));
	}
	ans=dp[n+1][1];
	for(re int i=n;i;--i){
		f[i]=f[i+1]+min((a[i]+1)*r1,r2)+r1+d+(i==n?d:0)+(i==n?0:d);
		ans=min(ans,dp[i][1]+f[i]);
	}
	printf("%lld",ans);
}