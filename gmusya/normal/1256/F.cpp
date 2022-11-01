#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <pair <char, int>> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i].first;
			b[i].second = i;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll inva = 0, invb = 0;
		bool tf = true, tf2 = false;
		for (int i = 0; i < n; i++) 
			if (a[i].first != b[i].first) tf = false;
		for (int i = 0; i < n - 1; i++) {
			if (a[i].first == a[i + 1].first) tf2 = true;
			if (b[i].first == b[i + 1].first) tf2 = true;
		}
		if (!tf2) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					inva += (a[j].first > a[i].first && a[j].second < a[i].second);
					invb += (b[j].first > b[i].first && b[j].second < b[i].second);
				}
		}
		if (((inva - invb) % 2 && !tf2) || !tf) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}