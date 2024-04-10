#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, n;
		cin >> a >> b >> n;
		if (a > b) swap(a, b);
		int x = 0;
		while (b <= n) {
			a += b;
			swap(a, b);
			x++;
		}
		cout << x << '\n';
	}
	return 0;
}