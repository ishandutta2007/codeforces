#include <iostream>
#include <vector>
const int N = 50005, K = 505;
unsigned int n, k, cnt[N][K];
std::vector<int> adj[N];

long long DFS(int u = 1, int p = 0)
{
	long long res = 0;
	cnt[u][0] = 1;
	for (int v : adj[u])
	{
		if (v == p)
			continue;
		res += DFS(v, u);
		for (int i = 1; i <= k; ++i)
			res += cnt[v][i - 1] * cnt[u][k - i];
		for (int i = 1; i <= k; ++i)
			cnt[u][i] += cnt[v][i - 1];
	}
	return res;
}

int main() 
{
	std::cin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		int a, b; std::cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	std::cout << DFS();
	return 0;
}