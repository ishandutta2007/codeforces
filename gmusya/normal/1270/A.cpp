#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		bool tf = false;
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		for (int i = 0; i < k1; i++) {
			int x;
			cin >> x;
			if (x == n)
				tf = true;
		}
		for (int i = 0; i < k2; i++)
			cin >> n;
		if (tf)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}