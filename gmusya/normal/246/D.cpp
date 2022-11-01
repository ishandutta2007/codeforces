#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
vector <set <int>> s;
vector <int> ans, c;

int main() {
	cin >> n >> m;
	s.resize(1e5+1), c.resize(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		if (c[u] != c[v]) {
			s[c[u]].insert(c[v]);
			s[c[v]].insert(c[u]);
		}
	}
	int first = -1, second = -1;
	for (int i = 0; i < n; i++) {
		if ((int) s[c[i]].size() > first || (s[c[i]].size() == first && c[i] < second)) {
			first = s[c[i]].size();
			second = c[i];
		}
	}
	cout << second;
	return 0;
}