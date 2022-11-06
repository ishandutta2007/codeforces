#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, k, Ans[N];
bool Flag[N];

int main()
{
	scanf("%d%d", &n, &k);
	int t = k;
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		t = __gcd(t, x);
	}
	for (int i = 0; i < k; i += t)
		Flag[i] = 1;
	for (int i = 0; i < k; i ++)
		if (Flag[i])
			Ans[++ Ans[0]] = i;
	for (int i = 0; i <= Ans[0]; i ++)
		printf("%d%c", Ans[i], (i % Ans[0] == 0) ? '\n' : ' ');
	return 0;
}