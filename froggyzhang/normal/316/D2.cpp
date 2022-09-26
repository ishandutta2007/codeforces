#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
#define N 1000100
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
int n,c1,c2,dp[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read();
		if(x==1)++c1;
		else ++c2;
	}
	dp[0]=dp[1]=1;
	for(int i=2;i<=c1;++i){
		dp[i]=(dp[i-1]+1LL*(i-1)*dp[i-2])%mod;
	}
	ans=dp[c1];
	for(int i=c1+1;i<=c1+c2;++i){
		ans=1LL*ans*i%mod;
	}
	printf("%d\n",ans);
	return 0;
}