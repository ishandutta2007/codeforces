#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b; cin >> a >> b;
	int c = min(a, b);
	int64_t res = 1;
	for (int i = 1; i <= c; i++) {
		res *= i;
	}
	cout << res << endl;
	return 0;
}