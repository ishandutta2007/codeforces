#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int T,n,a[N],dp[N][2];
int Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	dp[0][0]=dp[1][1]=n;
	dp[1][0]=a[1];
	for(int i=2;i<=n;++i){
		dp[i][0]=min(dp[i-1][1]+a[i],dp[i-2][1]+a[i]+a[i-1]);
		dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
	}
	return min(dp[n][0],dp[n][1]);
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}