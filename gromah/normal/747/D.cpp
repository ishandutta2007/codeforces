#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define INF 1234567890

int n, k, ans = 0, Min, Max, A[N];

inline int Solve(int ret)
{
	if (ret < 0) return INF;
	int res = ans;
	for (int i = 1; i <= A[0]; i ++)
	{
		if (ret < A[i]) break ;
		ret -= A[i], res -= 2;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1, x, last = 0; i <= n; i ++)
	{
		scanf("%d", &x);
		if (x < 0)
		{
			if (last)
				A[++ A[0]] = i - last - 1;
			else Min = i;
			Max = i;
			last = i, ans += 2, k --;
		}
	}
	if (k < 0) puts("-1");
	else if (ans == 0) puts("0");
	else
	{
		sort(A + 1, A + A[0] + 1);
		printf("%d\n", min(Solve(k - (n - Max)) - 1, Solve(k)));
	}
	return 0;
}