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
#include <unordered_map>
#include <cassert>


using namespace std;


int n, m;
int p[1000001];
int a[1000001];
int b[1000001];
vector<int> v[1000001];
bool used[1000001];
int comp = 0;
vector<int> elems[1000001];
vector<int> who[1000001];
int ans[1000001];


void dfs(int u) {
	used[u] = 1;
	elems[comp].push_back(u);
	who[comp].push_back(p[u]);
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			dfs(h);
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}	
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			comp++;
		}
	}
	for (int i = 0; i < comp; i++) {
		sort(elems[i].begin(), elems[i].end());
		sort(who[i].begin(), who[i].end());
		reverse(who[i].begin(), who[i].end());
		for (int j = 0; j < (int)who[i].size(); j++) {
			ans[elems[i][j]] = who[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}