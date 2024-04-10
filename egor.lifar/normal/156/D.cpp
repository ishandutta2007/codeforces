#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;



int n, m;
long long k;
vector<int> v[100000];
bool used[100000];
vector<int> g;
int s = 0;


void dfs(int u) {
	s++;
	used[u] = true;
	for (int i = 0; i < (int)v[u].size(); i++) {
		int h = v[u][i];
		if (!used[h]) {
			dfs(h);
		}
	}
}


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			s = 0;
			dfs(i);
			g.push_back(s);
			l++;
		}
	}
	if (l == 1) {
		cout << 1 % k << endl;
		return 0;
	}
	int ans = 1;
	for (int i = 0; i < l; i++) {
		ans = (1LL * ans * g[i]) % k;
	}
	for (int i = 1; i <= l - 2; i++) {
		ans = (1LL * ans * n) % k;
	}
	cout << ans << endl;
	return 0;
}