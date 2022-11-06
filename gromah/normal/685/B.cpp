#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, T, Pre[N], Fa[N], Deg[N], Size[N], Max[N], Up[N], Ans[N], q[N];

inline int getint()
{
	char ch = '\n';
	for (; ch > '9' || ch < '0'; ch = getchar()) ;
	int res = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
	return res;
}

inline int Find(int x)
{
	return Fa[x] == x ? x : Fa[x] = Find(Fa[x]);
}

inline void Prepare()
{
	for (int i = 1; i < n; i ++)
	{
		int z = q[i];
		Size[Pre[z]] += (++ Size[z]);
		Max[Pre[z]] = (Max[Pre[z]] && Size[Max[Pre[z]]] > Size[z]) ? Max[Pre[z]] : z;
	}
	Size[1] ++;
	for (int i = 1; i < n; i ++)
	{
		int z = q[i];
		int x = Max[z];
		if (!x) Up[z] = z;
		else for (Up[z] = Up[x]; Up[z] && Size[x] * 2 > Size[Up[z]]; Up[z] = Fa[Up[z]]) ;
		for (int j = Find(Up[z]); j; j = Find(Pre[j]))
		{
			if (Size[j] > Size[z] * 2) break ;
			Ans[j] = z, Fa[j] = Find(Pre[j]);
		}
	}
}

int main()
{
	n = getint(), T = getint();
	for (int i = 2; i <= n; i ++)
	{
		Pre[i] = getint();
		Deg[Pre[i]] ++; 
	}
	int l = 1, r = 0;
	for (int i = 1; i <= n; i ++)
		if (!Deg[i]) q[++ r] = i;
	while (l <= r)
	{
		int z = q[l ++];
		if (z == 1) continue ;
		Deg[Pre[z]] --;
		if (!Deg[Pre[z]]) q[++ r] = Pre[z];
	}
	for (int i = 1; i <= n; i ++)
		Fa[i] = i;
	Prepare();
	for (int i = 1; i <= n; i ++)
		if (!Ans[i]) Ans[i] = i;
	while (T --)
		printf("%d\n", Ans[getint()]);
	return 0;
}