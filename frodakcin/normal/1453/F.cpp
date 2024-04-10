#include <cstdio>
#include <cstring>
#include <cassert>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 3e3+10;
const int INF = 0x3f3f3f3f;

int dp[MN][MN], fail[MN][MN], a[MN];

void solve()
{
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	for(int i=0;i<N;++i)
	{
		memset(dp[i], 0x3f, N*sizeof*(dp[i]));
		memset(fail[i], 0, N*sizeof*(fail[i]));
	}
	for(int r=0;r<N;++r) // inc/inc
	{
		fail[r][r]=!!a[r];
		for(int l=r-1;l>=0;--l)
			fail[l][r] = fail[l+1][r] + (l+a[l]>r);
	}

	dp[0][0]=0;
	for(int i=0;i<N;++i)
		for(int j=i+1;j<=i+a[i];++j)
		{
			ckmin(dp[i][j], dp[i][j-1]);
			if(i+a[i] != N-1 || j == N-1)
				ckmin(dp[j][i+a[i]], dp[i][j-1]+fail[i+1][j-1]);
		}

	assert(dp[N-1][N-1]<INF);
	printf("%d\n", dp[N-1][N-1]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(;T--;)
		solve();
	return 0;
}