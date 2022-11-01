#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool mod2_0, mod2_1;
	mod2_0 = false;
	mod2_1 = false;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) mod2_0 = true;
		if (a[i] % 2 == 1) mod2_1 = true;
	}
	if (mod2_0 && mod2_1) sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}