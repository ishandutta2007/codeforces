#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <int> arr;
		vector <int> first(n+1, n + 1), last(n + 1, -1);
		for (int i = 0; i < n; i++) {
			if (first[a[i]] == n + 1) arr.push_back(a[i]);
			first[a[i]] = min(first[a[i]], i);
			last[a[i]] = max(last[a[i]], i);
		}
		int m = arr.size();
		sort(arr.begin(), arr.end());
		vector <int> sol(m);
		int ans = m - 1;
		for (int i = m - 1; i >= 0; i--) {
			if (i == m - 1 || last[arr[i]] >= first[arr[i + 1]]) sol[i] = 1;
			else sol[i] = 1 + sol[i + 1];
			ans = min(ans, (int)arr.size() - sol[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}