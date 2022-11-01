#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	int cur = (m + 1) / 2;
	while (cnt < n) {
		if (cur < 1 || cur > m)
			cur = (m + 1) / 2;
		cout << cur << endl;
		cnt++;
		if (cur == (m + 1) / 2 && m % 2 == 1) {
			cur--;
			continue;
		}
		if (cur <= m / 2) {
			cur = m + 1 - cur;
			continue;
		}
		cur = m - cur;
	}
	return 0;
}