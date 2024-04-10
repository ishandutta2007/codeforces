#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int SIZE = 300003;
bool chk[SIZE];
int d1[SIZE], d2[SIZE];
vector<int> adj[SIZE];

void bfs(int s, int* d)
{
	queue<int> q;
	for (q.push(s); !q.empty(); q.pop())
	{
		int u = q.front();
		for (int v : adj[u])
			if (d[v] == 0 && v != s)
			{
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
}

int bfs(int s, int t, int* d1, int* d2)
{
	fill(chk, chk + SIZE, false);
	queue<int> q;
	int cnt = 0;
	for (q.push(s); !q.empty(); q.pop())
	{
		int u = q.front();
		chk[u] = true;
		for (int v : adj[u])
			if (d1[v] + d2[v] != d1[t] && !chk[v])
				q.push(v);
		++cnt;
	}
	return cnt;
}

int main()
{
	int n, x, y; cin >> n >> x >> y;
	for (int i = 1; i <= n - 1; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(x, d1);
	bfs(y, d2);
	cout << 1LL * n * (n - 1) - 1LL * bfs(x, y, d1, d2) * bfs(y, x, d2, d1);
	return 0;
}