#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300010
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
int T,n,Q,a[N];
ll Solve(){
	static ll dp[N][2];
	for(int i=1;i<=n;++i){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]-a[i]);
		dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);
	}
	return max(dp[n][0],dp[n][1]);
}
int main(){
	T=read();
	while(T--){
		n=read(),Q=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		printf("%lld\n",Solve());
	}
	return 0;
}