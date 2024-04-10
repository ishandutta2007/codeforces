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


int n;
vector<int> v[100000];
int used[3001];
vector<int> ans;


int dfs(int u, int g) {
	used[u] = 1;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			int t = dfs(h, u);
			if (t != -1) {
				if (u != t && t != 10000) {
					ans.push_back(u);
					return t;
				} else {
					if (u == t) {
						ans.push_back(u);
					}
					return 10000;
				}
			}
		} else {
			if (used[h] == 1 && h != g) {
				ans.push_back(u);
				return h;
			}
		}
	}
	used[u] = 2;
	return -1;
}


int d[3001];
bool used1[3001];
queue<int> q;


void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int j = 0; j < (int)v[x].size(); j++) {
			if (!used1[v[x][j]]) {
				used1[v[x][j]] = true;
				d[v[x][j]] = d[x] + 1;
				q.push(v[x][j]);
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		memset(used, 0, sizeof(used));
		if (dfs(i, -1) != -1) {
			break;
		}
	}
	for (int j = 0; j < (int)ans.size(); j++) {
		d[ans[j]] = 0;
		q.push(ans[j]);
		used1[ans[j]] = true;
	}	
//	cout << endl;
	bfs();
	for (int i = 0; i < n; i++) {
		cout << d[i] << endl;
	}
	return 0;
}