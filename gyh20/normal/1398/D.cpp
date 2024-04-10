#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,A,B,C,a[2002],b[2002],c[2002],dp[202][202][202],ans;
int main(){
	A=read(),B=read(),C=read();
	for(re int i=1;i<=A;++i)a[i]=read();
	sort(a+1,a+A+1);reverse(a+1,a+A+1);
	for(re int i=1;i<=B;++i)b[i]=read();
	sort(b+1,b+B+1);reverse(b+1,b+B+1);
	for(re int i=1;i<=C;++i)c[i]=read();
	sort(c+1,c+C+1);reverse(c+1,c+C+1);
	memset(dp,-127,sizeof(dp));dp[0][0][0]=0;
	for(re int i=0;i<=A;++i){
		for(re int j=0;j<=B;++j){
			for(re int k=0;k<=C;++k){
				if(i&&j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]*b[j]);
				if(i&&k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i]*c[k]);
				if(j&&k)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+b[j]*c[k]);
				ans=max(ans,dp[i][j][k]);
			}
		}
	}
	printf("%d",ans);
}