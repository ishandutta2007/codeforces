#include <iostream>
#include <vector>

using namespace std;

int MAXVAL = 2e5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <int> cnt(MAXVAL + 2);
	for (int i = 0; i < n; i++)
		cnt[a[i]]++;
	pair <int, pair <int, int>> ans = { 0, {0, 0} };
	vector <pair <int, int>> lr;
	int L = -1;
	for (int i = 0; i <= MAXVAL; i++) {
		if (cnt[i] < 2) continue;
		if (L == -1) L = i;
		if (cnt[i + 1] < 2) {
			lr.push_back({ L, i });
			L = -1;
		}
	}
	for (int i = 0; i < lr.size(); i++) {
		int L = lr[i].first, R = lr[i].second;
		int sum = 0;
		for (int i = L - 1; i <= R + 1; i++) 
			sum += cnt[i];
		if (sum > ans.first) {
			ans.first = sum;
			ans.second = { L, R };
		}
	}
	if (!ans.first) {
		for (int i = 0; i <= MAXVAL; i++)
			if (cnt[i] + cnt[i + 1] > ans.first) {
				ans.first = cnt[i] + cnt[i + 1];
				ans.second = { i, i + 1 };
			}
		cout << ans.first << '\n';
		for (int i = 0; i < cnt[ans.second.first]; i++)
			cout << ans.second.first << ' ';
		for (int i = 0; i < cnt[ans.second.second]; i++)
			cout << ans.second.second << ' ';
		return 0;
	}
	cout << ans.first << '\n';
	for (int i = 0; i < cnt[ans.second.first - 1]; i++)
		cout << ans.second.first - 1 << ' ';
	for (int j = ans.second.first; j <= ans.second.second; j++)
		for (int i = 1; i < cnt[j]; i++)
			cout << j << ' ';
	for (int i = 0; i < cnt[ans.second.second + 1]; i++)
		cout << ans.second.second + 1 << ' ';
	for (int j = ans.second.second; j >= ans.second.first; j--)
		cout << j << ' ';
	return 0;
}