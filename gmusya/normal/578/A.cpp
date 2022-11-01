#include <iostream>
#include <vector>
#include <iomanip>

#define fsp fixed << setprecision(9)

typedef long long ll;
typedef double long dl;

using namespace std;

const dl eps = 1e-9;

int main() {
	ll a, b;
	cin >> a >> b;
	if (a + eps < b) {
		cout << -1;
		return 0;
	}
	int minperiod = 2 * b;
	int cnt_minperiod = (a + b) / minperiod;
	cout << fsp << (a + b) / ((dl) 2 * cnt_minperiod);
	return 0;
}