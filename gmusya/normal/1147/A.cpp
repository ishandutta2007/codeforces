#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e6;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(k), b(n, INF);
	vector <bool> used(n);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < k; i++)
		b[a[i]] = min(i, b[a[i]]);
	int ans = 0;
	vector <pair <int, int>> query;
	for (int i = 0; i < n; i++) {
		if (b[i] == INF) {
			if (i == 0 || i == n - 1)
				ans += 2;
			else
				ans += 3;
			continue;
		}
		if (i > 0)
			query.push_back({ b[i], i - 1 });
		if (i < n - 1)
			query.push_back({ b[i], i + 1 });
	}
	sort(query.begin(), query.end());
	reverse(query.begin(), query.end());
	int it_q = 0;
	for (int i = k - 1; i >= 0; i--) {
		used[a[i]] = true;
		while (it_q < query.size() && query[it_q].first == i) {
			ans += (1 - used[query[it_q].second]);
			it_q++;
		}
	}
	cout << ans;
	return 0;
}