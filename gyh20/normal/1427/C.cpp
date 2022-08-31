#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,m,t,a[1000002],b[1000002],c[1000002],dp[1000002],tp,mx,ans;
char s[200002];
int main(){
	m=read(),n=read()+1;
	b[1]=c[1]=1;mx=-1e9;tp=1;
	for(re int i=2;i<=n;++i){dp[i]=-1e9;
		a[i]=read(),b[i]=read(),c[i]=read();
		while(a[i]-a[tp]>m*2)mx=max(mx,dp[tp]),++tp;
		for(re int j=tp;j<i;++j)if(abs(b[i]-b[j])+abs(c[i]-c[j])<=a[i]-a[j])dp[i]=max(dp[i],dp[j]+1);
		dp[i]=max(dp[i],mx+1);ans=max(ans,dp[i]);
	}
	printf("%d",ans);
}