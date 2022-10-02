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
vector<int> v[100000];
int c[100000];
bool used[100000];
int d[100000];
int up[100000];
vector<int> t;
int pr[100000];


void dfs(int u) {
	t.push_back(u);
	used[u] = true;
	d[u] = 0;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			dfs(h);
			pr[h] = u;
			d[u] += d[h] + 1;
		}
	}
}


void resh(int root, int cc) {
	up[root] = 0;
	pr[root] = -1;
	t.clear();
	dfs(root);
	if ((int)t.size() == 0) {
		return;
	}
	for (int i = 0; i < (int)t.size(); i++) {
		used[t[i]] = false;
		up[t[i]] = (int)t.size() - d[t[i]] - 1;
	}
	for (int i = 0; i < (int)t.size(); i++) {
		int a = t[i];
		bool bb = false;
		for (int j = 0; j < (int)v[a].size(); j++) {
			int b = v[a][j];
			if (!used[b]) {
				if (b != pr[a]) {
					if (d[b] > (int)t.size() / 2) {
						bb = true;
					}
				} else {
					if (up[a] > (int)t.size() / 2) {
						bb = true;
					}
				}
			} 
		}
		if (!bb) {
			c[a] = cc;
			used[a] = true;
			for (int j = 0; j < (int)v[a].size(); j++) {
				int b = v[a][j];
				if (!used[b]) {
					resh(b, cc + 1);
				}
			}
			return;
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
		v[b].push_back(a);
	}
	resh(0, 0);
	for (int i = 0; i < n; i++) {
		//c[i] = min(c[i], 25);
		cout << (char)('A' + c[i]) << ' ';
	}
	cout << endl;
    return 0;
}