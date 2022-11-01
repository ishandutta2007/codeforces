#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n % 4) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}