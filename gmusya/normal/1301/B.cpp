#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

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
		vector <int> b;
		for (int i = 0; i < n; i++) {
			if (a[i] == -1)
				continue;
			if (i > 0 && a[i - 1] == -1)
				b.push_back(a[i]);
			if (i < n - 1 && a[i + 1] == -1)
				b.push_back(a[i]);
		}
		sort(b.begin(), b.end());
		int k;
		if (b.size() == 0)
			k = 0;
		else
			k = (b[0] + b[b.size() - 1]) / 2;
		for (int i = 0; i < n; i++)
			if (a[i] == -1)
				a[i] = k;
		int ans = 0;
		for (int i = 0; i < n - 1; i++)
			ans = max(ans, abs(a[i] - a[i + 1]));
		cout << ans << " " << k << endl;
	}
	return 0;
}