#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <pair <int, pair <int, int>>> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i].first;
		d[i].second = { 2 * i, 2 * i + 1 };
	}
	sort(d.rbegin(), d.rend());
	vector <pair <int, int>> e;
	for (int i = 1; i < n; i++)
		e.push_back({ 2 * (i - 1), 2 * i });
	vector <int> vertical_path(n);
	for (int i = 0; i < n; i++)
		vertical_path[i] = 2 * i;
	for (int i = 0; i < n; i++) {
		int dis = d[i].first;
		int v = vertical_path[i + dis - 1];
		if (i + dis == vertical_path.size()) vertical_path.push_back(2 * i + 1);
		e.push_back({ v, 2 * i + 1 });
	}
	vector <int> p;
	for (int i = 0; i < n; i++) {
		p.push_back(d[i].second.first);
		p.push_back(d[i].second.second);
	}
	for (auto &now : e)
		cout << p[now.first] + 1 << ' ' << p[now.second] + 1 << '\n';
	return 0;
}