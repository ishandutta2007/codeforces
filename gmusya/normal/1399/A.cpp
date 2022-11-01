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
		sort(a.begin(), a.end());
		bool tf = true;
		for (int i = 0; i + 1 < n; i++)
			if (a[i] + 1 < a[i + 1])
				tf = false;
		if (tf) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}