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
int a[500000];



bool get(int k) {
	if (k == 0) {
		return true;
	}
	for (int i = 0; i < k; i++) {
		if (a[n - k + i] < 2 * a[i]) {
			return false;
		}
	}
	return true;
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 0;
	int r = n / 2;
	while (l != r) {
		int m = (l + r + 1) / 2;
		if (get(m)) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	cout << n - l << endl;
	return 0;
}