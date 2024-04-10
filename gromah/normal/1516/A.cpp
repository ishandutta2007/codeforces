#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int Case, n, k, A[N];

int main()
{
	for (scanf("%d", &Case); Case; Case--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", A + i);
		for (int pos = 1; pos < n && k; k --)
		{
			for (; pos < n && A[pos] == 0; pos++);
			A[pos] --, A[n] ++;
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", A[i], i == n ? '\n' : ' ');
	}
	return 0;
}