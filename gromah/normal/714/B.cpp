#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, cnt, A[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	sort(A + 1, A + n + 1);
	cnt = unique(A + 1, A + n + 1) - A - 1;
	if (cnt > 3) puts("NO");
	else if (cnt < 3) puts("YES");
	else if (A[1] + A[3] == A[2] * 2) puts("YES");
	else puts("NO");
	return 0;
}