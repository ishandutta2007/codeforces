#include <iostream>

using namespace std;

int main() {
	long long N, x, y; cin >> N >> x >> y;

	if (N > y) {
		cout << "-1\n";
		return 0;
	}


	long long a1 = y - N + 1, b1, a2, b2;
	a2 = 1;
	b2 = N - 1;
	b1 = 1;

	if (a1 * a1 * b1 + a2 * a2 * b2 < x)
		cout << "-1\n";
	else {
		for (int i = 0; i < b1; ++i)
			cout << a1 << "\n";
		for (int i = 0; i < b2; ++i)
			cout << a2 << "\n";
	}
}