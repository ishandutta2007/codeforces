#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
ll n,dp[66][10101],ans;
int k;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll Solve(ll num,int i,int j){
	if(dp[i][j])return dp[i][j];
	if(i==0)return dp[i][j]=1;
	if(j==0)return dp[i][j]=Solve(num,i-1,j)*num%mod;
	for(int p=0;p<=i;++p){
		dp[i][j]=(dp[i][j]+Solve(num,p,j-1))%mod;
	}
	return dp[i][j]=dp[i][j]*qpow(i+1,mod-2)%mod;
}
int main(){
	n=read(),k=read(),ans=1;
	for(ll i=2;i*i<=n;++i){
		if(n%i==0){
			int cnt=0;
			while(n%i==0)++cnt,n/=i;
			memset(dp,0,sizeof(dp));
			ans=ans*Solve(i,cnt,k)%mod;
		}
	}
	if(n>1)memset(dp,0,sizeof(dp)),ans=ans*Solve(n,1,k)%mod;
	printf("%lld\n",ans);
	return 0;
}