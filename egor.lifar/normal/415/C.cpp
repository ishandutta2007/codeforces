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


int n, k;
int a[100000];


int main() {
	cin >> n >> k;
	if (n == 1) {
		if (k == 0) {
			cout << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	}
	if (k < n / 2) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = 1000000000 - i;
	}
	a[0] = k - (n / 2 - 1);
	a[1] = 2 * (k - (n / 2 - 1));
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}