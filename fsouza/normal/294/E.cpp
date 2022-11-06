#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>
#include <numeric>

#define MAXN 5000
#define INF (1000000000000000000LL)

typedef long long lint;

using namespace std;

pair <int, int> blocked;
bool isblocked(int a, int b) {return blocked == make_pair(a, b) || blocked == make_pair(b, a);}

vector <pair <int, lint> > adj[MAXN];
int stsize[MAXN];
lint stsum[MAXN];
lint fullsum[MAXN];
int mark[MAXN];

int parent[MAXN];
lint parentweight[MAXN];
int fullsize;

lint weirdedgesum[MAXN];

void dfs1(int v)
{
	mark[v] = 1;
	stsize[v] = 1;
	stsum[v] = 0;
	weirdedgesum[v] = 0;

	for (int i = 0; i < adj[v].size(); i++) {
		int v2 = adj[v][i].first;
		lint w = adj[v][i].second;

		if (isblocked(v, v2) || mark[v2]) continue;

		parent[v2] = v;
		parentweight[v2] = w;

		dfs1(v2);

		stsize[v] += stsize[v2];
		weirdedgesum[v] += w * (lint)stsize[v2];
		weirdedgesum[v] += weirdedgesum[v2];
	}

	stsum[v] += weirdedgesum[v];
}

void dfs2(int v, lint& bestfullsum)
{
	mark[v] = 1;

	if (parent[v] == -1) {
		fullsize = stsize[v];
		fullsum[v] = stsum[v];
	} else {
		fullsum[v] = fullsum[parent[v]] + parentweight[v] * (lint)(fullsize-2*stsize[v]);
	}
	bestfullsum = min(bestfullsum, fullsum[v]);

	for (int i = 0; i < adj[v].size(); i++) {
		int v2 = adj[v][i].first;
		lint w = adj[v][i].second;

		if (isblocked(v, v2) || mark[v2]) continue;

		dfs2(v2, bestfullsum);
	}
}

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		adj[i].clear();

	vector <pair<pair <int, int>, lint> > edges;

	for (int i = 0; i < n-1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		
		adj[a].push_back(make_pair(b, w));
		adj[b].push_back(make_pair(a, w));
		edges.push_back(make_pair(make_pair(a, b), w));
	}

	lint finalret = INF;

	for (int i = 0; i < (int)edges.size(); i++) {
		blocked = edges[i].first;

		lint weight = edges[i].second;
		lint bestleft = INF, bestright = INF;
		
		for (int j = 0; j < n; j++)
			mark[j] = 0;

		parent[blocked.first] = -1;
		dfs1(blocked.first);

		parent[blocked.second] = -1;
		dfs1(blocked.second);

		memset(mark, 0, sizeof(int)*n);

		dfs2(blocked.first, bestleft);
		dfs2(blocked.second, bestright);
		
		lint ret = accumulate(fullsum, fullsum+n, 0LL)/2LL;
		lint leftsize = stsize[blocked.first], rightsize = stsize[blocked.second];

		ret += leftsize*rightsize*weight + bestleft*rightsize + bestright*leftsize;

		finalret = min(finalret, ret);
	}

	cout << finalret << endl;

	return 0;
}