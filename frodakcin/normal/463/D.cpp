#include <cstdio>
#include <array>

const int MN = 1e3+10;
int N, K;
int dp[MN], a[10][MN], b[10][MN], ans;

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0;i<K;++i)
		for(int j=0;j<N;++j)
			scanf("%d", a[i]+j), b[i][a[i][j]]=j;
	for(int i=0;i<N;++i)
	{
		int v=a[0][i];
		dp[v]=1;
		for(int j=0;j<i;++j)
		{
			int x=a[0][j];
			bool good=1;
			for(int k=1;good&&k<K;++k)
				if(b[k][x]>b[k][v])
					good=0;
			if(good)
				dp[v] = std::max(dp[v], dp[x]+1);
		}
	}
	for(int i=1;i<=N;++i)
		ans = std::max(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}