#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5
#define mp make_pair

int n, Min, cur, cnt, Ord[N], Rank[N];
LL A[N], B[N];

struct Node
{
	int id;
	LL ret;
	Node (int _id = 0, LL _ret = 0) {id = _id, ret = _ret;}
	bool operator < (const Node a) const
	{
		return mp(ret, 1LL * id) > mp(a.ret, 1LL * a.id);
	}
};

priority_queue <Node> Q;

inline bool cmp(int u, int v)
{
	return mp(A[u], -1LL * u) > mp(A[v], -1LL * v);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%I64d%I64d", A + i, B + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, cmp);
	for (int i = 1; i <= n; i ++)
		Rank[Ord[i]] = i;
	Ord[n + 1] = Rank[n + 1] = n + 1;
	Min = cnt = Rank[1], cur = Ord[Rank[1] + 1];
	for (int i = 1; i < Rank[1]; i ++)
	{
		int _i = Ord[i];
		Q.push(Node(_i, B[_i] - A[_i] + 1));
	}
	while (!Q.empty())
	{
		Node x = Q.top();
		if (A[1] < x.ret) break ;
		A[1] -= x.ret, cnt --;
		Q.pop();
		for (; cur <= n && A[1] < A[cur]; cur = Ord[Rank[cur] + 1])
			Q.push(Node(cur, B[cur] - A[cur] + 1)), cnt ++;
		Min = min(Min, cnt);
	}
	printf("%d\n", Min);
	return 0;
}