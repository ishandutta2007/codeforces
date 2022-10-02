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
#include <bitset>


using namespace std;


int n, m;
vector<int> v[500001];
int in[500001];
int out[500001];
int p[500001];
int deep[500001];
int t = 0;
vector<int> g[500001];
vector<int> f[500001];
int maxDeep = 0;


void dfs(int u) {
	deep[u] = deep[p[u]] + 1;
	maxDeep = max(deep[u], maxDeep);
	g[deep[u]].push_back(u);
	t++;
	in[u] = t;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		dfs(h);
	}
	t++;
	out[u] = t;
}


string s;


int main() {
	cin >> n >> m;
	p[0] = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		v[p[i]].push_back(i);
	}
	cin >> s;
	dfs(0);
	for (int i = 1; i <= maxDeep; i++) {
		int l = (int)g[i].size();
		f[i].resize(l);
		for (int k = 0; k < l; k++) {
			for (int j = 0; j < 26; j++) {
				if (s[g[i][k]] == ('a' + j)) {
					f[i][k] = (f[i][k] ^ (1 << j));
				}
			}
			if (k != 0) {
				f[i][k] = (f[i][k] ^ f[i][k - 1]);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int v, h;
		scanf("%d %d", &v, &h);
		v--;
		if (h > maxDeep) {
			printf("Yes\n");
			continue;
		}
		int l = 0;
		int r = (int)g[h].size() - 1;
		if (in[g[h][0]] < in[v]) {
	 		while (l != r) {
				int mm = (l + r + 1) / 2;
				if (in[g[h][mm]] < in[v]) {
					l = mm;
				} else {
					r = mm - 1;
				}
			}
		} else {
			l = -1;
		}
		if (l == (int)g[h].size() - 1) {
			printf("Yes\n");
			continue;
		}
		l++;
		if (out[g[h][l]] > out[v]) {
			printf("Yes\n");
			continue;
		}
		int l1 = l;
		int r1 = (int)g[h].size() - 1;
		while (l1 != r1) {
			int mm = (l1 + r1 + 1) / 2;
			if (out[g[h][mm]] > out[v]) {
				r1 = mm - 1;
			} else {
				l1 = mm;
			}
		}
		int k = 0;
		for (int j = 0; j < 26; j++) {
			if (((f[h][l1] & (1 << j)) ^ (l > 0 ? (f[h][l - 1] & (1 << j)): 0)) == (1 << j)) {
				k++;
			}
		}
		if (k < 2) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
 	}
    return 0;
}