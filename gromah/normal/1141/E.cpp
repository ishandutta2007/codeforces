#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n, A[N];
LL h, del, Min;

int Get(LL hp)
{
	for (int i = 1; i <= n; i ++)
	{
		hp += A[i];
		if (hp <= 0) return i;
	}
	return -1;
}

int main()
{
	scanf("%lld%d", &h, &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Min = min(Min, del += A[i]);
	}
	if (del >= 0 && h + Min > 0) puts("-1");
	else if (h + Min <= 0)
		printf("%d\n", Get(h));
	else
	{
		del = -del;
		LL round = (h + Min + del - 1) / del;
		printf("%lld\n", round * n + Get(h - del * round));
	}
	return 0;
}