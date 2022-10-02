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


long long k, n, w;


int main() {
	cin >> k >> n >> w;
	long long sum = ((w * (w + 1LL)) / 2LL) * k;
	if (sum <= n) {
		cout << 0 << endl;
	} else {
		cout << sum - n << endl;
	}
	return 0;
}