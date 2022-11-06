#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, Max, A[N << 1];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		A[i + n] = A[i];
	}
	for (int l = 1, r; l <= 2 * n; l = r + 1)
	{
		for (r = l; r <= 2 * n && A[r] == 1; r ++) ;
		Max = max(Max, r - l);
	}
	printf("%d\n", Max);
	return 0;
}