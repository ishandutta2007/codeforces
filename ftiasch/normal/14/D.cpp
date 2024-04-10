// Codeforces Beta Round #14
// Problem D -- Two Paths
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 200
#define M (N + N - 1)

using namespace std;

int n, answer, first[N], size, begin[M], end[M], next[M], dist[N];
bool visit[N];

void insert_edge(int a, int b)
{
	size ++;
	begin[size] = a;
	end[size] = b;
	next[size] = first[a];
	first[a] = size;
}

void dfs(int pre, int u, int cnt, int &best)
{
	dist[u] = cnt;
	if(dist[u] > dist[best])
		best = u;
	for(int i = first[u]; i; i = next[i])
		if(!visit[end[i]] && end[i] != pre)
			dfs(u, end[i], cnt + 1, best);
}

int solve()
{
	memset(dist, -1, sizeof(dist));
	int answer = 0;
	for(int i = 0; i != n; ++ i)
		if(!visit[i] && dist[i] == -1)
		{
			int best = i;
			dfs(-1, i, 0, best);
			dfs(-1, best, 0, best);
			answer = max(answer, dist[best]);
		}
	return answer;
}

void search(int pre, int u, int cnt)
{
	visit[u] = true;
	answer = max(answer, cnt * solve());
	for(int i = first[u]; i; i = next[i])
		if(end[i] != pre)
			search(u, end[i], cnt + 1);
	visit[u] = false;
}

int main()
{
	scanf("%d", &n);
	memset(first, 0, sizeof(first));
	size = 0;
	for(int i = 1; i != n; ++ i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		insert_edge(a - 1, b - 1);
		insert_edge(b - 1, a - 1);
	}
	answer = 0;
	memset(visit, 0, sizeof(visit));
	for(int i = 0; i != n; ++ i)
		search(-1, i, 0);
	printf("%d\n", answer);
	return 0;
}