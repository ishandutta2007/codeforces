#include<bits/stdc++.h>
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
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],dp[32][32];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=29;~i;--i)a[30-i]=(n>>i)&1;
		for(re int i=29;~i;--i)b[30-i]=(m>>i)&1;
		memset(dp,0,sizeof(dp));
		dp[30][0]=1;
		for(re int i=30;i;--i){
			//printf("%d %d\n",a[i],b[i]);
			for(re int j=0;j<=30;++j){
			//	if(i>=27)printf("%d %d %d\n",i,j,dp[i][j]);
				if(a[i]==b[i]){
					dp[i-1][0]=dp[i][0];
					for(re int k=1;k<=j;++k)dp[i-1][k]|=dp[i][j];
				}
				else if(a[i]){
					for(re int k=1;k<=j+1;++k)dp[i-1][k]|=dp[i][j];
				}
				else{
					for(re int k=0;k<j;++k)dp[i-1][k]|=dp[i][j];
				}
			}
		}
		puts(dp[0][0]?"YES":"NO");
	}
}