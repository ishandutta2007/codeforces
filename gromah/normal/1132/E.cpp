#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 840
#define M 6720 + 5
#define INF 1234567890987654321LL

LL w, Max, A[9], Dp[M], _Dp[M];

int main()
{
	scanf("%lld", &w);
	for (int i = 1; i <= 8; i ++)
		scanf("%lld", A + i);
	for (int i = 1; i < M; i ++)
		Dp[i] = _Dp[i] = -INF;
	for (int i = 1; i <= 8; i ++)
	{
		for (int j = 1, t = N / i; j * i < N && j <= A[i]; j ++)
			for (int x = M - 1; x >= j * i; x --)
				_Dp[x] = max(_Dp[x], Dp[x - j * i] + (A[i] - j) / t);
		for (int j = 0; j < M; j ++)
			Dp[j] = max(Dp[j], _Dp[j]);
	}
	for (int j = 0; j < M && j <= w; j ++)
		Max = max(Max, j + N * min((w - j) / N, Dp[j]));
	printf("%lld\n", Max);
	return 0;
}