#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;


long long x[3];


int main() {
	cin >> x[0] >> x[1] >> x[2];
	sort(x, x + 3);
	if (x[0] == 0 && x[1] == 0) {
		cout << 0 << endl;
		return 0;
	}
	x[2] = min(x[2], (x[0] + x[1]) * 2);
	cout << (x[0] + x[1] + x[2]) / 3 << endl;
	return 0;
}