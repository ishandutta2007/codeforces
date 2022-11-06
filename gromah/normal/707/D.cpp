#include <cstdio>
#include <vector>
using namespace std;
#define N 1000 + 5
#define M 100000 + 5

int n, m, q, Map[N][N], Sum[N], Flag[N], Op[M][3], Ans[M];
bool Done[M];
vector <int> Vec[M];

void dfs(int z)
{
	if (Op[z][0] && Op[z][0] <= 2)
	{
		int x = Op[z][1], y = Op[z][2];
		int w = Map[x][y] ^ Flag[x];
		if (!w && Op[z][0] == 1)
			Ans[z] ++, Sum[x] ++, Map[x][y] ^= 1, Done[z] = 1;
		else if (w && Op[z][0] == 2)
			Ans[z] --, Sum[x] --, Map[x][y] ^= 1, Done[z] = 1;
	}
	else if (Op[z][0] == 3)
	{
		int x = Op[z][1];
		Ans[z] -= Sum[x];
		Flag[x] ^= 1;
		Sum[x] = m - Sum[x];
		Ans[z] += Sum[x];
	}
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		Ans[d] = Ans[z];
		dfs(d);
	}
	if (Op[z][0] && Op[z][0] <= 2)
	{
		int x = Op[z][1], y = Op[z][2];
		int w = Map[x][y] ^ Flag[x];
		if (Done[z] && Op[z][0] == 1)
			Sum[x] --, Map[x][y] ^= 1;
		else if (Done[z] && Op[z][0] == 2)
			Sum[x] ++, Map[x][y] ^= 1;
	}
	else if (Op[z][0] == 3)
	{
		int x = Op[z][1];
		Flag[x] ^= 1;
		Sum[x] = m - Sum[x];
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int t = 1, cur = 0; t <= q; t ++)
	{
		int type;
		scanf("%d", &type);
		Op[t][0] = type & 3;
		if (type <= 2)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			Op[t][1] = x, Op[t][2] = y;
		}
		else if (type == 3)
		{
			int x;
			scanf("%d", &x);
			Op[t][1] = x;
		}
		else if (type == 4)
		{
			int k;
			scanf("%d", &k);
			cur = k;
		}
		Vec[cur].push_back(t);
		cur = t;
	}
	dfs(0);
	for (int i = 1; i <= q; i ++)
		printf("%d\n", Ans[i]);
	return 0;
}