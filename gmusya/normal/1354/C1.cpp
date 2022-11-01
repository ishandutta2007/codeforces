#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define fsp fixed << setprecision(10) 

using namespace std;

typedef double long dl;

const dl pi = atan2(0, -1);

int main() {
	int t;
	cin >> t;
	while (t--) {
		dl n;
		cin >> n;
		dl ans = 1 / tan(pi / (2 * n));
		cout << fsp << ans << '\n';
	}
	return 0;
}