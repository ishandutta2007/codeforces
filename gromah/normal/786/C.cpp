#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define M 262144 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, A[N], Next[N], Head[N], Tree[M], Ans[N];

struct Node
{
	int id, pos, step;
	Node (int _id = 0, int _pos = 0, int _step = 0)
	{
		id = _id, pos = _pos, step = _step;
	}
	bool operator < (const Node &a) const
	{
		return pos > a.pos;
	}
};

priority_queue <Node> Q;

inline void update(int x)
{
	Tree[x] = Tree[ls(x)] + Tree[rs(x)];
}

void Modify(int x, int l, int r, int t, int k)
{
	if (l == r)
	{
		Tree[x] += k;
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, t, k);
	else Modify(rs(x), mid + 1, r, t, k);
	update(x);
}

int Find(int x, int l, int r, int k)
{
	if (Tree[x] <= k) return r + 1;
	if (l == r) return l;
	int mid = l + r >> 1;
	if (Tree[ls(x)] <= k)
		return Find(rs(x), mid + 1, r, k - Tree[ls(x)]);
	else return Find(ls(x), l, mid, k);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Head[i] = n + 1;
		Q.push(Node(i, 1, 0));
	}
	for (int i = n; i; i --)
	{
		Next[i] = Head[A[i]];
		Head[A[i]] = i;
	}
	for (int i = 1; i <= n; i ++)
		if (Head[i] != n + 1)
			Modify(1, 1, n, Head[i], 1);
	for (int i = 1; i <= n && !Q.empty(); i ++)
	{
		while (!Q.empty() && Q.top().pos == i)
		{
			Node x = Q.top();
			Q.pop(), x.step ++;
			x.pos = Find(1, 1, n, x.id);
			if (x.pos > n)
				Ans[x.id] = x.step;
			else Q.push(x);
		}
		Modify(1, 1, n, i, -1);
		if (Next[i] <= n)
			Modify(1, 1, n, Next[i], 1);
	}
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Ans[i], i == n ? '\n' : ' ');
	return 0;
}