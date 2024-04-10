#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int rook, bishop, king;
	if (x1 == x2 || y1 == y2)
		rook = 1;
	else
		rook = 2;
	king = max(abs(x2 - x1), abs(y2 - y1));
	if ((x1 + y1) % 2 != (x2 + y2) % 2)
		bishop = 0;
	else {
		if (abs(x2 - x1) == abs(y2 - y1))
			bishop = 1;
		else
			bishop = 2;
	}
	cout << rook << " " << bishop << " " << king;
	return 0;
}