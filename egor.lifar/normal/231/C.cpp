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


using namespace std;


int n;
long long k;
long long a[100001];
long long d[100001];


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		d[i] = (i > 0 ? d[i - 1]: 0LL);
		d[i] += a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = 0;
		while (l != r) {
			int m = (l + r) / 2;
			if (a[i] * (i - m + 1) - d[i] + (m > 0 ? d[m - 1]: 0) <= k) {
				l = m;
			} else {
				r = m + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = 0;
		while (l != r) {
			int m = (l + r) / 2;
			if (a[i] * (i - m + 1) - d[i] + (m > 0 ? d[m - 1]: 0) <= k) {
				l = m;
			} else {
				r = m + 1;
			}
		}
		if (ans == i - l + 1) {
			cout << a[i] << endl;
			return 0;
		}
	}
    return 0;
}