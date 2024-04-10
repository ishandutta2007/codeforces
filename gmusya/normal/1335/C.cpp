#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <int> cnt(n + 1);
		for (int i = 0; i < n; i++)
			cnt[a[i]]++;
		int sum = 0;
		for (int i = 0; i <= n; i++)
			sum += (cnt[i] > 0);
		int ma = 0;
		for (int i = 0; i <= n; i++)
			ma = max(cnt[i], ma);
		cout << max(min(sum - 1, ma), min(sum, ma - 1)) << endl;
	}
	return 0;
}