#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << (n * m + 1) / 2 << '\n';
	}
	return 0;
}