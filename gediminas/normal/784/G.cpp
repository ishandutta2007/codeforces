/*input
5-5
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main () {

	long long x;
	cin >> x;
	long long y;
	char z;

	while (cin >> z >> y) {
		if (z == '+')
			x += y;
		else
			x -= y;
	}
	vector<int> sk;

	while (x > 0) {
		sk.push_back(x % 10);
		x /= 10;
	}

	if(sk.size()==0){
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++.>\n";
	}

	for (int i = sk.size() - 1; i >= 0; i--) {
		for (int j = 0; j < sk[i]; j++)
			cout << '+';

		cout << "++++++++++++++++++++++++++++++++++++++++++++++++.>\n";
	}

	return 0;
}