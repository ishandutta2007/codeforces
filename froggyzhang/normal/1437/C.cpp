#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 233
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
int T,n,a[N];
int Solve(){
	static int dp[N][N<<1];
	sort(a+1,a+n+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=(n<<1);++j){
			for(int k=0;k<j;++k){
				dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(j-a[i]));
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(int j=n;j<=(n<<1);++j){
		ans=min(ans,dp[n][j]);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		printf("%d\n",Solve());
	}
	return 0;
}