#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, A[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	sort(A + 1, A + n + 1);
	printf("%d\n", A[n + 1 >> 1]);
	return 0;
}