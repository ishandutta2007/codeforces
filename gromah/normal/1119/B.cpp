#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000 + 5

int n, h, A[N];

bool Check(int k)
{
	static int B[N];
	for (int i = 1; i <= k; i ++)
		B[i] = A[i];
	sort(B + 1, B + k + 1);
	reverse(B + 1, B + k + 1);
	LL sum = 0;
	for (int i = 1; i <= k; i += 2)
		sum += B[i];
	return sum <= h;
}

int main()
{
	scanf("%d%d", &n, &h);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (Check(mid))
			l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}