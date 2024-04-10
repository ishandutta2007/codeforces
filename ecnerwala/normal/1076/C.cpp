#include<bits/stdc++.h>
using namespace std;

// they're roots to x^2 - dx + d = 0
// (d +- sqrt(d^2 - 4d)) / 2
int main() {
	int T; cin >> T;
	while (T--) {
		int d; cin >> d;
		if (d == 0) {
			cout << "Y" << ' ' << 0 << ' ' << 0 << '\n';
		} else if (d < 4) {
			cout << "N" << '\n';
		} else {
			cout << "Y" << ' ';
			double v = d * (d-4);
			v = sqrt(v);
			cout << fixed << setprecision(10) << (d+v) / 2 << ' ';
			cout << fixed << setprecision(10) << (d-v) / 2 << '\n';
		}
	}

	return 0;
}