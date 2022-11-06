#include <cstdio>
#include <algorithm>
using namespace std;

int n, Max, A[99];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		A[i] = ((1 << i) - 1) * (1 << i - 1);
		if (n % A[i] == 0) Max = max(Max, A[i]);
		if (A[i] > n) break ;
	}
	printf("%d\n", Max);
	return 0;
}