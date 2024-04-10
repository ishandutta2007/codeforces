#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <vector <int>> g(n);
	for (int i = 1; i < n; i++) {
		int u;
		cin >> u;
		g[u - 1].push_back(i);
	}
	vector <int> d(n);
	queue <int> q;
	q.push(0);
	vector <bool> used(n);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		used[v] = true;
		for (int u : g[v]) {
			d[u] = d[v] + 1;
			q.push(u);
		}
	}
	vector <int> arr(n);
	for (int i = 0; i < n; i++)
		arr[d[i]]++;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (arr[i] % 2);
	cout << cnt;
	return 0;
}