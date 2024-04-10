#include <stack>
#include <cstdio>
using namespace std;
const int N = 1e5, M = 3e5;
bool chk[M];
struct TEdge
{
	int des, id;
	TEdge() {}
	TEdge(int des_, int id_) : des(des_), id(id_) {}
};
stack<TEdge> adj[N + 1];

void FindEuler()
{
	stack<int> st, res;
	int S = 1;
	st.push(S); 
	res.push(S);
	while (!st.empty())
	{
		int cur = st.top();
		if (!adj[cur].empty())
		{
			TEdge nxt = adj[cur].top();
			adj[cur].pop();
			if (!chk[nxt.id])
			{
				chk[nxt.id] = true;
				st.push(nxt.des);
			}
		}
		else
		{
			st.pop();
			if (!st.empty())
				res.push(st.top());
		}
	}
	printf("%d\n", res.size() - 1);
	while (res.size() > 1)
	{
		int v1 = res.top();
		res.pop();
		int v2 = res.top();
		res.pop();
		int v3 = res.top();
		printf("%d %d\n%d %d\n", v1, v2, v3, v2);
	}
}

int main() 
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].emplace(v, i);
		adj[v].emplace(u, i);
	}
	for (int i = 1, j = 0; i <= n; ++i)
		if (adj[i].size() & 1)
			if (j == 0)
				j = i;
			else
			{
				adj[i].emplace(j, m);
				adj[j].emplace(i, m);
				j = 0;
				++m;
			}
	if (m & 1)
		adj[1].emplace(1, m);
	FindEuler();
	return 0;
}