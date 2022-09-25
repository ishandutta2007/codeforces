#include<bits/stdc++.h>
using namespace std;
#define N 2020
const int inf=0x3f3f3f3f;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int T,n,m,dp[N][N],a[N];
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=-inf;
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]);
		}
		for(int j=0;j<=i;++j){
			dp[i][j]=max(dp[i][j],dp[i-1][j]+(a[i]==i-j));	
		}
	}
	for(int j=0;j<=n;++j){
		if(dp[n][j]>=m){
			printf("%d\n",j);
			return;
		}
	}
	puts("-1");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}