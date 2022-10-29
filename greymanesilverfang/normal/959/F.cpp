// #math 

#include <algorithm>
#include <cstdio>
#include <set>
const int N = 1e5+1, INF = 1e9+7;
struct TQuery { int l, x, idx; };
int a[N], ans[N];
TQuery b[N];
inline bool operator < (TQuery lhs, TQuery rhs) { return lhs.l < rhs.l; }

int main()
{
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= q; ++i)
		scanf("%d%d", &b[i].l, &b[i].x);
	for (int i = 1; i <= q; ++i)
		b[i].idx = i;
	std::sort(b + 1, b + q + 1);
	std::set<int> s;
	s.insert(0);
	int res = 1, pos = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (s.find(a[i]) != s.end())
			res = res * 2 % INF;
		else for (auto x : s)
			s.insert(x ^ a[i]);
		while (pos <= q && b[pos].l == i)
		{
			if (s.find(b[pos].x) != s.end())
				ans[b[pos].idx] = res;
			++pos;
		}
	}
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}