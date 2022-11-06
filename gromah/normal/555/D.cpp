#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n, m, Ord[N], Rank[N];
LL A[N], B[N];

inline bool cmp(int u, int v)
{
	return A[u] < A[v];
}

inline int dfs(int pos, LL l, int last, int op)
{
	if (n == 1) return 1;
	if ((op && pos == n) || (!op && pos == 1))
		return dfs(pos, l, last, op ^ 1);
	int t;
	if (op) t = upper_bound(A + pos + 1, A + n + 1, A[pos] + l) - A - 1;
		else t = n - (upper_bound(B + n - pos + 2, B + n + 1, B[n - pos + 1] + l) - B - 1) + 1;
	if (t == pos && last) return pos;
	if (t == last)
	{
		LL del = op ? A[t] - A[pos] : A[pos] - A[t];
		del *= 2;
		if (l >= del)
		{
			l %= del;
			return dfs(pos, l, last, op);
		}
	}
	if (op) return dfs(t, A[pos] + l - A[t], pos, op ^ 1);
		else return dfs(t, A[t] + l - A[pos], pos, op ^ 1);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%I64d", A + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, cmp);
	sort(A + 1, A + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		B[i] = -A[n - i + 1];
		Rank[Ord[i]] = i;
	}
	while (m --)
	{
		int pos;
		LL l;
		scanf("%d%I64d", &pos, &l);
		printf("%d\n", Ord[dfs(Rank[pos], l, 0, 1)]);
	}
	return 0;
}