#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
const int mod=1e9+7;;
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
int n,c[N],b[N],Q;
int Solve(int x){
	static int lim[N],dp[N*N];
	memset(dp,0,sizeof(dp));
	for(int i=1,sum=0,now=0;i<=n;++i){
		lim[i]=i*x+now;
		sum+=b[i];
		now+=sum;
	}
	dp[0]=1;
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=c[i];
		for(int j=sum;j>=0;--j){
			int tmp=0;
			for(int k=0;k<=min(j,c[i]);++k){
				tmp=(tmp+dp[j-k])%mod;
			}
			dp[j]=tmp;
		}
		for(int j=0;j<=min(sum,lim[i]-1);++j)dp[j]=0;
	}
	int ans=0;
	for(int i=0;i<=sum;++i)ans=(ans+dp[i])%mod;
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<n;++i)b[i]=read();
	Q=read();
	while(Q--){
		int x=read();
		printf("%d\n",Solve(x));
	}
	return 0;
}