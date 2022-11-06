#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200 + 5

int n, S[N], D[N], Ord[N];

inline bool cmp(int u, int v)
{
	return S[u] < S[v];
}

inline bool Check(int u, int v)
{
	int l = max(S[u], S[v]), r = min(D[u], S[v] + D[v] - 1);
	return l > r;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d", S + i, D + i);
		bool ok = 1;
		for (int j = 1; ok && j < i; j ++)
			ok = Check(j, i);
		if (ok)
		{
			D[i] += S[i] - 1;
			Ord[i] = i;
			sort(Ord + 1, Ord + i + 1, cmp);
			continue ;
		}
		for (int j = 1; !ok && j < i; j ++)
			if (S[Ord[j]] - D[Ord[j - 1]] - 1 >= D[i])
			{
				S[i] = D[Ord[j - 1]] + 1;
				D[i] += S[i] - 1;
				ok = 1;
			}
		if (!ok) S[i] = D[Ord[i - 1]] + 1, D[i] += S[i] - 1;
		Ord[i] = i;
		sort(Ord + 1, Ord + i + 1, cmp);
	}
	for (int i = 1; i <= n; i ++)
		printf("%d %d\n", S[i], D[i]);
	return 0;
}