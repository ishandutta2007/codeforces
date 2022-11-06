#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
#define N 10 + 5
#define M 200000 + 5

int n, m, ans, A[N][M], Suf[N], Stack[N], Ans[N];
map<Pii, int> Map;

inline int GetId(int a, int b)
{
	static int tot = 0;
	Pii p = make_pair(a, b);
	if (Map.count(p) == 0)
		Map.emplace(p, ++ tot);
	return Map.at(p);
}

void dfs(int z, int dep, int sum)
{
	if (dep > n)
		return ;
	map<Pii, int>::iterator bg = Map.lower_bound(make_pair(z, 0)), ed = Map.upper_bound(make_pair(z, M)), it;
	int pos = A[dep][0], cnt = 0;
	for (it = ed; it != bg; )
	{
		it --, cnt ++;
		if (it->first.second == pos)
			pos --;
		else break;
	}
	if (pos > 0)
	{
		int tmp = sum + A[dep][pos] + Suf[dep + 1];
		if (tmp > ans)
		{
			ans = tmp;
			for (int i = 1; i < dep; i ++)
				Ans[i] = Stack[i];
			Ans[dep] = pos;
			for (int i = dep + 1; i <= n; i ++)
				Ans[i] = A[i][0];
		}
	}
	for (it = bg; it != ed; it ++)
	{
		Stack[dep] = it->first.second;
		dfs(it->second, dep + 1, sum + A[dep][it->first.second]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j <= A[i][0]; j ++)
			scanf("%d", A[i] + j);
	for (int i = n; i; i --)
		Suf[i] = Suf[i + 1] + A[i][A[i][0]];
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++)
	{
		int u = 0;
		for (int j = 1, a; j <= n; j ++)
		{
			scanf("%d", &a);
			u = GetId(u, a);
		}
	}
	dfs(0, 1, 0);
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Ans[i], i == n ? '\n' : ' ');
	return 0;
}