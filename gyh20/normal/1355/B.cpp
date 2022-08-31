#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,ans,a[1000002],dp[1000002];
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);ans=0;
		for(re int i=1;i<=n;++i){
		dp[i]=dp[i-1];		if(i>=a[i])dp[i]=max(dp[i],dp[i-a[i]]+1);ans=max(ans,dp[i]);}
		printf("%d\n",ans);
		for(re int i=1;i<=n;++i)dp[i]=0;
	}
}