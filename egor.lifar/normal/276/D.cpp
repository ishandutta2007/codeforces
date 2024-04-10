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


long long l, r;
int a[64];
int b[64];
int c[64];


int main() {
	cin >> l >> r;
	for (int i = 0; i < 64; i++) {
		a[i] = l % 2LL;
		l /= 2LL;
		b[i] = r % 2LL;
		r /= 2LL;
	}
	for (int i = 63; i >= 0; i--) {
		if (a[i] == b[i]) {
			c[i] = 0;
		} else {
			for (int j = i; j >= 0; j--) {
				c[j] = 1;
			}
			break;
		}
	}
	long long ans = 0;
	for (int i = 63; i >= 0; i--) {
		//cout << c[i];
		ans *= 2LL;
		ans += 1LL * c[i];
	}
	//cout << endl;
	cout << ans << endl;
	return 0;	
}