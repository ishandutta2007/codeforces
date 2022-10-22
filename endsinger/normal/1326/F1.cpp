#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=14;
int n;
char a[N+1][N+5];
vector<vector<int>>dp[1<<N];
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<1<<n;i++)
	{
		int cnt=__builtin_popcount(i);
		if(cnt==1)
		{
			dp[i].push_back(vector<int>(n));
			for(int j=0;j<n;j++)
				if(i&1<<j)
					dp[i][0][j]=1;
			continue;
		}
		dp[i].resize(1<<cnt-1,vector<int>(n));
		for(int j=0;j<dp[i].size();j++)
			for(int k=0;k<n;k++)
				if(i&1<<k)
					for(int o=0;o<n;o++)
						if(a[k][o]-'0'==!!(j&1<<cnt-2))
							dp[i][j][k]+=dp[i^1<<k][j^(j&1<<cnt-2)][o];
	}
	for(int i=0;i<1<<n-1;i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
			sum+=dp[(1<<n)-1][i][j];
		printf("%lld ",sum);
	}
	return 0;
}