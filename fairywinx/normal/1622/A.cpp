#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
	array<int, 3> a;
	for (int i = 0; i < 3; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			int k = 1 + 2 - i - j;
			if (a[i] + a[j] == a[k]) {
				cout << "YES\n";
				return;
			}
			if (a[i] == a[j] && a[k] % 2 == 0) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}