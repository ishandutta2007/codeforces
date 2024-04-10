#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define N 100010
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
int n;
ll dp[N][201][2],a[N],ans,s[201][2];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dp[0][0][1]=1;
	for(int i=1;i<=n;i++){
		if(~a[i]){
			for(int j=0;j<=a[i]-1;j++){
				dp[i][a[i]][0]=(dp[i][a[i]][0]+dp[i-1][j][0]+dp[i-1][j][1])%mod;
			}
			dp[i][a[i]][1]=(dp[i][a[i]][1]+dp[i-1][a[i]][0]+dp[i-1][a[i]][1])%mod;
			for(int j=a[i]+1;j<=200;j++){
				dp[i][a[i]][1]=(dp[i][a[i]][1]+dp[i-1][j][1])%mod;
			}
		}
		else{
			s[0][0]=dp[i-1][0][0],s[0][1]=dp[i-1][0][1];
			for(int j=1;j<=200;j++){
				s[j][0]=(s[j-1][0]+dp[i-1][j][0])%mod;
				s[j][1]=(s[j-1][1]+dp[i-1][j][1])%mod;
			}
			for(int k=1;k<=200;k++){
				dp[i][k][0]=(s[k-1][0]+s[k-1][1])%mod;
				dp[i][k][1]=(dp[i][k][1]+dp[i-1][k][0]+s[200][1]-s[k-1][1]+mod)%mod;
			}
		}
	}
	for(int i=1;i<=200;i++){
		ans=(ans+dp[n][i][1])%mod;
	}
	cout<<ans<<endl;
	return 0;
}