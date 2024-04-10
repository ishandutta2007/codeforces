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
    n *= 2;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
	ll sum = 0;
	for (int i = 0; i < n / 2; ++i) sum += a[i];
	for (int i = n / 2; i < n; ++i) sum -= a[i];
	if (sum == 0) cout << "-1\n";
	else {
		for (auto x : a) cout << x << ' ';
	}
}