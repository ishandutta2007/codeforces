#include<bits/stdc++.h>
using namespace std;
const int N=1005;
char c;
int n,a[20],f[N],m[20][20],zh[20][20],dp[N][(1<<16)+10];
inline void up(int &x,int y){if(x>y)x=y;}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=4;i++)
		cin>>a[i];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>c;
			f[j]=(f[j]<<1)+(c=='*');
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=4-i;j++)
		{
			for(int k=0;k<4;k++)
				for(int p=0;p<4;p++)
					zh[k][p]=1;
			for(int k=0;k<j;k++)
				for(int p=0;p<j;p++)
					zh[k][p+i]=0;
			for(int k=3;k>=0;k--)
				for(int p=0;p<4;p++)
					m[i][j]=(m[i][j]<<1)+zh[k][p];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	int be=0;
	for(int i=3;i>=0;i--)
		be=(be<<4)+f[i];
	dp[0][be]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=(1<<16)-1;j>=0;j--)
		{
			if(dp[i][j]>=0x3f3f3f3f-10)
				continue;
			if((j&15)==0)
				up(dp[i+1][(f[i+4]<<12)|(j>>4)],dp[i][j]);
			for(int k=0;k<4;k++)
				for(int p=1;p<=4-k;p++)
					up(dp[i][j&m[k][p]],dp[i][j]+a[p]);
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}