#include <bits/stdc++.h>
using namespace std;

int a[110];
int ans[110];
int l[110];

int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> l[i];
		}
		if (sum < 0) {
			for (int i = 1; i <= n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			continue;
		}
		multiset <int> S;
		for (int i = 1; i <= n; i++) {
			if (l[i] == 0) S.insert(a[i]);
		}
		for (int i = n; i >= 1; i--) {
			if (l[i] == 1) {
				sum -= a[i];
				continue;
			}
			a[i] = *S.begin(), S.erase(S.begin());
			sum -= a[i];
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}