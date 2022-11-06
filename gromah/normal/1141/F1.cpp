#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1500 + 5
#define M 1125750 + 5
#define mp make_pair

int n, cnt, sz, Max, id, A[N], T[M << 1], Dp[M], Fa[M], Tree[N];

struct Segment
{
	int l, r, fix;
	Segment() {}
	Segment(int l, int r, int fix) : l(l), r(r), fix(fix) {}
	bool operator < (const Segment &obj) const
	{
		return mp(fix, r) < mp(obj.fix, obj.r);
	}
}S[M];

int Calc(int x)
{
	int id = 0;
	for (; x; x -= (x & -x))
		if (Dp[id] < Dp[Tree[x]])
			id = Tree[x];
	return id;
}

void Add(int x, int id)
{
	for (; x <= sz; x += (x & -x))
		if (Dp[Tree[x]] < Dp[id])
			Tree[x] = id;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		for (int j = i, sum = 0; j; j --)
		{
			sum += A[j];
			S[++ cnt] = Segment(j, i, sum);
		}
	}
	sort(S + 1, S + cnt + 1);
	for (int l = 1, r; l <= cnt; l = r)
	{
		for (r = l, sz = 0; r <= cnt && S[l].fix == S[r].fix; r ++)
			T[++ sz] = S[r].l, T[++ sz] = S[r].r;
		sort(T + 1, T + sz + 1);
		sz = unique(T + 1, T + sz + 1) - T - 1;
		for (int i = 1; i <= sz; i ++)
			Tree[i] = 0;
		for (int i = l; i < r; i ++)
		{
			int le = lower_bound(T + 1, T + sz + 1, S[i].l) - T;
			int ri = lower_bound(T + 1, T + sz + 1, S[i].r) - T;
			Fa[i] = Calc(le - 1), Dp[i] = Dp[Fa[i]] + 1;
			Add(ri, i);
			if (Dp[i] > Max)
				Max = Dp[i], id = i;
		}
	}
	printf("%d\n", Max);
	for (; id; id = Fa[id])
		printf("%d %d\n", S[id].l, S[id].r);
	return 0;
}