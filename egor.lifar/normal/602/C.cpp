#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;


int n, m;
bool g[401][401];
queue<int> q;
int d[401];


void bfs(int u, int t) {
	q.push(u);
	d[u] = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (i != a) {
				if (t == 0) {
					if (!g[a][i]) {
						if (d[i] == 1000000000) {
							d[i] = d[a] + 1;
							q.push(i);
						}
					}
				} else {
					if (g[a][i]) {
						if (d[i] == 1000000000) {
							d[i] = d[a] + 1;
							q.push(i);
						}
					}
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a - 1][b - 1] = true;
		g[b - 1][a - 1] = true;
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1000000000;
	}
	if (g[0][n - 1]) {
		bfs(0, 0);
	} else {
		bfs(0, 1);
	}
	if (d[n - 1] == 1000000000) {
		cout << -1 << endl;
		return 0;
	}
	cout << d[n - 1] << endl;
	return 0;
}