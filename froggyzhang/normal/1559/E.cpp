#include<bits/stdc++.h>
using namespace std;
#define N 110010
typedef long long ll;
const int mod=998244353;
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
int n,m,l[N],r[N],ans[N];
int calc(int t){
	static int dp[N],s[N];
	for(int i=0;i<=m/t;++i)dp[i]=0;
	dp[0]=1;
	for(int i=1;i<=n;++i){
		s[0]=dp[0];
		for(int j=1;j<=m/t;++j){
			s[j]=(s[j-1]+dp[j])%mod;
		}
		int L=(l[i]+t-1)/t,R=r[i]/t;
		for(int j=0;j<L;++j)dp[j]=0;
		for(int j=L;j<=m/t;++j){
			dp[j]=(s[j-L]+(j>R?mod-s[j-R-1]:0))%mod;	
		}
	}
	int ans=0;
	for(int i=0;i<=m/t;++i)ans=(ans+dp[i])%mod;
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read();
	}
	for(int i=1;i<=m;++i){
		ans[i]=calc(i);
	}
	for(int i=m;i>=1;--i){
		for(int j=i+i;j<=m;j+=i){
			ans[i]=(ans[i]-ans[j]+mod)%mod;
		}
	}
	printf("%d\n",ans[1]);
	return 0;
}