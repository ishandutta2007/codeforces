#include <cstdio>
#include <cassert>
#include <queue>
#include <vector>
const int N = 6e5;
int n, m, d[N], p[N];
std::vector<int> adj[N], ans;
bool chk[N];

bool check1()
{
	for (int i = 1; i <= n; ++i)
		if (adj[i].size() % 3 == 0)
		{
			ans.push_back(i);
			return true;
		}
	return false;
}

bool check2()
{
	for (int i = 1; i <= n; ++i)
		chk[i] = false;
	for (int i = 1; i <= n; ++i)
		if (!chk[i] && adj[i].size() % 3 == 1)
		{
			chk[i] = true;
			d[i] = 1;
			p[i] = 0;
			std::queue<int> q;
			for (q.push(i); !q.empty(); q.pop())
			{
				int u = q.front();
				for (int v : adj[u])
					if (!chk[v])
					{
						chk[v] = true;
						d[v] = d[u] + 1;
						p[v] = u;
						q.push(v);
						if (adj[v].size() % 3 == 1)
						{
							while (v != 0)
							{
								ans.push_back(v);
								v = p[v];
							}
							return true;
						}
					}
			}
		}
	return false;
}

bool check3()
{
	for (int i = 1; i <= n; ++i)
		chk[i] = false;
	for (int i = 1; i <= n; ++i)
		if (!chk[i] && adj[i].size() % 3 == 2)
		{
			chk[i] = true;
			d[i] = 1;
			p[i] = 0;
			std::queue<int> q;
			for (q.push(i); !q.empty(); q.pop())
			{
				int u = q.front();
				for (int v : adj[u])
					if (adj[v].size() % 3 == 2)
						if (!chk[v])
						{
							chk[v] = true;
							d[v] = d[u] + 1;
							p[v] = u;
							q.push(v);
						}
						else if (v != p[u])
						{
							while (true)
							{
								ans.push_back(v);
								v = p[v];
								if (u == v)
									break;
								ans.push_back(u);
								u = p[u];
								if (u == v)
									break;
							}
							ans.push_back(u);
							return true;
						}
			}
		}
	return false;
}

bool check4()
{
	for (int i = 1; i <= n; ++i)
		chk[i] = false;
	for (int i = 1; i <= n; ++i)
		if (!chk[i] && adj[i].size() % 3 == 1)
		{
			chk[i] = true;
			ans.push_back(i);
			int cnt = 0;
			for (int u : adj[i])
				if (!chk[u])
				{
					chk[u] = true;
					d[u] = 1;
					p[u] = i;
					std::queue<int> q;
					bool flag = false;
					for (q.push(u); !q.empty(); q.pop())
					{
						int u = q.front();
						for (int v : adj[u])
							if (!chk[v])
							{
								chk[v] = true;
								d[v] = d[u] + 1;
								p[v] = u;
								q.push(v);
							}
							else if (!flag && v != p[u])
							{
								flag = true;
								for (int v = u; v != i; v = p[v])
									ans.push_back(v);
							}
					}
					if (++cnt == 2)
						break;
				}
			return true;
		}
	// this should never happens
	assert(false);
	return false;
}

void print_ans()
{
	if (ans.size() < n)
	{
		printf("Yes\n%d\n", n - ans.size());
		for (int i = 1; i <= n; ++i)
			chk[i] = false;
		for (int x : ans)
			chk[x] = true;
		for (int i = 1; i <= n; ++i)
			if (!chk[i])
				printf("%d ", i);
		printf("\n");
	}
	else 
		printf("No\n");
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		adj[i].clear();
	for (int i = 1; i <= m; ++i)
	{
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans.clear();
	if (check1() || check2() || check3() || check4())
		print_ans();
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve();
}