#include <iostream>
#include <vector>

using namespace std;

int main() {
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	vector <bool> tf(d + 1, false);
	for (int i = 1; i <= d; i++) {
		if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
			tf[i] = true;
	}
	int cnt = 0;
	for (int i = 0; i <= d; i++)
		cnt += tf[i];
	cout << cnt;
	return 0;
}