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


unsigned long long a, b;

int main() {
	cin >> a >> b;
	vector<int> v, v1;
	unsigned long long a1 = a, b1 = b;
	while (a > 0) {
		v.push_back(a % 2LL);
		a /= 2LL;
	}
	while (b > 0) {
		v1.push_back(b % 2LL);
		b /= 2LL;
	}
	int ans = 0;
	for (int i = (int)v.size(); i <= (int)v1.size(); i++) {
		//cout << i << endl;
		for (int j = 1; j < i; j++) {
			unsigned long long c = 0;
			for (int g = 0; g < j; g++) {
				c *= 2LL;
				c += 1LL;
			}
			c *= 2LL;
			for (int g = j + 1; g < i; g++) {
				c *= 2LL;
				c += 1LL;
			}
			if (c >= a1 && c <= b1) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}