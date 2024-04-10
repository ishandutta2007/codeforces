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


int x, y, z, k;


int main() {
	cin >> x >> y >> z >> k;
	k = min(k, x + y + z - 3);
	int a[3] = {0, 0, 0};
	for (int i = 0; i < k; i++) {
		if (a[0] < x - 1 && (a[0] <= a[1] || a[1] >= y - 1) && (a[0] <= a[2] || a[2] >= z - 1)) {
			a[0]++;
			continue;
		}
		if (a[1] < y - 1 && (a[1] <= a[0] || a[0] >= x - 1) && (a[1] <= a[2] || a[2] >= z - 1)) {
			a[1]++;
			continue;
		}
		if (a[2] < z - 1 && (a[2] <= a[0] || a[0] >= x - 1) && (a[2] <= a[1] || a[1] >= y - 1)) {
			a[2]++;
			continue;
		}
	}
	cout << 1LL * (a[0] + 1LL) * (a[1] + 1LL) * (a[2] + 1LL) << endl;
 	return 0;
}