#include <iostream>

using namespace std;

inline int64_t gcd(int64_t a, int64_t b) {
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int64_t p, q, b; cin >> p >> q >> b;
		int64_t g = gcd(p, q);
		p /= g; q /= g;
		bool ok = true;
		for (;;) {
			if (q == 1) {
				break;
			}
			int64_t g = gcd(q, b);
			if (g == 1) {
				ok = false;
				break;
			}
			q /= g;
			b = g;
		}
		cout << (ok ? "Finite" : "Infinite") << "\n";
	}
	return 0;
}