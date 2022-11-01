#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 1) cout << -1 << endl;
		else {
			cout << 2;
			for (int i = 1; i < n; i++) cout << 3;
			cout << endl;
		}
	}
	return 0;
}