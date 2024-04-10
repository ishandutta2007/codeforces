#include <bits/stdc++.h>
using namespace std;
short dp[505][505][505],nxt[505][2];
string a,b;
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	cin >> a >> b;
	a=' '+a,b=' '+b;
	for(int i=0;i<=m;i++)
	{
		string ling=b.substr(1,i)+'0';
		nxt[i][0]=0;
		for(int j=min(m,(int)ling.size());j>=1;j--)
		{
			if(b.substr(1,j)==ling.substr(ling.size()-j))
			{
				nxt[i][0]=j;
				break;
			}
		}
		string yi=b.substr(1,i)+'1';
		nxt[i][1]=0;
		for(int j=min(m,(int)yi.size());j>=1;j--)
		{
			if(b.substr(1,j)==yi.substr(yi.size()-j))
			{
				nxt[i][1]=j;
				break;
			}
		}
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++) for(int k=0;k<=m;k++) dp[i][j][k]=20000;
	dp[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=m;k++)
			{
				dp[i+1][j+(nxt[k][0]==m)][nxt[k][0]]=min(dp[i+1][j+(nxt[k][0]==m)][nxt[k][0]],(short)(dp[i][j][k]+(a[i+1]!='0')));
				dp[i+1][j+(nxt[k][1]==m)][nxt[k][1]]=min(dp[i+1][j+(nxt[k][1]==m)][nxt[k][1]],(short)(dp[i][j][k]+(a[i+1]!='1')));
			}
		}
	}
	for(int i=0;i<=n-m+1;i++)
	{
		short ans=20000;
		for(int k=0;k<=m;k++)
			ans=min(ans,dp[n][i][k]);
		if(ans==20000) ans=-1;
		cout << ans << " ";
	}
	return 0;
}