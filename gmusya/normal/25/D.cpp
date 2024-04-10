#include <iostream>
#include <vector>
#include <numeric>
#include <random>

using namespace std;

vector <int> dsu;

int get(int v) {
	if (dsu[v] == v) return v;
	return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
	u = get(u);
	v = get(v);
	if (u % 2) swap(u, v);
	dsu[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	dsu.resize(n);
	vector <pair <pair <int, int>, pair <int, int>>> ans;
	vector <pair <int, int>> e(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> e[i].first >> e[i].second;
		e[i].first--, e[i].second--;
	}
	iota(dsu.begin(), dsu.end(), 0);
	for (int i = 0; i < n - 1; i++) {
		int u = e[i].first, v = e[i].second;
		if (get(u) == get(v))
			ans.push_back({ { u + 1, v + 1 }, {} });
		else
			merge(u, v);
	}
	int it = 0;
	for (int i = 1; i < n; i++) {
		int u = 0, v = i;
		if (get(u) == get(v)) continue;
		merge(u, v);
		ans[it++].second = { u + 1, v + 1 };
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	return 0;
}