#include <iostream>

using namespace std;

int main() {
	int cnt = 0, n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (b - a >= 2)
			cnt++;
	}
	cout << cnt;
	return 0;
}