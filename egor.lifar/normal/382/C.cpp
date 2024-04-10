#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 
using namespace std;


int a[100000];
int n;


bool gen() {
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
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
	if (n == 1) {
		cout << -1 << endl;
		return 0;
	}
	if (gen()) {
		cout << 1 << endl;
		cout << a[0] << endl;
		return 0;
	}
	if (n == 2) {
		int k = a[1] - a[0];
		if (k % 2  == 0){
			cout << 3 << endl;
			cout << a[0] - k << ' ' << a[0] + k / 2 << ' ' << a[1] + k << endl;
		} else {
			cout << 2 << endl;
			cout << a[0] - k << ' ' << a[1] + k << endl;
		}
		return 0;
	}
	bool b = true;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] != a[1] - a[0]) {
			b = false;
		}
	}
	if (b) {
		cout << 2 << endl;
		cout << a[0] - (a[1] - a[0]) << ' ' << a[n - 1] + (a[1] - a[0]) << endl;
		return 0;
	}
	int r = min(a[1] - a[0], a[2] - a[1]);
	int s = 0;
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] != r) {
			s++;
			k = i - 1;
		}
	}
	if (s == 1) {
		if (a[k + 1] - a[k] == 2 * r) {
			cout << 1 << endl;
			cout << a[k] + (a[k + 1] - a[k]) / 2 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}