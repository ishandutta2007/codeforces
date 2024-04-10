#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


int main() {
	long long n;
	cin >> n;
	if (n == 0LL) {
		cout << 0 << endl;
		return 0;
	}
	n %= 360LL;
	n *= -1;
	if (n < 0) {
		n = 360 - abs(n);
	}
	int t = min(n, 360 - n);
	int f = 0;
	for (int i = 1; i <= 1000; i++) {
		n += 90;
		n %= 360;
		//cout << n << endl;
		if (n < t || 360 - n < t) {
			t = min(n, 360 - n);
			f = i;
		}
	}
	//cout << t << endl;
	cout << f << endl;
	return 0;
}
//1 1 3
//1 3 1
//3 1 1
//1 2 2