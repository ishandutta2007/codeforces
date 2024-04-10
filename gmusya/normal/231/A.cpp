#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c > 1)
			cnt++;
	}
	cout << cnt;
	return 0;
}