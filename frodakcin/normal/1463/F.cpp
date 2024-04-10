#include <cstdio>
#include <cstring>

bool ckmax(auto& a, const auto& b) {return b>a?a=b,1:0;}
bool ckmin(auto& a, const auto& b) {return b<a?a=b,1:0;}

const int MX = 22;
const int ALL = (1<<MX)-1;

int N, X, Y, dp[2][1<<MX];

int main()
{
	scanf("%d%d%d", &N, &X, &Y);
	int M=N/(X+Y);
	int R=N-M*(X+Y);

	for(int i=0;i<X+Y;++i)
	{
		memcpy(dp[0], dp[1], sizeof dp[0]);
		memset(dp[1], 0, sizeof dp[1]);
		for(int j=0;j<1<<MX;++j)
		{
			ckmax(dp[1][j<<1&ALL], dp[0][j]);
			if(!(j>>X-1&1) && !(j>>Y-1&1))
				ckmax(dp[1][j<<1&ALL|1], dp[0][j]+M+(i<R));
		}
	}

	int f=0;
	for(int i=0;i<1<<MX;++i)
		ckmax(f, dp[1][i]);
	printf("%d\n", f);
	return 0;
}