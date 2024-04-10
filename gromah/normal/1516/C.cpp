#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5
#define M 200000 + 5

int Case, n, sum, A[N];
bool Dp[M];

int main()
{
	scanf("%d", &n);
	Dp[0] = true;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", A + i);
		sum += A[i];
		for (int j = M - 1; j >= A[i]; j--)
			Dp[j] |= Dp[j - A[i]];
	}
	if ((sum & 1) || !Dp[sum / 2])
		puts("0");
	else
	{
		puts("1");
		int id = 1, val = A[1] & -A[1];
		for (int i = 2; i <= n; i++)
			if ((A[i] & -A[i]) < val)
				id = i, val = A[i] & -A[i];
		printf("%d\n", id);
	}

	return 0;
}