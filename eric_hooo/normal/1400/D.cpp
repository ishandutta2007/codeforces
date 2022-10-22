#include <bits/stdc++.h>
using namespace std;

int a[3010], c1[3010], c2[3010];

int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			memset(c1, 0, sizeof(c1)), memset(c2, 0, sizeof(c2));
			long long sum = 0;
			for (int j = i + 2; j < n; j++) {
				c2[a[j]]++;
			}
			for (int j = i + 1; j < n; j++) {
				if (a[i] == a[j]) ans += sum;
				sum -= c1[a[j]] * c2[a[j]];
				c1[a[j]]++;
				sum += c1[a[j]] * c2[a[j]];
				sum -= c1[a[j + 1]] * c2[a[j + 1]];
				c2[a[j + 1]]--;
				sum += c1[a[j + 1]] * c2[a[j + 1]];
			}
		}
		cout << ans << endl;
	}
	return 0;
}