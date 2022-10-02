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
#include <assert.h>


using namespace std;


long long h, n;


int main() {
	cin >> h >> n;
	long long t = 1;
	for (int i = 0; i < h - 1; i++) {
		t *= 2LL;
	}
	long long ans = 0;
	if (1LL == n && h == 1LL) {
		cout << 1 << endl;
		return 0;
	}
	long long ans1 = 1;
	int k = 0;
	while (t != 0) {
		if (t == 1) {
			if (ans + t < n && k == 0) {
				cout << ans1 + 1 << endl;
			} else {
				if (k == 0) {
					cout << ans1 << endl;
				} else {
					if (ans + t + 1 > n) {
						cout << ans1 + 1 << endl;
					} else {
						cout << ans1 << endl;
					}
				}
			}
			return 0;
		}
		if (k == 0 && ans + t < n) {
			ans += t;
			long long k1 = 1;
			while (k1 <= t) {
				ans1 += k1;
				k1 *= 2LL;
			}
			ans1++;
		} else {
			if (k == 0) {
				ans1++;
				k = 1 - k;
			} else {
				if (ans + t + 1 > n) {
					long long k1 = 1;
					while (k1 <= t) {
						ans1 += k1;
						k1 *= 2LL;
					}
					ans1++;
				} else {
					ans1++;
					ans += t;
					k = 1 - k;
				}
			}
		}
		// /cout << ans << endl;
		t /= 2;
	}
//	cout << ans1 - 1 << endl;
  	return 0; 
}