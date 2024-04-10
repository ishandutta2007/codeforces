#include <iostream>
#include <cstdio>

using namespace std;

template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}
template<class T> bool mx(T& a, const T& b) {return b>a?a=b,1:0;}

const int INF = 1e9;
const int MN = 2e5 + 100;
int N;
int a[MN];
int dp[2][MN], pr[2][MN];
bool ans[MN];

int main(void)
{
	scanf("%d", &N);
	for(int i = 1;i <= N;i++)
		scanf("%d", a + i);
	dp[0][1] = INF, dp[1][1] = -INF;
	for(int i = 2;i <= N;i++)
	{
		dp[0][i] = -INF, dp[1][i] = INF;
		pr[0][i] = pr[1][i] = -1;

		if(a[i]>a[i-1]) if(~pr[0][i-1] && mx(dp[0][i], dp[0][i-1])) pr[0][i] = 0;
		if(a[i]>dp[1][i-1]) if(~pr[1][i-1] && mx(dp[0][i], a[i-1])) pr[0][i] = 1;

		if(a[i]<a[i-1]) if(~pr[1][i-1] && mn(dp[1][i], dp[1][i-1])) pr[1][i] = 1;
		if(a[i]<dp[0][i-1]) if(~pr[0][i-1] && mn(dp[1][i], a[i-1])) pr[1][i] = 0;

		//printf("%d: %d(%d) %d(%d)\n", i, dp[0][i], pr[0][i], dp[1][i], pr[1][i]);
	}

	if(~pr[1][N] || ~pr[0][N])
	{
		bool c = ~pr[1][N];
		for(int i = N;i >= 1;i--)
		{
			ans[i] = c;
			if(i>1)
				c = pr[c][i];
		}
		printf("YES\n");
		for(int i = 1;i <= N;i++)
			printf("%d%c", ans[i], " \n"[i==N]);
	}
	else
		printf("NO\n");
	return 0;
}