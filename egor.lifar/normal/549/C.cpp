#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n, k;
int a[1000000];


int main() {
	cin >> n >> k;
	int t = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		t += a[i] % 2;
	}
	if (k == n) {
		if (t % 2 == 1) {
			cout << "Stannis" << endl;
		} else {
			cout << "Daenerys" << endl;
		}
		return 0;
	}
	if ((n - k) % 2 == 1) {
		if (k % 2 == 0) {
			if ((n - k) / 2 >= t || (n - k) / 2 >= n - t) {
				cout << "Daenerys"  << endl;
			} else {
				cout << "Stannis" << endl;
			}
		} else {
			if ((n - k) / 2 >= t) {
				cout << "Daenerys" << endl;
			} else {
				cout << "Stannis" << endl;
			}
		}
	} else {
		if (k % 2 == 0) {
			cout << "Daenerys" << endl;
		} else {
			if ((n - k + 1) / 2 >= n - t) {
				cout << "Stannis" << endl;
			} else {
				cout << "Daenerys" << endl;
			}
		}
	}
 	return 0;
}