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
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		if (n % 2 && a[n / 2] != b[n / 2]) {
			cout << "No\n";
			continue;
		}
		vector <pair <int, int>> pa, pb;
		for (int i = 0; i < n / 2; i++)
			pa.push_back({ min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1]) });
		for (int i = 0; i < n / 2; i++)
			pb.push_back({ min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1]) });
		sort(pa.begin(), pa.end());
		sort(pb.begin(), pb.end());
		bool tf = true;
		for (int i = 0; i < pa.size(); i++)
			if (pa[i] != pb[i])
				tf = false;
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}