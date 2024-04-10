#include<bits/stdc++.h>
using namespace std;
#define PB push_back 
typedef long long ll;
ll n,dp[111][2];
string s;
void dynamic_programming()
{
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='A'&&s[i+1]=='A')dp[i][0]=dp[i+1][1],dp[i][1]=dp[i+1][1];
		else if(s[i]=='A'&&s[i+1]=='B')dp[i][0]=dp[i+1][0]+dp[i+1][1],dp[i][1]=dp[i+1][1];
		else if(s[i]=='B'&&s[i+1]=='A')dp[i][0]=dp[i+1][1],dp[i][1]=dp[i+1][0];
		else dp[i][0]=dp[i+1][0]+dp[i+1][1],dp[i][1]=0;
	}
}
int main()
{
	cin>>s;
	n=s.size();
	s.PB(s[0]);
	ll ans=0;
	dp[n][0]=1;dp[n][1]=0;
	dynamic_programming();
	ans+=dp[0][0];
	
	dp[n][0]=0;dp[n][1]=1;
	dynamic_programming();
	ans+=dp[0][1];
	
	cout<<ans<<endl;
	return 0;
}