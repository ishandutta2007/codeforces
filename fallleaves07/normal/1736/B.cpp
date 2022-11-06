#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}
LL lcm(int a, int b) {
	return 1ll * a * b / gcd(a, b);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<LL> b(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			b[i] = a[i];
		} else {
			b[i] = lcm(a[i - 1], a[i]);
		}
	}
	b[n] = a[n - 1];
	for (int i = 0; i < n; i++) {
		if (gcd(b[i], b[i + 1]) != a[i]) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}