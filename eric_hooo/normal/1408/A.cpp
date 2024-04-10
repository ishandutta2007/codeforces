#include <bits/stdc++.h>
using namespace std;

int a[110], b[110], c[110];
int ans[110];

int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		for (int i = 0; i < n; i++) {
			if (i == 0) ans[i] = a[i];
			else if (i != n - 1) {
				if (ans[i - 1] != a[i]) ans[i] = a[i];
				else if (ans[i - 1] != b[i]) ans[i] = b[i];
				else if (ans[i - 1] != c[i]) ans[i] = c[i];
			} else {
				if (ans[i - 1] != a[i] && ans[0] != a[i]) ans[i] = a[i];
				else if (ans[i - 1] != b[i] && ans[0] != b[i]) ans[i] = b[i];
				else if (ans[i - 1] != c[i] && ans[0] != c[i]) ans[i] = c[i];
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}