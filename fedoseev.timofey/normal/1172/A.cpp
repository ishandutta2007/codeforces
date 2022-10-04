#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int cnt = 0;
	bool fl = true;
	for (int i = 0; i < n; ++i) {
		if (b[i] == 1) {
			for (int j = 0; i + j < n; ++j) {
				fl &= (b[i + j] == (b[i] + j));
			}
		}
	}
	if (fl) {
		for (int i = 0; i < n; ++i) {
			if (b[i] == 1) break;
			if (b[i] > 0) {
				fl &= (i <= (b[i] - b[n - 1] - 2));
			}
		}
	}
	if (fl) {
		cout << n - b[n - 1] << '\n';
	}
	else {
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i] > 0) {
				int need_pos = b[i] - 2;
				ans = max(ans, i - need_pos);
			}
		}
		cout << ans + n << '\n';
	}
}