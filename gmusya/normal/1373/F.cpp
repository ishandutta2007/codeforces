#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll suma = 0, sumb = 0;
		int n;
		cin >> n;
		vector <ll> a(n + n), b(n + n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i + n] = a[i];
			suma += a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			b[i + n] = b[i];
			sumb += b[i];
		}
		if (suma > sumb) {
			cout << "NO\n";
			continue;
		}
		ll need = 0;
		bool tf = true;
		for (int i = 0; i < n + n; i++) {
			need += (a[i] - b[i ? i - 1 : 2 * n - 1]);
			if (need > b[i]) tf = false;
			if (need < 0) need = 0;
		}
		if (tf) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}