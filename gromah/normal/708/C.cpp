#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 400000 + 5

int n, Size[N], W[N], Fa[N], Up[N], Down[N];
vector <int> Vec[N];

inline int getint()
{
	char ch = '\n';
	for (; ch > '9' || ch < '0'; ch = getchar()) ;
	int res = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

inline void dfs(int z)
{
	Size[z] = 1;
	int Max = 0;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == Fa[z]) continue ;
		Fa[d] = z;
		dfs(d);
		Down[z] = max(Down[z], Down[d]);
		Size[z] += Size[d];
		if (Size[d] > Max)
			Max = Size[d], W[z] = d;
	}
	if (n - Size[z] > Max)
		Max = n - Size[z], W[z] = Fa[z];
	if (Size[z] <= n / 2)
		Down[z] = Size[z];
}

inline void _dfs(int z)
{
	int Max_1 = 0, Max_2 = 0;
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == Fa[z]) continue ;
		Max_2 = max(Max_2, Down[d]);
		if (Max_2 > Max_1) swap(Max_1, Max_2);
	}
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == Fa[z]) continue ;
		Up[d] = Up[z];
		if (Down[d] == Max_1)
			Up[d] = max(Up[d], Max_2);
		else Up[d] = max(Up[d], Max_1);
		if (n - Size[d] <= n / 2)
			Up[d] = max(Up[d], n - Size[d]);
		_dfs(d);
	}
}

int main()
{
	n = getint();
	for (int i = 1; i < n; i ++)
	{
		int u = getint(), v = getint();
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	dfs(1);
	_dfs(1);
	for (int i = 1; i <= n; i ++)
	{
		if (W[i] == Fa[i])
		{
			if (n - Size[i] <= n / 2) putchar('1');
				else putchar('0' + (n - Size[i] - Up[i] <= n / 2));
		}
		else
		{
			if (Size[W[i]] <= n / 2) putchar('1');
				else putchar('0' + (Size[W[i]] - Down[W[i]] <= n / 2));
		}
		putchar(i == n ? '\n' : ' ');
	}
	return 0;
}