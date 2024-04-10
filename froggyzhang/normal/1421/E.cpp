#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 200020
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
int n,a[N];
ll dp[N][2][2][3];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	if(n==1)return !printf("%d\n",a[1]);
	memset(dp,~0x3f,sizeof(dp));
	dp[1][1][0][n%3]=a[1];
	dp[1][0][0][(n+1)%3]=-a[1];
	for(int i=2;i<=n;++i){
		for(int t=0;t<=1;++t){
			for(int j=0;j<=1;++j){
				for(int s=0;s<=1;++s){
					for(int x=0;x<3;++x){
						ll &tmp=dp[i][t][(t==j)|s][(x+(!t))%3];
						tmp=max(tmp,dp[i-1][j][s][x]+(t?a[i]:-a[i]));
					}
				}
			}
		}
	}
	printf("%lld\n",max(dp[n][0][1][1],dp[n][1][1][1]));
	return 0;
}