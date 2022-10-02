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


int n;
int x[200021];
long long d[200021];
long double ans = -1.0;


long double f(int i, int xx) {
	return double(d[n - 1] - d[n - xx] + d[i] - (i - xx >= 0 ? d[i - xx]: 0)) / double(2 * xx - 1) - x[i];
}


int main() {
	cin >> n;
	//n = 200001;
	//while (true) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		//x[i] = rand() % 1000000 + 1;
	}
	sort(x, x + n);
	if (n == 1) {
		cout << 1 << endl;
		cout << x[0] << endl;
		return 0;
	}
	if (n == 2) {
		cout << 2 << endl;
		cout << x[0] << ' ' << x[1] << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		d[i] = x[i];
		if (i > 0) {
			d[i] += d[i - 1];
		}
	}
	int t = 0, s = 1;
	for (int i = 0; i < n; i++) {
		int l = 1;
		int r = min(i + 1, n - i);
		while (l + 10 <= r) {
			int l1 = l + (r - l) / 3;
			int l2 = l + (r - l) / 3 * 2;
			if (f(i, l1) <= f(i, l2)) {
				l = l1;
			} else {
				r = l2 - 1;
			}
		}
		for (int j = l; j <= r; j++) {
			ans = max(ans, f(i, j));
			if (abs(ans - f(i, j)) < 1e-15)  {
				t = i;
				s = j;
			}
		}
	}
	cout << 2 * s - 1 << endl;
	for (int i = t - s + 1; i <= t; i++) {
		printf("%d ", x[i]);
	} 
	for (int i = n - s + 1; i < n; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
	return 0;
}