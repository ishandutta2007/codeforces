#include <cstdio>
#include <algorithm>
#include <set>
const int N = 2e5;
int n, k, m;
struct TNode
{
	int l, r, sum, cnt, max;
} node[N * 8];

void update(int id)
{
	node[id].sum = node[id * 2].sum + node[id * 2 + 1].sum;
	node[id].cnt = node[id * 2].cnt + node[id * 2 + 1].cnt;
	node[id].max = std::max(node[id * 2].max + node[id * 2 + 1].sum, node[id * 2 + 1].max);
}

void build(int l, int r, int id = 1)
{
	node[id].l = l;
	node[id].r = r;
	int mid = (l + r) / 2;
	if (l < r - 1)
	{
		build(l, mid, id * 2);
		build(mid, r, id * 2 + 1);
		update(id);
		return;
	}
	if (l == n * 2)
		node[id].sum = n - 1;
	else 
		node[id].sum = -1;
	node[id].cnt = 0;
	node[id].max = node[id].sum;
}

void modify(int pos, int val, int id = 1)
{
	if (pos < node[id].l || node[id].r - 1 < pos)
		return;
	if (node[id].l < node[id].r - 1)
	{
		modify(pos, val, id * 2);
		modify(pos, val, id * 2 + 1);
		update(id);
		return;
	}
	node[id].sum += val;
	node[id].cnt += val;
	node[id].max += val;
}

int query(int id = 1)
{
	if (node[id].l < node[id].r - 1)
		if (node[id * 2 + 1].cnt)
			return std::max(node[id * 2].max + node[id * 2 + 1].sum, query(id * 2 + 1));
		else
			return query(id * 2) + node[id * 2 + 1].sum;
	return node[id].sum;
}

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	build(1, n * 2 + 1);
	std::set<std::pair<int,int>> set;
	for (int i = 1; i <= m; ++i)
	{
		int x, y; scanf("%d%d", &x, &y);
		std::pair<int,int> pawn = {x, y};
		int pos = std::abs(k - x) + y;
		if (set.find(pawn) == set.end())
		{
			set.insert(pawn);
			modify(pos, 1);
		}
		else 
		{
			set.erase(pawn);
			modify(pos, -1);
		}
		printf("%d\n", std::max(query(), 0));
	}
}