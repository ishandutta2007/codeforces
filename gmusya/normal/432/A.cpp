#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x + k <= 5)
			cnt++;
	}
	cout << cnt / 3;
	return 0;
}