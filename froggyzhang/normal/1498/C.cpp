#include<bits/stdc++.h>
using namespace std;
#define N 1010
const int mod=1e9+7;
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
int T;
int Solve(int n,int m){
	static int dp[N][N][2];
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			dp[i][j][0]=dp[i][j][1]=0;
		}
	}
	int ans=1;
	dp[0][0][1]=1;
	for(int i=1;i<m;++i){
		static int pre[N],suf[N];
		pre[0]=dp[0][i-1][1];
		for(int j=1;j<=n;++j){
			pre[j]=(pre[j-1]+dp[j][i-1][1])%mod;
		}
		suf[n+1]=0;
		for(int j=n;j>=1;--j){
			suf[j]=(suf[j+1]+dp[j][i-1][0])%mod;
		}
		for(int j=1;j<=n;++j){
			dp[j][i][0]=pre[j-1];
			dp[j][i][1]=suf[j+1];
			ans=((ans+pre[j-1])%mod+suf[j+1])%mod;
		}	
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		int n=read(),k=read();
		printf("%d\n",Solve(n,k));
	}
	return 0;
}