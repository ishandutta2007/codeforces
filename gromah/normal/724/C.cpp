#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
#define N 200000 + 5
#define K 100000
#define mp make_pair

int n, m, k, X[N], Y[N];
LL Ans[N];
vector <int> Vec[2][N];
map <Pii, bool> Flag;

inline int Abs(int x)
{
	return x > 0 ? x : -x;
}

inline void dfs(int u, int v, int dir, LL cur)
{
	if (Flag[mp(u, v)]) return ;
	Flag[mp(u, v)] = 1;
	int tmp = !dir ? u + v : u + K - v;
	for (int i = 0; i < Vec[dir][tmp].size(); i ++)
	{
		int z = Vec[dir][tmp][i];
		if (Ans[z] != -1) continue ;
		int x = X[z], y = Y[z];
		Ans[z] = cur + Abs(u - x);
	}
	if (dir == 0)
	{
		if (u == 0 || v == m)
		{
			int del = min(n - u, v);
			dfs(u + del, v - del, 1, cur + del);
		}
		else
		{
			int del = min(u, m - v);
			dfs(u - del, v + del, 1, cur + del);
		}
	}
	else if (dir == 1)
	{
		if (u == 0 || v == 0)
		{
			int del = min(n - u, m - v);
			dfs(u + del, v + del, 0, cur + del);
		}
		else
		{
			int del = min(u, v);
			dfs(u - del, v - del, 0, cur + del);
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, x, y; i <= k; i ++)
	{
		scanf("%d%d", &x, &y);
		X[i] = x, Y[i] = y;
		Vec[0][x + y].push_back(i);
		Vec[1][x + K - y].push_back(i);
		Ans[i] = -1;
	}
	dfs(0, 0, 1, 0);
	for (int i = 1; i <= k; i ++)
		printf("%I64d\n", Ans[i]);
	return 0;
}