#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5
#define K 1000000000
#define mp make_pair

int n, k, T[N], B[N], Ord[N];
LL sum, ans;

priority_queue <int, vector<int>, greater<int> > Q;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d", T + i, B + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, [](int u, int v) {
		return B[u] > B[v];
	});
	for (int i = 1; i <= n; i ++)
	{
		if (Q.size() == k)
			sum -= Q.top(), Q.pop();
		sum += T[Ord[i]];
		Q.push(T[Ord[i]]);
		LL tmp = sum * B[Ord[i]];
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}