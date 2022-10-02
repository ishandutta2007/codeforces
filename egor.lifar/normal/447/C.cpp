#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
int a[100000];
int ans = 0;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0;
	int r = 0;
	while ((r < n - 1 && r >= 0 && a[r + 1] > a[r]) || (r == 0 && r < n - 1)) {
		r++;
	}
	int r1 = 0;
	while ((r1 < n - 1 && r1 >= 0 && a[r1 + 1] > a[r1]) || (r1 == 0 && r1 < n - 1)) {
		r1++;
	}
	for (int i = 0; i < n; i++) {
		//cout << l + 1 << ' ' << r + 1 << endl;
		ans = max(ans, 1 + i - l + r - i);
		ans = max(ans, r1 - i + 1);
		if (i >= 1 && a[i] <= a[i - 1]) {
			l = i;
		}
		if (i == r) {
			r = i + 1;
		}
		if (i == r1) {
			r1 = i + 1;
		}
			while ((r < n - 1 && a[r + 1] > a[r]) || (r == i + 1 && r < n - 1)) {
				if (r == i + 1 && l != i + 1 && a[r + 1] <= a[r - 1] + 1) {
					break;
				}
				r++;
			}
			while ((r1 < n - 1 && a[r1 + 1] > a[r1]) || (r1 == i + 1 && r1 < n - 1)) {
				r1++;
			}
	}
	cout << ans << endl;
	return 0;
}