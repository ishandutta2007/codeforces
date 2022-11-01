#include <iostream>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	while (n > 0) {
		cnt += n % 2;
		n /= 2;
	}
	cout << cnt;
	return 0;
}