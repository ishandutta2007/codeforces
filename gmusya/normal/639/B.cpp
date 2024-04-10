#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, h, d;
	cin >> n >> d >> h;
	if (h > d || 2 * h < d) {
		cout << -1;
		return 0;
	}
	if (d == 1 && n != 2) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= h; i++)
		cout << i << " " << i + 1 << endl;
	if (h == d) {
		for (int i = d + 2; i <= n; i++)
			cout << 2 << " " << i << endl;
		return 0;
	}
	cout << 1 << " " << h + 2 << endl;
	for (int i = h + 2; i <= d; i++)
		cout << i << " " << i + 1 << endl;
	for (int i = d + 2; i <= n; i++)
		cout << 1 << " " << i << endl;
	return 0;
}