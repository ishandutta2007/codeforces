#include <bits/stdc++.h>

using namespace std;

int sigma(int x) {
	int ret = 0;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			if (x / i == i) {
				ret++;
			} else {
				ret += 2;
			}
		}
	}
	return ret;
}

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int A = sigma(a), B = sigma(b), C = sigma(c);
		int AB = sigma(gcd(a, b)), AC = sigma(gcd(a, c)), BC = sigma(gcd(b, c));
		int ABC = sigma(gcd(gcd(a, b), c));
		int ans = A * B * C - AB * BC * AC + ABC * (AB * BC + BC * AC + AC * AB) - A * (BC) * (BC-1) / 2 - B * AC * (AC-1) / 2 - C * AB * (AB-1) / 2 - ABC * (ABC + 1) * (AB + BC + AC) / 2 + ABC * (ABC + 1) * (ABC + 2) / 6;
		cout << ans << endl;
	}
	return 0;
}