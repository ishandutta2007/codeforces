// Skyqwq
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, m, K, in[N], id, q[N];

bool ok;

map<string, int> mp;

vector<int> g[N];

void inline add(int x, int y) {
	g[x].push_back(y), in[y]++;
}
bool st;
void dfs(string s, int u) {
	if (u == K) {
		if (mp.count(s)) {
			int t = mp[s];
			if (t != id) add(id, t);
			else st = true;
		}
		return;
	}
	dfs(s, u + 1);
	if (s[u] != '_') {
		s[u] = '_';
		dfs(s, u + 1);
	}
}

bool inline topo() {
	int hh = 1, tt = 0;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) q[++tt] = i;
	}
	while (hh <= tt) {
		int u = q[hh++];
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (--in[v] == 0) q[++tt] = v; 
		}
	}
	return tt == n;
}

int main() {
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		string a; cin >> a;
		mp[a] = i;
	}
	ok = true;

	for (int i = 1; i <= m; i++) {
		st = false;
		string a; cin >> a;
		cin >> id;
		dfs(a, 0);
		if (!st) ok = false;
	}
	if (!topo() || !ok) puts("NO");
	else {
		puts("YES");
		for (int i = 1; i <= n; i++) printf("%d ", q[i]);
	}
	return 0;
}