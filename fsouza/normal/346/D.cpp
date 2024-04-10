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
#define MAXN 1000000

typedef long long lint;

using namespace std;

vector <int> radj[MAXN];
int outdeg[MAXN], result[MAXN], maxout[MAXN], mark[MAXN];

int main(int argc, char ** argv)
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		outdeg[i] = 0;
		radj[i].clear();
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;

		radj[b].push_back(a);
		outdeg[a] ++;
	}

	int s, t;
	scanf("%d %d", &s, &t);
	s--, t--;

	priority_queue <pair <int, int> > pq;
	
	for (int i = 0; i < n; i++) {
		result[i] = INF;
		maxout[i] = 0;
		mark[i] = 0;
	}
	result[t] = 0;
	pq.push(make_pair(-0, t));

	while (!pq.empty()) {
		pair <int, int> rv = pq.top(); pq.pop();
		int ret = -rv.first;
		int v = rv.second;

		if (mark[v]) continue;
		mark[v] = 1;

		for (int i = 0; i < (int)radj[v].size(); i++) {
			int v2 = radj[v][i];

			maxout[v2] = max(maxout[v2], ret);
			outdeg[v2] --;
			if (outdeg[v2] == 0 && result[v2] > maxout[v2])
				pq.push(make_pair(-(result[v2] = maxout[v2]), v2));
			if (result[v2] > ret+1)
				pq.push(make_pair(-(result[v2] = ret+1), v2));
		}
	}

	if (result[s] == INF)
		printf("-1\n");
	else
		printf("%d\n", result[s]);

	return 0;
}