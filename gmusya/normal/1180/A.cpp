#include <iostream>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	int i = 1;
	while (i <= n) {
		if (i == 1) cnt++;
		if (i > 1) cnt += 4 * (i - 1);
		i++;
	}
	cout << cnt;
	return 0;
}