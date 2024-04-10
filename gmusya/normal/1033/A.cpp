#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, x1, y1, x2, y2, x3, y3;
	cin >> n >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (((x1 > x2 && x1 > x3) || (x1 < x2 && x1 < x3)) && ((y1 > y2 && y1 > y3) || (y1 < y2 && y1 < y3)))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}