#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
int a[100000];
int k = 0;


int main() {
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			k++;
		}
		a[i] = abs(a[i]);
	}
	if (k % 2 == 0 || (k - n >= 0 && (k - n) % 2 == 0) || (k % 2 == 1 && n % 2 == 1)) {
		k = 0;
	} else {
		k = 1;
	}
	sort(a, a + 2 * n - 1);
	long long ans = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (i == 0 && k == 1) {
			ans -= a[i];
		} else {
			ans += a[i];
		}
	}
	cout << ans << endl;
	return 0;
}