#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int num = k / (n - 1) * n;
		if (k % (n - 1) == 0) num--;
		else num += k % (n - 1);
		cout << num << '\n';
	}
	return 0;
}