#include <iostream>

using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int x1, y1, x2, y2;

	x1 = (a - 1) / m + 1;
	y1 = (a - 1) % m + 1;

	x2 = (b - 1) / m + 1;
	y2 = (b - 1) % m + 1;

	int rez = 3;
	if (b == n)
		y2 = m;

	if (y1 == 1 || y2 == m || y2 == y1 - 1 || x1 == x2 - 1)
		rez = 2;

	if (x1 == x2 || (y1 == 1 && y2 == m))
        rez = 1;

	cout << rez;
}