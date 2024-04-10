#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <tuple>
#include <unordered_set>


using namespace std;


int n;
vector<int> v[200000];
bool used[200000];
int d[200000][2];
int w[200000];



void dfs1(int u) {
	used[u] = true;
	bool b = true;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			dfs1(h);
			w[u] += w[h];
			b = false;
		}
	}
	w[u] += b;
}



void dfs(int u) {
	if ((int)v[u].size() == 0) {
		d[u][0] = 1;
		d[u][1] = 1;
		return;
	}
	used[u] = true;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			dfs(h);
			d[u][0] = max(d[u][0], w[u] - w[h] + d[h][1]);
			d[u][1] += d[h][0] - 1;
		}
	}
	d[u][1] += 1;
}


void dfs2(int u) {
	used[u] = true;
	if ((int)v[u].size() == 0) {
		d[u][1] = 1;
		d[u][0] = 1;
		return;
	} 
	//d[u][0] = 
	d[u][1] = 1000000000;
	for (int j = 0; j < (int)v[u].size(); j++) {
		int h = v[u][j];
		if (!used[h]) {
			dfs2(h);
			d[u][1] = min(d[u][1], d[h][0]);
			d[u][0] += d[h][1];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
	}
	dfs1(0);
	memset(used, 0, sizeof(used));
	dfs(0);
	cout << d[0][0] << ' ';
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; i++) {
		d[i][0] = 0;
		d[i][1] = 0;
	}
	dfs2(0);
	cout << d[0][0] << endl;
    return 0;	
}