#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
const int N = 5e3, Q = 7e4;
int n, q, a[N], ans[Q];
std::vector<std::pair<int,int>> move;
struct data {
	std::vector<int> v;
	std::map<std::pair<int,int>,int> map;
} node[N*4];

void build(int l, int r, int id = 1)
{
	std::vector<int> &v = node[id].v;
	if (l == r)
	{
		v.push_back(a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(l, m, id * 2);
	build(m + 1, r, id * 2 + 1);
	std::vector<int> &v1 = node[id * 2].v;
	std::vector<int> &v2 = node[id * 2 + 1].v;
	v.resize(r - l + 1);
	std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
}

int solve(int l, int r, int id = 1)
{
	std::vector<int> &v = node[id].v;
	int x = std::lower_bound(v.begin(), v.end(), l) - v.begin();
	int y = std::upper_bound(v.begin(), v.end(), r) - v.begin();
	if (x == v.size() || x == y)
		return -1;
	if (x + 1 == y)
		return v[x];
	std::map<std::pair<int,int>,int> &map = node[id].map;
	if (map.find({x, y}) == map.end())
	{
		int a = solve(l, r, id * 2);
		int b = solve(l, r, id * 2 + 1);
		if (a != -1 && b != -1)
		{
			move.push_back({a, b});
			map[{x, y}] = move.size() + n;
		}
		else
			map[{x, y}] = std::max(a, b);
	}
	return map[{x, y}];
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		int val; scanf("%d", &val);
		a[val] = i;
	}
	build(1, n);
	for (int i = 1; i <= q; ++i)
	{
		int l, r; scanf("%d%d", &l, &r);
		ans[i] = solve(l, r);
	}
	printf("%d\n", move.size() + n);
	for (std::pair<int,int> p : move)
		printf("%d %d\n", p.first, p.second);
	for (int i = 1; i <= q; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}