#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

int n, x, y, cnt, A[N];

int main()
{
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1, w; i <= n; i ++)
	{
		scanf("%d", &w);
		cnt += (w <= x);
	}
	printf("%d\n", y < x ? n : (cnt + 1 >> 1));
	return 0;
}