#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n, m, k;
vector<int> v[100000];
bool used[100000];
int g[100000];
vector<int> ansss;


int dfs(int u, int gg) {
	used[u] = 1;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			g[h] = g[u] + 1; 
			int f = dfs(h, u);
			if (f == -1) {
				continue;
			}
			if (u != f && f != 100001) {
				ansss.push_back(u);
				return f;
			} else {
				return 100001;
			}
		} else {
			if (used[h] == 1 && h != gg) {
				if (g[u] - g[h] >= k) {
					ansss.push_back(h);
					ansss.push_back(u);
					//cout << g[h] << endl;
					return h;
				}
			}
		}
	}
	used[u] = 2;
	return -1;
}



int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			if (dfs(i, -1)) {
				break;
			}
		}
	}
	cout << (int)ansss.size() << endl;
	for (int i = 0; i < (int)ansss.size(); i++) {
		cout << ansss[i] + 1 << ' ';
	}
	cout << endl;
 	return 0;
}