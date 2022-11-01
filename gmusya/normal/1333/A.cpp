#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << "W";
		for (int i = 1; i < m; i++) cout << "B";
		cout << endl;
		for (int i = 1; i < n; i++) {
			for (int i = 0; i < m; i++)
				cout << "B";
			cout << endl;
		}
	}
	return 0;
}