#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 100000

typedef long long lint;

using namespace std;

int isblack[MAXN];
vector <pair <int, int> > adj[MAXN];
pair <int, int> maxdist[MAXN];
pair <int, int> downdists[MAXN];
int result[MAXN], delta[MAXN];

pair <int, int> dfs(int v, int parent, int dist, int root)
{
	pair <int, int> result = make_pair(-INF, -1);

	if (isblack[v]) result = make_pair(dist, v);
	maxdist[v] = max(maxdist[v], make_pair(dist, root));

	for (int i = 0; i < (int)adj[v].size(); i++) {
		if (adj[v][i].first == parent) continue;
		result = max(result, dfs(adj[v][i].first, v, dist + adj[v][i].second, root));
	}

	return result;
}

void dfs2(int v, int parent)
{
	downdists[v] = make_pair(-INF, -INF);

	if (isblack[v]) downdists[v].first = 0;

	for (int i = 0; i < (int)adj[v].size(); i++) {
		int v2 = adj[v][i].first;
		if (v2 == parent) continue;
		dfs2(v2, v);
		if (adj[v][i].second + downdists[v2].first > downdists[v].second) {
			downdists[v].second = downdists[v2].first + adj[v][i].second;
			if (downdists[v].second > downdists[v].first)
				swap(downdists[v].first, downdists[v].second);
		}
	}
}

int dfs3(int v, int parent, int dist, int limit, int root)
{
	int ret = 0;

	if (isblack[v] && maxdist[v].second == root) {
		int limit2 = downdists[v].first == dist ? v : limit;
		ret ++;
		delta[limit2] --;
	}

	for (int i = 0; i < (int)adj[v].size(); i++) {
		int v2 = adj[v][i].first;
		if (v2 == parent) continue;
		
		int best = downdists[v].first;
		if (best == downdists[v2].first + adj[v][i].second) best = downdists[v].second;

		ret += dfs3(v2, v, dist + adj[v][i].second, best == dist ? v : limit, root);
	}

	result[v] += ret;
	ret += delta[v];
	delta[v] = 0;

	return ret;
}

int main(int argc, char ** argv)
{
	int n, m;

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		isblack[i] = 0;
		adj[i].clear();
		result[i] = 0;
		delta[i] = 0;
	}

	for (int j = 0; j < m; j++) {
		int i;
		scanf("%d", &i);
		i--;
		isblack[i] = 1;
	}
	
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
		
	int dA = dfs(0, -1, 0, 0).second;
	for (int i = 0; i < n; i++) maxdist[i] = make_pair(-1, -1);

	int dB = dfs(dA, -1, 0, dA).second;
	dfs(dB, -1, 0, dB);

	dfs2(dA, -1);
	dfs3(dA, -1, 0, dA, dA);

	dfs2(dB, -1);
	dfs3(dB, -1, 0, dB, dB);

	int ret = -1, retmany = 0;

	for (int i = 0; i < n; i++)
		if (!isblack[i]) {
			if (result[i] > ret) {
				ret = result[i];
				retmany = 0;
			}
			if (result[i] == ret)
				retmany ++;
		}

	printf("%d %d\n", ret, retmany);

	return 0;
}