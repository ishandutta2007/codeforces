#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, q, x, A[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	sort(A + 1, A + n + 1);
	for (scanf("%d", &q); q; q --)
	{
		scanf("%d", &x);
		int t = upper_bound(A + 1, A + n + 1, x) - A - 1;
		printf("%d\n", t);
	}
	return 0;	
}