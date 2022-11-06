#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define K 600 + 5
#define N 100000 + 5
#define INF 0x7fffffff

int n, k, cnt, cur, tot, size, X[N], Y[N], A[N], B[N], Ord[N], Pos[K];
long long Ans[N];
vector <int> Vec[K];

inline bool cmp(int u, int v)
{
	return make_pair(X[u], u) > make_pair(X[v], v);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d", X + i, Y + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, cmp);
	for (int t = 1, first = 0; t <= n; t ++)
	{
		int z = Ord[t];
		for (int j = k - 1, s = cur; ~j; j --)
		{
			if (!first || X[z] + j < Pos[cnt == 0 ? K - 1 : cnt - 1])
			{
				first = 1;
				Pos[cnt] = X[z] + j;
				Vec[cnt].push_back(Y[z]);
				cnt = cnt == K - 1 ? 0 : cnt + 1;
			}
			else
			{
				for (; Pos[s] > X[z] + j; s = s == K - 1 ? 0 : s + 1) ;
				Vec[s].push_back(Y[z]);
			}
		}
		for (; (X[z] + k <= Pos[cur] || t == n) && cur != cnt; cur = cur == K - 1 ? 0 : cur + 1)
		{
			int m = 0, t_a = 1, t_b = 1, c = 0;
			for (int i = 0; i < Vec[cur].size(); i ++)
				A[++ m] = Vec[cur][i];
			Vec[cur].clear();
			sort(A + 1, A + m + 1);
			A[m + 1] = A[m] + k;
			for (int i = 1; i <= m + 1; i ++)
				B[i] = A[i] + k;
			while (t_a <= m || t_b <= m)
			{
				if (t_a <= m && (t_b > m || B[t_b] > A[t_a]))
					Ans[++ c] += min(A[t_a + 1], B[t_b]) - A[t_a ++];
				else Ans[-- c] += min(A[t_a], B[t_b + 1]) - B[t_b ++];
			}
		}
	}
	for (int i = 1; i <= n; i ++)
		printf("%I64d%c", Ans[i], i == n ? '\n' : ' ');
	return 0;
}