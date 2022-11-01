#include<bits/stdc++.h>
using namespace std;
#define N 105
const int B=100000;
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
int n,c[N],b[N],Q,ans[200002];
int Solve(int x){
	if(~ans[x+B])return ans[x+B];
	static int lim[N],dp[N*N];
	for(int i=1,sum=0,now=0;i<=n;++i){
		lim[i]=i*x+now;
		sum+=b[i];
		now+=sum;
	}
	bool ok=true;
	bool _0=true;
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=c[i];
		if(lim[i]>0){_0=false;}
		if(lim[i]>sum){ok=false;}
	}
	if(x!=-B&&_0)return ans[x+B]=ans[0];
	if(!ok)return ans[x+B]=0;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	sum=0;
	for(int i=1;i<=n;++i){
		sum+=c[i];
		static int s[N];
		s[0]=dp[0];
		for(int i=1;i<=sum;++i)s[i]=(s[i-1]+dp[i])%mod;
		for(int j=sum;j>=0;--j){
			dp[j]=(j<=c[i]?s[j]:(s[j]-s[j-c[i]-1]+mod)%mod);
		}
		for(int j=0;j<=min(sum,lim[i]-1);++j)dp[j]=0;
	}
	int tot=0;
	for(int i=0;i<=sum;++i)tot=(tot+dp[i])%mod;
	return ans[x+B]=tot;
}
int main(){
	memset(ans,-1,sizeof(ans));
	n=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<n;++i)b[i]=read();
	Solve(-100000);
	Q=read();
	while(Q--){
		int x=read();
		printf("%d\n",Solve(x));
	}
	return 0;
}