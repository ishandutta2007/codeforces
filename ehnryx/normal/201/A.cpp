#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	if (x == 3)
		cout << 5 << endl;
	else {
		int n;
		for (n = 1; (n/2)*(n+1) + 1 < x; n+=2)
			;
		cout << n << endl;
	}
	return 0;
}