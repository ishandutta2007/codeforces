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
long long l, r, ql, qr;
int w[100000];
long long dr[100000], dl[100000];
long long ans = 1000000000000000LL;


int main() {
	cin >> n >> l >> r >> ql >> qr;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		dl[i] = (i > 0 ? dl[i - 1]: 0) + w[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		dr[i] = (i < n - 1 ? dr[i + 1]: 0) + w[i];
	}
	for (int i = 0; i <= n; i++) {
		long long s = 0;
		if (n - i > i) {
			s = (max(n - i - i - 1, 0)) * qr;
		} else {
			s = (max(i - n + i - 1, 0)) * ql;
		}
		ans = min(ans, (i > 0 ? dl[i - 1]: 0) * l + (i <= n - 1 ? dr[i]: 0) * r + s);
	}
	cout << ans << endl;
	return 0;
}