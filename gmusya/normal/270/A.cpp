#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (360 % (180 - n) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}