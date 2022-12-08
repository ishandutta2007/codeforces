#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int SZ=5001;
ll dp[SZ][SZ], p[SZ], sum[SZ];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	sum[0]=0;
	repeq(i,1,n)
	{
		cin >> p[i];
		sum[i]=p[i]+sum[i-1];
	}
	repeq(j,1,k)
		dp[0][j]=-1;
	dp[0][0]=0;
	repeq(i,1,n)
	{
		dp[i][0]=0;
		repeq(j,1,k)
		{
			dp[i][j]=dp[i-1][j];
			if(i-m>=0 && dp[i-m][j-1]!=-1)
			{
				ll v = dp[i-m][j-1]+sum[i]-sum[i-m];
				if(v>dp[i][j])
					dp[i][j]=v;
			}
		}
	}
	cout << dp[n][k]<<endl;
	return 0;
}