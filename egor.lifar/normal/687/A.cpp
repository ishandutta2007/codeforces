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


using namespace std;


int n, m;
vector<int> v[100001];
int colours[100001];
bool used[100001];


void dfs(int u, int t) {
	used[u] = 1;
	colours[u] = t;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			dfs(h, 1 - t);
		} else {
			if (colours[u] == colours[h]) {
				cout << -1 << endl;
				exit(0);
			}
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
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, 0);
		}
	}
	vector<int> vv, v1;
	for (int i = 0; i < n; i++) {
		if (colours[i]) {
			vv.push_back(i + 1);
		} else {
			v1.push_back(i + 1);
		}
	}
	cout << (int)vv.size() << endl;
	for (auto x: vv) {
		printf("%d ", x);
	}
	printf("\n");
	cout << (int)v1.size() << endl;
	for (auto x: v1) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}