#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;

int n;
int aa[100001];
vector<pair<int, int> > v[100001];
long long dist[100001];
int size[1000001];
int cnt = 0;
int ans = 0;
long long mindist[1000001];


int dfs(int u) {
	size[u] = 1;
	if (dist[u] - mindist[u] > aa[u]) {
		cnt++;
	}
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i].first;
		dist[h] = dist[u] + v[u][i].second;
		mindist[h] = min(mindist[h], mindist[u]);
		mindist[h] = min(mindist[h], dist[h]);
		size[u] += dfs(h);
	}
	if (dist[u] - mindist[u] > aa[u]) {
		if (cnt == 1) {
			ans += size[u];
		}
		cnt--;
	}
	return size[u];
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &aa[i]);
	}
	for (int i = 1; i < n; i++) {
		int p, c;
		scanf("%d %d", &p, &c);
		p--;
		v[p].push_back(make_pair(i, c));
	}
	dfs(0);
	cout << ans << endl;
    return 0;
}