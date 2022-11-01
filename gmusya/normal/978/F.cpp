#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> hm(n);
	for (int i = 0; i < n; i++)
		cin >> hm[i];
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = { hm[i], i };
	}
	sort(a.begin(), a.end());
	vector <int> ans(n);
	for (int i = 0; i < n; i++) {
		int j = i;
		ans[a[i].second] = i;
		while (i < n - 1 && a[i].first == a[i + 1].first) {
			i++;
			ans[a[i].second] = ans[a[i - 1].second];
		}
	}
	while (k--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		if (hm[l] > hm[r])
			ans[l]--;
		if (hm[r] > hm[l])
			ans[r]--;
	}
	for (int x : ans)
		cout << x << " ";
	return 0;
}