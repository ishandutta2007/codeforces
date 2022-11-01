#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll sum = 0;
		for (int i = 0; i + 1 < n; i++)
			if (a[i] - a[i + 1] > 0)
				sum += a[i] - a[i + 1];
		cout << sum << '\n';
	}
	return 0;
}