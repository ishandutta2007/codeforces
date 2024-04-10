#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 50 + 5

int n, m;
char s[N][N];

struct Opt
{
	int x, y;
	Opt (int _x = 0, int _y = 0)
	{
		x = _x, y = _y;
	}
	void out()
	{
		printf("%d %d\n", x, y);
	}
};

vector <Opt> Vec;

void Handle(int u, int v)
{
	Vec.push_back(Opt(u, v));
	if (s[u][v] == 'L')
	{
		s[u][v] = s[u][v + 1] = 'U';
		s[u + 1][v] = s[u + 1][v + 1] = 'D';
	}
	else
	{
		s[u][v] = s[u + 1][v] = 'L';
		s[u][v + 1] = s[u + 1][v + 1] = 'R';
	}
}

void Handle_r(int u, int v)
{
	if (u == 1 || s[u - 1][v] == 'R') return ;
	if (s[u - 1][v] == 'L')
	{
		Handle(u - 1, v);
		return ;
	}
	if (v < m && s[u - 1][v] == 'D' && s[u - 1][v + 1] == 'D')
	{
		Handle(u - 2, v);
		Handle(u - 1, v);
		Handle_r(u - 2, v);
	}
}

void Handle_c(int u, int v)
{
	if (v == 1 || s[u][v - 1] == 'D') return ;
	if (s[u][v - 1] == 'U')
	{
		Handle(u, v - 1);
		return ;
	}
	if (u < n && s[u][v - 1] == 'R' && s[u + 1][v - 1] == 'R')
	{
		Handle(u, v - 2);
		Handle(u, v - 1);
		Handle_c(u, v - 2);
	}
}

void Solve()
{
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	if (n & 1)
	{
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if (s[i][j] == 'L')
					Handle_r(i, j);
	}
	else
	{
		for (int j = 1; j <= m; j ++)
			for (int i = 1; i <= n; i ++)
				if (s[i][j] == 'U')
					Handle_c(i, j);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	Solve();
	int sz = Vec.size();
	Solve();
	reverse(Vec.begin() + sz, Vec.end());
	printf("%d\n", Vec.size());
	for (int i = 0; i < Vec.size(); i ++)
		Vec[i].out();
	return 0;
}