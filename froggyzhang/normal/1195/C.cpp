#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
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
int n,a[2][N];
ll dp[N][3],ans;
int main(){
	n=read();
	for(int i=0;i<2;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=2;++j){
			int w=(j&1?a[0][i]:0)+(j&2?a[1][i]:0);
			for(int k=0;k<=2;++k){
				if(j&k)continue;
				dp[i][j]=max(dp[i][j],dp[i-1][k]+w);
			}
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}