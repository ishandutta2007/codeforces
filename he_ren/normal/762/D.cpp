#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN][5];

ll sum[MAXN][5];
inline ll get_sum(int i,int l,int r)
{
	if(l>r) swap(l,r);
	return sum[i][r] - sum[i][l-1];
}

ll dp[MAXN][5];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int j=1; j<=3; ++j)
		for(int i=1; i<=n; ++i)
			scanf("%d",&a[i][j]);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=3; ++j)
			sum[i][j] = sum[i][j-1] + a[i][j];
	
	memset(dp,0xc0,sizeof(dp));
	dp[0][1] = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=3; ++j)
			for(int k=1; k<=3; ++k)
				dp[i][j] = max(dp[i][j], dp[i-1][k] + get_sum(i, j, k));
		
		for(int j=1; j<=3; ++j) if(j != 2)
		{
			dp[i][0] = max(dp[i][0], dp[i-1][j] + get_sum(i, 1, 3));
			dp[i][j] = max(dp[i][j], dp[i-1][0] + get_sum(i, 1, 3));
		}
	}
	
	printf("%lld",dp[n][3]);
	return 0;
}