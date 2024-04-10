#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int i;
vector <pair <int, int>> a;

void dfs(int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (a[l].first) return;
		a[l].first = ++i;
		a[l].second = r - l;
	}
	int m = (l + r)	/ 2;
	if (!a[m].first) {
		a[m].first = ++i;
		a[m].second = r - l;
	}
	dfs(l, m - 1);
	dfs(m + 1, r);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		a.assign(n, { 0, 0 });
		i = 0;
		dfs(0, n - 1);
		vector <pair <pair <int, int>, int>> b(n);
		for (int i = 0; i < n; i++) {
			b[i].first = { -a[i].second, a[i].first };
			b[i].second = i;
		}
		sort(b.begin(), b.end());
		vector <int> c(n);
		for (int i = 0; i < n; i++)
			c[b[i].second] = i + 1;
		for (int i = 0; i < n; i++)
			cout << c[i] << ' ';
		cout << '\n';
	}
	return 0;
}