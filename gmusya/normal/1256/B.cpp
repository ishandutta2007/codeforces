#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

void swap(ll *a, ll *b) {
	ll k = *a;
	*a = *b;
	*b = k;
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector <ll> a(n);
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		ll uk = 0;
		while (uk < n) {
			int ukprev = uk;
			int minid = uk;
			for (int i = uk; i < n; i++) {
				if (a[minid] > a[i])
					minid = i;
			}
			if (uk == minid) {
				uk++;
				continue;
			}
			uk = minid;
			for (int i = uk; i > ukprev; i--)
				swap(a[i], a[i - 1]);
		}
		for (auto now : a)
			cout << now << " ";
		cout << endl;
	}
	return 0;
}