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


#define INF -200000000


int n, m, d;
int a[100001];
vector<int> v[100000];
int down[100001];
int up[100001];
bool used[100001];
bool good[100001];


void dfs(int u) {
	used[u] = true;
	if (good[u]) {
		down[u] = 0;
	}
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			dfs(h);
			down[u] = max(down[u], down[h] + 1);
		}
	}
}


void dfs1(int u) {
	used[u] = true;
	if (good[u]) {
		up[u] = max(up[u], 0);
	}
	multiset<int> s;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			s.insert(down[h]);
		}
	}
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			s.erase(s.find(down[h]));
			if (!s.empty()) {
				up[h] = max(up[h], 2 + *(s.rbegin()));
			}
			s.insert(down[h]);
			up[h] = max(up[h], up[u] + 1);
			dfs1(h);
		}
	}
}



int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		a[i]--;
		good[a[i]] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		down[i] = INF;
		up[i] = INF;
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		if (down[i] < INF / 2) {
			down[i] = INF;
		}
	}
	memset(used, 0, sizeof(used));
	dfs1(0);
	for (int i = 0; i < n; i++) {
		if (up[i] < INF / 2) {
			up[i] = INF;
		}
	}
	//cout << up[1] << endl; 
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (down[i] <= d && up[i] <= d) {
			k++;
		}
	}
	cout << k << endl;
    return 0;
}