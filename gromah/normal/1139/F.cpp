#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define mp make_pair

int n, m, sz, cnt, P[N], S[N], B[N], Inc[N], Pref[N], Ans[N], T[N << 2], Tree[2][N << 2];

struct Event
{
	int x, y, op, id;
	Event() {}
	Event(int x, int y, int op, int id) : x(x), y(y), op(op), id(id) {}
	bool operator < (const Event &obj) const
	{
		return mp(x, op) < mp(obj.x, obj.op);
	}
}E[(N) * 6];

int Calc(int *tree, int x)
{
	int res = 0;
	for (; x; x -= (x & -x))
		res += tree[x];
	return res;
}

void Add(int *tree, int x, int k)
{
	for (; x <= sz; x += (x & -x))
		tree[x] += k;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d", P + i);
	for (int i = 1; i <= n; i ++)
		scanf("%d", S + i);
	for (int i = 1; i <= n; i ++)
		scanf("%d", B + i);
	for (int i = 1; i <= m; i ++)
		scanf("%d", Inc + i);
	for (int i = 1; i <= m; i ++)
		scanf("%d", Pref + i);
	for (int i = 1; i <= n; i ++)
	{
		int p = P[i], s = S[i], b = B[i];
		E[++ cnt] = Event(p, p + b, 0, 1);
		E[++ cnt] = Event(p, b - p + 1, 1, -1);
		E[++ cnt] = Event(s + 1, p + b, 0, -1);
		E[++ cnt] = Event(s + 1, b - p + 1, 1, 1);
		T[++ sz] = p + b, T[++ sz] = b - p + 1;
	}
	for (int i = 1; i <= m; i ++)
	{
		int inc = Inc[i], pref = Pref[i];
		E[++ cnt] = Event(inc, inc + pref, 2, i);
		E[++ cnt] = Event(inc, pref - inc, 3, i);
		T[++ sz] = inc + pref, T[++ sz] = pref - inc;
	}
	sort(T + 1, T + sz + 1);
	sz = unique(T + 1, T + sz + 1) - T - 1;
	for (int i = 1; i <= cnt; i ++)
		E[i].y = lower_bound(T + 1, T + sz + 1, E[i].y) - T;
	sort(E + 1, E + cnt + 1);
	for (int i = 1; i <= cnt; i ++)
	{
		if (E[i].op & 2)
			Ans[E[i].id] += Calc(Tree[E[i].op & 1], E[i].y);
		else Add(Tree[E[i].op], E[i].y, E[i].id);
	}
	for (int i = 1; i <= m; i ++)
		printf("%d%c", Ans[i], i == m ? '\n' : ' ');
	return 0;
}