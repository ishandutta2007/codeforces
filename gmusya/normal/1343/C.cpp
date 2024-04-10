#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <ll> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll mi = 0, pl = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0 && !pl) {
				sum += mi;
				mi = 0;
				pl = a[i];
				continue;
			}
			if (a[i] > 0) {
				pl = max(pl, a[i]);
				continue;
			}
			if (a[i] < 0 && !mi) {
				sum += pl;
				pl = 0;
				mi = a[i];
				continue;
			}
			mi = max(mi, a[i]);
		}
		sum += mi + pl;
		cout << sum << '\n';
	}
	return 0;
}