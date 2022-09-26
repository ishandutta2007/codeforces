#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 5005
const int mod=998244353;
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
int dp[N][N],n,a[N],cnt[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1,j=0;i<=n;++i){
		while(a[j+1]*2<=a[i])++j;
		cnt[i]=j;
	}
	for(int i=1;i<=n;++i){
		dp[1][i]=1;
	}
	for(int i=2;i<=n;++i){
		int sum=0,k=1;
		for(int j=1;j<=n;++j){
			while(a[k]*2<=a[j])sum=(sum+dp[i-1][k++])%mod;
			dp[i][j]=(dp[i][j]+1LL*dp[i-1][j]*(cnt[j]-i+2)+sum)%mod;
		}
	}
	for(int i=1;i<=n;++i){
		ans=(ans+dp[n][i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}