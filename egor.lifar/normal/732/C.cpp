#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <complex>


using namespace std;


int main() {
	long long a[3];
	cin >> a[0] >> a[1] >> a[2];
	if (a[0] == 1 && a[1] == 0 && a[2] == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (a[0] == 0 && a[1] == 1 && a[2] == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (a[0] == 0 && a[1] == 0 && a[2] == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (a[0] == 1 && a[1] == 1 && a[2] == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (a[0] == 0 && a[1] == 1 && a[2] == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (a[0] == 1 && a[1] == 0 && a[2] == 1) {
		cout << 0 << endl;
		return 0;
	}
	long long ans = 3e18;
	for (int i = 0; i <= 3; i++) {
		for (int k = i; k < 3; k++) {
			a[k]--;
		}
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k < j; k++) {
				a[k]--;
			}
			long long st = 0;
			long long l = max(a[2], max(a[0], a[1]));
			l = max(l, 0LL);
			if (a[0] < 0) {
				st -= a[0];
				st += l;
			} else {
				st += l - a[0];
			}
			if (a[1] < 0) {
				st -= a[1];
				st += l;
			} else {
				st += l - a[1];
			}
			if (a[2] < 0) {
				st -= a[2];
				st += l;
			} else {
				st += l - a[2];
			}
			ans = min(ans, st);
			//cout << st << ' ' << i << ' ' << j << endl;
			for (int k = 0; k < j; k++) {
				a[k]++;
			}
		}
		for (int k = i; k < 3; k++) {
			a[k]++;
		}
	}
	cout << ans << endl;
	return 0;
}