#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;


#define INF 1000 * 1000 * 1000


int n, m;
vector<int> v[100000];
int d[1000][1000];
queue<int> q;
int used[1000];
bool b = true;
int ans = 0;


void dfs(int u) {
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			used[h] = 3 - used[u];
			dfs(h);
		} else {
			if (used[h] != 3 - used[u]) {
				b = false;
			}
		}
	}
}


void bfs(int u) {
	q.push(u);
	for (int i = 0; i < n; i++) {
		d[u][i] = INF;
	}
	d[u][u] = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 0; i < (int)v[a].size(); i++) {
			int h = v[a][i];
			if (d[u][h] == INF) {
				d[u][h] = d[u][a] + 1;
				ans = max(ans, d[u][h]);
				q.push(h);
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> v1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = 1;
			dfs(i);
			v1.push_back(i);
		}
	}
	if (!b) {
		cout << -1 << endl;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < (int)v1.size(); i++) {
		int x = v1[i];
		memset(used, 0, sizeof(used));
		used[x] = 1;
		dfs(x);
		ans = 0;
		for (int j = 0; j < n; j++) {
			if (used[j]) {
				bfs(j);
			}
		}
		sum += ans;
	}
	cout << sum << endl;
    return 0;
}