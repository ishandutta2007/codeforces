#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;



int a, b, c;
long long ans = 0;


int main() {
	cin >> a >> b >> c;
	while (a > 1 && b > 1 && c > 1) {
		ans += 2 * (a + b + c) - 6;
		a--;
		b--;
		c--;
	}
	if (a == 1 && b == 1 && c == 1) {
		ans += 1;
	}
	if (a == 1 && b != 1 && c != 1) {
		ans += b * c;
	}
	if (a != 1 && b == 1 && c != 1) {
		ans += a * c;
	}
	if (a != 1 && b != 1 && c == 1) {
		ans += a * b;
	}
	if (a == 1 && b == 1 && c != 1) {
		ans += c;
	}
	if (a != 1 && b == 1 && c == 1) {
		ans += a;
	}
	if (a == 1 && b != 1 && c == 1) {
		ans += b;
	}
	cout << ans << endl;
	return 0;
}