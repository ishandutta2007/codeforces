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


using namespace std;


int n;
int ans[200001];
vector<pair<int, int> > v[200001];
bool used[200001];
int d[200001];
int up[200001];


void dfs(int u) {
	used[u] = true;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i].first;
		if (!used[h]) {
			if (v[u][i].second == 2) {
				d[u]++;
			}
			dfs(h);
			d[u] += d[h];
		}
	}
}



void dfs1(int u) {
	used[u] = true;
	vector<int> g;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i].first;
		if (!used[h]) {
			up[h] += up[u];
			if (v[u][i].second == 1) {
				up[h]++;
			}
			g.push_back(i);
		}
	}
	for (int i = 0; i < (int)g.size(); i++) {
		int h = v[u][g[i]].first;
		up[h] += d[u] - d[h] - (v[u][g[i]].second == 2);
		dfs1(h);
	}
}



int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(make_pair(b, 1));
		v[b].push_back(make_pair(a, 2));
	}
	dfs(0);
	memset(used, 0, sizeof(used));
	dfs1(0);
	int t = 1000 * 1000;
	for (int i = 0; i < n; i++) {
		ans[i] = d[i] + up[i];
		t = min(t, ans[i]);
	}
	//cout << d[1] << endl;
//	cout << up[1] << endl;
	cout << t << endl;
	for (int i = 0; i < n; i++) {
		if (ans[i] == t) {
			cout << i + 1 << ' ';
		}
	}
	cout << endl;

    return 0;
}