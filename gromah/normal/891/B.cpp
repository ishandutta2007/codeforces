#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 22 + 5

int n, A[N], Ord[N], Rank[N], Ans[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, [&] (int a, int b) {return A[a] < A[b];});
	for (int i = 1; i <= n; i ++)
		Rank[Ord[i]] = i;
	for (int i = 1; i <= n; i ++)
		Ans[i] = A[Ord[Rank[i] % n + 1]];
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Ans[i], i == n ? '\n' : ' ');
	return 0;
}