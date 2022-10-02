#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <vector>
#include <map>
 

using namespace std;


int a, x, y;


int main() {
	cin >> a >> x >> y;
	int t = y / a;
	if (y % a == 0) {
		cout << -1 << endl;
		return 0;
	}
	int p = (t - 1 >= 0 ? 1: 0) + ((t - 1) > 0 ? t / 2 + ((t - 1) / 2) * 2: 0);
	//cout << p << endl;
	if (t >= 2 && t % 2 == 0) {
		if (x < 0) {
			if (x > -a && x != 0) {
				cout << p + 1 << endl;
			} else {
				cout << -1 << endl;
			}
		} else {
			if (x < a && x != 0) {
				cout << p + 2 << endl;
			} else {
				cout << -1 << endl;
			}
		}
	} else {
		if (abs(x) < double(a) / 2.0) {
			cout << p + 1 << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}