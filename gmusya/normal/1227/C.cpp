#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector <char> s1(n);
	for (int i = 0; i < n; i++)
		cin >> s1[i];
	vector <char> ans(n);
	vector <pair <int, int>> operations;
	for (int i = 0; i < (k - 1) * 2; i += 2) {
		ans[i] = '(';
		ans[i + 1] = ')';
	}
	for (int i = (k - 1) * 2; i < (k - 1) * 2 + (n - (k - 1) * 2) / 2; i++)
		ans[i] = '(';
	for (int i = (k - 1) * 2 + (n - (k - 1) * 2) / 2; i < n; i++)
		ans[i] = ')';
	int l, r;
	for (l = 0, r = 0; l < n - 1; l++) {
		if (s1[l] == ans[l])
			continue;
		if (l > r)
			r = l + 1;
		while (r < n && s1[l] == s1[r])
			r++;
		if (r == n)
			return;
		operations.push_back({ l, r });
		swap(s1[l], s1[r]);
	}
	cout << operations.size() << endl;
	for (auto now : operations)
		cout << ++now.first << " " << ++now.second << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}