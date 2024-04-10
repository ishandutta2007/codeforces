#include <iostream>

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		if (n == 1 || m == 1 || (n == 2 && m == 2)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}