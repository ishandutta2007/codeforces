#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,dp[N][2];
char s[2][N];
void Solve(){
	cin>>n;
	cin>>(s[0]+1);
	cin>>(s[1]+1);
	dp[0][0]=dp[0][1]=-1;
	int las=0;
	for(int i=1;i<=n;++i){
		if(s[0][i]=='.'&&s[1][i]=='.'){
			dp[i][0]=dp[i-1][0]+(dp[i-1][0]>=0),dp[i][1]=dp[i-1][1]+(dp[i-1][1]>=0);
			continue;
		}
		else{
			las=i;
			if(s[0][i]=='*'&&s[1][i]=='*'){
				dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][1]+2,dp[i-1][0]+2);
			}
			else if(s[0][i]=='*'){
				dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+2);
			}
			else{
				dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+2);
				dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
			}
		}
	}
	cout<<max(0,min(dp[las][0],dp[las][1]))<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}