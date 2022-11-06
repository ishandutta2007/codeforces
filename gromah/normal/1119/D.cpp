#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, q;
LL A[N], Sum[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", A + i);
	sort(A + 1, A + n + 1);
	for (int i = 1; i < n; i ++)
		A[i] = A[i + 1] - A[i];
	sort(A + 1, A + n);
	for (int i = 1; i < n; i ++)
		Sum[i] = Sum[i - 1] + A[i];
	scanf("%d", &q);
	for (int i = 1; i <= q; i ++)
	{
		LL l, r, del;
		scanf("%lld%lld", &l, &r);
		del = r - l + 1;
		int pos = lower_bound(A + 1, A + n, del) - A - 1;
		printf("%lld%c", 1LL * del * (n - pos) + Sum[pos], i == q ? '\n' : ' ');
	}
	return 0;
}