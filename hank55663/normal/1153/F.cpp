#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
LL dp[2005][2005][2];
int mod=998244353;
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int main(){
	int n,k,l;
	scanf("%d %d %d",&n,&k,&l);
	dp[0][0][0]=1;
	if(k==0)
	dp[0][0][1]=1;
	for(int i = 1;i<=n;i++){
		dp[i][0][0]=dp[i-1][0][0]*(n-i+1)%mod;
		dp[i][0][1]=dp[i-1][0][1]*(n-i+1)%mod;
		if(i>=k){
			dp[i][0][1]+=dp[i][0][0];
			dp[i][0][1]%=mod;
		}
		for(int j = 1;j<=i;j++){
			dp[i][j][0]=(dp[i-1][j][0]*(n-i+1)+dp[i][j-1][0]*(i-j+1))%mod;
			dp[i][j][1]=(dp[i-1][j][1]*(n-i+1)+dp[i][j-1][1]*(i-j+1))%mod;
			if(i-j>=k){
				dp[i][j][1]+=dp[i][j][0];
				dp[i][j][1]%=mod;
			}
		}
	}
	LL temp=1;
	for(int i = 1;i<=2*n+1;i++)
		temp = temp*i%mod;
	for(int i = 1;i<=n;i++){
		temp = temp*(mod+1)/2%mod;
	}
	LL ans = dp[n][n][1];
//	printf("%lld\n",ans);
	ans=ans*f_pow(temp,mod-2)%mod;
	printf("%lld\n",ans*l%mod);
}