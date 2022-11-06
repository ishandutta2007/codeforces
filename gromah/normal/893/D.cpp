#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, d, cnt, A[N];
LL add, Sum[N], Max[N];
bool ok = 1;

int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Sum[i] = Sum[i - 1] + A[i];
	}
	Max[n] = Sum[n];
	for (int i = n - 1; i; i --)
		Max[i] = max(Max[i + 1], Sum[i]);
	ok = (Max[1] <= d);
	for (int i = 1; ok && i <= n; i ++)
		if (A[i] == 0)
		{
			if (Sum[i] + add < 0)
				add += d - add - Max[i], cnt ++;
			if (Sum[i] + add < 0) ok = 0;
		}
	if (!ok) puts("-1");
	else printf("%d\n", cnt);
	return 0;
}