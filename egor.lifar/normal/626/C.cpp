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

using namespace std;


int n, m;


int main() {
	cin >> n >> m;
	int l = 2;
	int r = 10002000;
	while (l != r) {
		int k = (l + r) / 2;
		if (k < n * 2 || k < m * 3) {
			l = k + 1;
			continue;
		}
		int cnt = k / 2;
		int f = k / 3 - k / 6;
		cnt -= n;
		f += min(cnt, k / 6);
		if (f >= m) {
			r = k;
		} else {
			l = k + 1;
		}
	}
	cout << l << endl;
	return 0;
}