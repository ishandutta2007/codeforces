#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nod(int a, int b) {
	if (b % a == 0)
		return a;
	return nod(b % a, a);
}

int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		int r, b, k;
		cin >> r >> b >> k;
		int n1 = max(r, b) / nod(r, b);
		int n2 = min(r, b) / nod(r, b);
		/*if ((n1 + n2 - 1) / n2 > k || k == 1)
			cout << "REBEL" << endl;
		else
			cout << "OBEY" << endl;
			*/
		if ((n1 - 2) / n2 >= k - 1)
			cout << "REBEL" << endl;
		else
			cout << "OBEY" << endl;
	}
	return 0;
}