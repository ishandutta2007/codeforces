#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, k, cnt, root, Size[N], Max[N], Point[N];
bool Flag[N];
vector <int> Vec[N], A[N];

struct Node
{
	int id, cnt;
	Node (int _id = 0, int _cnt = 0)
	{
		id = _id, cnt = _cnt;
	}
	bool operator < (const Node a) const
	{
		return cnt < a.cnt;
	}
}X[2];

priority_queue <Node> Q;

inline void dfs(int z, int fa)
{
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == fa) continue ;
		dfs(d, z);
		Size[z] += Size[d];
		Max[z] = max(Max[z], Size[d]);
	}
	Max[z] = max(Max[z], k * 2 - Size[z]);
}

inline void DFS(int z, int fa, int id)
{
	if (Flag[z]) A[id].push_back(z);
	for (int i = 0; i < Vec[z].size(); i ++)
	{
		int d = Vec[z][i];
		if (d == fa) continue ;
		DFS(d, z, id);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		Vec[u].push_back(v);
		Vec[v].push_back(u);
	}
	for (int i = 1, x; i <= k * 2; i ++)
	{
		scanf("%d", &x);
		Size[x] = Flag[x] = 1;
	}
	dfs(1, 0);
	for (root = 1; root <= n; root ++)
		if (Max[root] <= k) break ;
	printf("1\n%d\n", root);
	for (int i = 0; i < Vec[root].size(); i ++)
	{
		int d = Vec[root][i];
		DFS(d, root, i);
		Q.push(Node(i, A[i].size()));
	}
	if (Flag[root])
	{
		int x = Vec[root].size();
		A[x].push_back(root);
		Q.push(Node(x, 1));
	}
	for (int i = 1; i <= k; i ++)
	{
		for (int j = 0; j < 2; j ++)
		{
			X[j] = Q.top();
			Q.pop();
		}
		printf("%d %d %d\n", A[X[0].id][Point[X[0].id] ++], A[X[1].id][Point[X[1].id] ++], root);
		for (int j = 0; j < 2; j ++)
			if (-- X[j].cnt) Q.push(X[j]);
	}
	return 0;
}