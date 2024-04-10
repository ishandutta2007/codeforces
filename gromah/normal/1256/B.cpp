#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int Case, n, A[N], Pos[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", A + i);
			Pos[A[i]] = i;
		}
		for (int i = 1, last = 0; i <= n; last = max(last, Pos[i]), i ++)
			if (Pos[i] > last)
				for (int j = Pos[i]; j > last && A[j] < A[j - 1]; j --)
					swap(A[j], A[j - 1]);
		for (int i = 1; i <= n; i ++)
			printf("%d%c", A[i], i == n ? '\n' : ' ');
	}
	return 0;
}