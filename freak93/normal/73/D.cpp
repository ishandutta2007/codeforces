#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 1000050;

int leaf, rest, p, t, n, m, k, x, y;

vector<int> E[maxn];
int been[maxn];

void dfs(int x) {
	been[x] = 1;
	++p;
	for (vector<int>::iterator it = E[x].begin(); it != E[x].end(); ++it)
		if (been[*it] == 0)
			dfs(*it);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
		cin >> x >> y, E[x].push_back(y), E[y].push_back(x);
    for (int i = 1; i <= n; ++i)
		if (been[i] == 0) {
			p = 0; ++t;
			dfs(i); p = min(p, k);
	   		if (p == 1)
				++leaf;
			else
				rest += p;
		}
	if (k == 1) {
		cout << max(0, t - 2) << "\n";
		return 0;
	}
	if (t == n) {
		cout << (n - 1) / 2 << "\n";
		return 0;
	}
	rest -= (t - leaf - 1) * 2;
	if (rest >= leaf) {
		cout << 0 << "\n";
		return 0;
	}
	cout << (leaf - rest + 1) / 2 << "\n";
}