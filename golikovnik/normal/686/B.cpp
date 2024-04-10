#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + 1 < n; ++j) {
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				cout << j + 1 << " " << j + 2 << "\n";
			}
		}
	}
	return 0;
}