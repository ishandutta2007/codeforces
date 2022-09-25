#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
const int mod=1e9+7;
int lcp[N][N],n;
char s[N];
void Solve_sum(){
	static int dp[N][N],sum[N][N];
	dp[0][0]=1;
	fill(sum[0],sum[0]+n+1,1);
	for(int i=1;i<=n;++i){
		for(int j=i;j>=1;--j){
			int len=i-j+1;
			if(s[j]=='1'){
				dp[i][j]=sum[j-1][max(0,j-len+1)];
				if(j-1>=len&&(lcp[j-len][j]>=len||s[j+lcp[j-len][j]]>s[j-len+lcp[j-len][j]])){
					dp[i][j]=(dp[i][j]+dp[j-1][j-len])%mod;
				}
			}	
		}
		for(int j=i;j>=0;--j){
			sum[i][j]=(sum[i][j+1]+dp[i][j])%mod;	
		}
	}
	cout<<sum[n][0]<<'\n';	
}
void Solve_mn(){
	static int dp[N][N],mn[N][N];
	const int inf=0x3f3f3f3f;
	memset(dp,0x3f,sizeof(dp));
	memset(mn,0x3f,sizeof(mn));
	dp[0][0]=0;
	fill(mn[0],mn[0]+n+1,0);
	for(int i=1;i<=n;++i){
		for(int j=i;j>=1;--j){
			int len=i-j+1;
			if(s[j]=='1'){
				dp[i][j]=mn[j-1][max(0,j-len+1)]+1;
				if(j-1>=len&&(lcp[j-len][j]>=len||s[j+lcp[j-len][j]]>s[j-len+lcp[j-len][j]])){
					dp[i][j]=min(dp[i][j],dp[j-1][j-len]+1);
				}
			}
		}
		for(int j=i;j>=0;--j){
			mn[i][j]=min(mn[i][j+1],dp[i][j]);	
		}
	}
	int ans=inf;
	int z=0,t=1;
	for(int i=n;i>=max(1,n-19);--i,t<<=1){
		z=(z+t*(s[i]-'0'))%mod;
		if(dp[n][i]<inf){
			ans=min(ans,dp[n][i]+z);
		}
	}
	if(ans<inf){
		cout<<ans<<'\n';
		return;
	}
	for(int i=n-20;;--i,(t<<=1)%=mod){
		z=(z+t*(s[i]-'0'))%mod;
		if(dp[n][i]<inf){
			cout<<(z+dp[n][i])%mod<<'\n';
			return;	
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=n;i>=1;--i){
		for(int j=n;j>=1;--j){
			lcp[i][j]=s[i]==s[j]?lcp[i+1][j+1]+1:0;		
		}
	}
	Solve_sum();
	Solve_mn();
	return 0;
}