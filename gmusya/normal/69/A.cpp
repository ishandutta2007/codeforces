#include <iostream>
#include <vector>

using namespace std;

int main() {
	int sumx = 0, sumy = 0, sumz = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		sumx += x;
		sumy += y;
		sumz += z;
	}
	if (sumx == 0 && sumy == 0 && sumz == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}