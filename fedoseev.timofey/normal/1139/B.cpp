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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
	int x = a[n - 1];
	for (int i = n - 1; i >= 0; --i) {
		x = min(x, a[i]);
		ans += max(0, x);
		--x;
	}
	cout << ans << '\n';
}