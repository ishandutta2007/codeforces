#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define M 200000 + 5
#define K 524288 + 5
#define MAXN 35
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, m, q, E[M][2], Sum[K], Id_l[N], Id_r[N];
bool Ans[M];

struct Queries
{
	int l, r, s, t;
}A[M];

vector <int> Vec[K];
vector <int> Last_l[N];
vector <int> Last_r[N];

struct Bitset
{
	unsigned int num[MAXN];
	void clear()
	{
		for (int i = 0; i < MAXN; i ++) num[i] = 0;
	}
	void Modify(int x)
	{
		int t = x >> 5, p = x & 31;
		num[t] |= (1 << p);
	}
	bool Query(int x)
	{
		int t = x >> 5, p = x & 31;
		return (num[t] >> p) & 1;
	}
	void Or(Bitset a)
	{
		for (int i = 0; i < MAXN; i ++)
			num[i] |= a.num[i];
	}
	bool All_zero()
	{
		for (int i = 0; i < MAXN; i ++)
			if (num[i]) return 0;
		return 1;
	}
}Dp[M];

inline void Add(int x, int l, int r, int s, int t, int id)
{
	Sum[x] ++;
	if (l == s && r == t)
	{
		Vec[x].push_back(id);
		return; 
	}
	int mid = l + r >> 1;
	if (t <= mid) Add(ls(x), l, mid, s, t, id);
	else if (s > mid) Add(rs(x), mid + 1, r, s, t, id);
	else Vec[x].push_back(id);
}

inline void Solve(int x, int l, int r)
{
	if (!Sum[x]) return ;
	int mid = l + r >> 1;
	if (l < r)
	{ 
		Solve(ls(x), l, mid);
		Solve(rs(x), mid + 1, r);
	}
	if (!Vec[x].size()) return ;
	for (int i = l; i <= r; i ++)
		Dp[i].clear();
	for (int i = mid + 1; i <= r; i ++)
	{
		int u = E[i][0], v = E[i][1];
		int _u = Id_r[u] == x ? Last_r[u][Last_r[u].size() - 1] : -1;
		int _v = Id_r[v] == x ? Last_r[v][Last_r[v].size() - 1] : -1;
		Dp[i].Modify(u), Dp[i].Modify(v);
		if (~_u) Dp[i].Or(Dp[_u]);
		if (~_v) Dp[i].Or(Dp[_v]);
		if (Id_r[u] != x)
			Id_r[u] = x, Last_r[u].clear();
		if (Id_r[v] != x)
			Id_r[v] = x, Last_r[v].clear();
		Last_r[u].push_back(i);
		Last_r[v].push_back(i);
	}
	for (int i = mid; i >= l; i --)
	{
		int u = E[i][0], v = E[i][1];
		int _u = Id_l[u] == x ? Last_l[u][Last_l[u].size() - 1] : -1;
		int _v = Id_l[v] == x ? Last_l[v][Last_l[v].size() - 1] : -1;
		Dp[i].Modify(u), Dp[i].Modify(v);
		if (~_u) Dp[i].Or(Dp[_u]);
		if (~_v) Dp[i].Or(Dp[_v]);
		if (Id_l[u] != x)
			Id_l[u] = x, Last_l[u].clear();
		if (Id_l[v] != x)
			Id_l[v] = x, Last_l[v].clear();
		Last_l[u].push_back(i);
		Last_l[v].push_back(i);
	}
	for (int i = 0; i < Vec[x].size(); i ++)
	{
		int z = Vec[x][i], u, v;
		bool ok = 0;
		if (Id_l[A[z].s] != x) u = 0;
		else
		{
			int l = -1, r = Last_l[A[z].s].size() - 1;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if (Last_l[A[z].s][mid] >= A[z].l) l = mid;
				 	else r = mid - 1;
			}
			if (!~l) u = 0;
				else u = Last_l[A[z].s][l];
		}
		ok |= Dp[u].Query(A[z].t);
		if (Id_r[A[z].t] != x) v = 0;
		else
		{
			int l = -1, r = Last_r[A[z].t].size() - 1;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if (Last_r[A[z].t][mid] <= A[z].r) l = mid;
				 	else r = mid - 1;
			}
			if (!~l) v = 0;
				else v = Last_r[A[z].t][l];
		}
		ok |= Dp[v].Query(A[z].s);
		for (int i = 0; !ok && i < MAXN; i ++)
			ok |= Dp[u].num[i] & Dp[v].num[i];
		Ans[z] = ok;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i ++)
		scanf("%d%d", E[i], E[i] + 1);
	for (int i = 1; i <= q; i ++)
	{
		scanf("%d%d%d%d", &A[i].l, &A[i].r, &A[i].s, &A[i].t);
		Add(1, 1, m, A[i].l, A[i].r, i);
	}
	Solve(1, 1, m);
	for (int i = 1; i <= q; i ++)
		puts(Ans[i] ? "Yes" : "No");
	return 0;
}