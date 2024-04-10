#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 5005
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int a[N],n;
long long dp[2][N>>1][3];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	memset(dp,0x3f,sizeof(dp));
	dp[1][1][1]=dp[1][0][0]=0;
	for(int i=2;i<=n;++i){
		memset(dp[i&1],0x3f,sizeof(dp[i&1]));
		dp[i&1][0][0]=0;
		for(int j=1;j<=(n+1)/2;++j){
			dp[i&1][j][2]=min(dp[i&1][j][2],dp[(i-1)&1][j][1]+max(0,a[i]-a[i-1]+1));
			dp[i&1][j][1]=min(dp[(i-1)&1][j-1][2]+max(0,min(a[i-2]-1,a[i-1])-a[i]+1),dp[(i-1)&1][j-1][0]+max(0,a[i-1]-a[i]+1));
			dp[i&1][j][0]=min(dp[(i-1)&1][j][0],dp[(i-1)&1][j][2]);
		}
	}
	for(int i=1;i<=(n+1)/2;++i){
		printf("%lld ",min(min(dp[n&1][i][0],dp[n&1][i][1]),dp[n&1][i][2]));
	}
	return 0;
}