#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <pair <pair <int, int>, int>> a;
	vector <bool> used(m);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		for (int i = 0; i < a.size(); i++) {
			if (used[i])
				continue;
			if (a[i].first.second == u) {
				u = a[i].first.first;
				w = min(a[i].second, w);
				used[i] = true;
				continue;
			}
			if (a[i].first.first == v) {
				v = a[i].first.second;
				w = min(a[i].second, w);
				used[i] = true;
			}
		}
		a.push_back({ {u, v}, w });
	}
	vector <pair <pair <int, int>, int>> answer;
	for (int i = 0; i < a.size(); i++)
		if (!used[i] && a[i].first.first != a[i].first.second)
			answer.push_back(a[i]);
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (auto now : answer)
		cout << now.first.first << " " << now.first.second << " " << now.second << endl;
	return 0;
}