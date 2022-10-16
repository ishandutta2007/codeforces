#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int n,k,z,T,dp[6][N],a[N];
void Solve(){
	n=read(),k=read(),z=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=0;i<=z;++i){
		for(int j=0;j<=n;++j){
			dp[i][j]=0;
		}
	}
	int ans=0;
	for(int i=1;i<=k+1;++i){
		dp[0][i]=dp[0][i-1]+a[i];
		ans=max(ans,dp[0][i]);
	}
	for(int i=1;i<=z;++i){
		for(int j=1;j<=k+1-(i<<1);++j){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j+1])+a[j];
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	
	return 0;
}