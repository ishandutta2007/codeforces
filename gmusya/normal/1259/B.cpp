#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ll long long

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
		set <ll> kek;
		for (int i = 0; i < n; i++)
			if (a[i] % 2 == 0)
				kek.insert(a[i]);
		int cnt = 0;
		while (kek.size() > 0) {
			cnt++;
			ll x = *(--kek.end());
			kek.erase(x);
			if (x % 4 == 0)
				kek.insert(x / 2);
		}
		cout << cnt << endl;
	}
	return 0;
}