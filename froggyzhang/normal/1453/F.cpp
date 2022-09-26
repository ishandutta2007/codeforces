#include<bits/stdc++.h>
using namespace std;
#define N 3005
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
int T,n,a[N],dp[N][N],mn[N][N];
int Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=mn[i][j]=inf;
		}
	}
	dp[1][1]=0;
	for(int j=1;j<=n;++j)mn[1][j]=0;
	for(int i=2;i<=n;++i){
		int cnt=0;
		for(int j=i-1;j>=1;--j){
			if(a[j]+j>=i){
				dp[i][a[j]+j]=min(dp[i][a[j]+j],mn[j][i-1]+cnt);
				++cnt;	
			}
		}
		for(int j=i;j<=n;++j){
			mn[i][j]=min(mn[i][j-1],dp[i][j]);
		}
	}
	return dp[n][n];
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}