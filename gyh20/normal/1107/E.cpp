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
int n,a[102],dp[102][102][102];
char s[102];
inline int ask(re int l,re int r,re int k){
	if(l>r)return 0;
	if(l==r)return a[k];
	if(~dp[l][r][k])return dp[l][r][k];
	dp[l][r][k]=ask(l+1,r,1)+a[k];  
	for(re int i=l+1;i<=r;++i)if(s[i]==s[l])dp[l][r][k]=max(dp[l][r][k],ask(l+1,i-1,1)+ask(i,r,k+1));
	return dp[l][r][k];
}
signed main(){
	n=read();
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i){
		a[i]=read();
		for(re int j=i-1;j;--j)a[i]=max(a[i],a[j]+a[i-j]);
	}
	memset(dp,-1,sizeof(dp));
	printf("%lld",ask(1,n,1));
}