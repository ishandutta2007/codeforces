#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > y1) swap(x1, y1);
		if (x2 > y2) swap(x2, y2);
		if (x1 + x2 == y1 && x1 + x2 == y2) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}