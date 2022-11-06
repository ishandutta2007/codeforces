#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define mp make_pair

int n, k, s, t, Pos[N], Min[N];

struct Car
{
	int c, v;
	Car (int _c = 0, int _v = 0) {c = _c, v = _v;}
	bool operator < (const Car a) const
	{
		return mp(v, c) < mp(a.v, a.c);
	}
}E[N];

inline bool Check(int v)
{
	int ret = t;
	for (int i = 1; i <= k; i ++)
	{
		int x = 2 * (Pos[i] - Pos[i - 1]) - v;
		int y = v - (Pos[i] - Pos[i - 1]);
		if (y < 0) return 0;
		if (x < 0) x = 0, y = Pos[i] - Pos[i - 1];
		int tmp = 2 * x + y;
		ret -= tmp;
		if (ret < 0) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d%d%d", &n, &k, &s, &t);
	for (int i = 1, c, v; i <= n; i ++)
	{
		scanf("%d%d", &c, &v);
		E[i] = Car(c, v);
	}
	sort(E + 1, E + n + 1);
	for (int i = n; i; i --)
		Min[i] = i == n ? E[i].c : min(Min[i + 1], E[i].c);
	for (int i = 1; i <= k; i ++)
		scanf("%d", Pos + i);
	sort(Pos + 1, Pos + k + 1);
	Pos[++ k] = s;
	int l = 1, r = n + 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (Check(E[mid].v)) r = mid;
		else l = mid + 1;
	}
	if (l > n) puts("-1");
	else printf("%d\n", Min[l]);
	return 0;
}