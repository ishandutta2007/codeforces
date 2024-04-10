#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		bool tf = true;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if ((a || b) && x1 == x2) tf = false;
		if ((c || d) && y1 == y2) tf = false;
		x = x - a + b;
		y = y - c + d;
		if (!((x1 <= x && x <= x2) && (y1 <= y && y <= y2))) tf = false;
		if (tf) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}