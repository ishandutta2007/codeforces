#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <queue>


using namespace std;


int n, m;
int ans = 0;
vector<int> v[100001];
bool used[100001];
int d[1000001];


void dfs(int u) {
	used[u] = 1;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int  h = v[u][i];
		if (!used[h]) {
			d[h] = d[u] + 1;
			dfs(h);
		}
	}
}
 

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(0);
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > d[c]) {
			c = i;
		}
	}
	memset(used, 0, sizeof(used));
	memset(d, 0, sizeof(d));
	dfs(c);
	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
 	return 0;
}