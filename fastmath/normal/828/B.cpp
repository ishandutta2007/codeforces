#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>


using namespace std;
#define int long long
int mod = 1e9 + 7;
int big_mod = 1e18 + 7;


signed main() {
	cout.precision(20);
	int n, m;
	char a[107][107];
	cin >> n >> m;
	int left = mod, right = -mod, up = mod, down = -mod;
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'B') {
				++k;
				left = min(left, j);
				right = max(right, j);
				up = min(up, i);
				down = max(down, i);
			}
		}
	}

	if (!k) {
		cout << 1;
		return 0;
	}


	if (right - left + 1 > n || down - up + 1 > m) {
		cout << -1;
		return 0;
	}
	else {
		if (right - left >= down - up) {
			int add = (right - left) - (down - up);
			if (add <= up) {
				up -= add;
			}
			else {
				down += (add - up);
				up = 0;
			}

			int ans = 0;
			for (int i = up; i <= down; ++i) {
				for (int j = left; j <= right; ++j) {
					if (a[i][j] != 'B') {
						++ans;
					}
				}
			}

			cout << ans;
		}
		else {
			int add = (down - up) - (right - left);
			if (add <= left) {
				left -= add;
			}
			else {
				right += (add - left);
				left = 0;
			}

			int ans = 0;
			for (int i = up; i <= down; ++i) {
				for (int j = left; j <= right; ++j) {
					if (a[i][j] != 'B') {
						++ans;
					}
				}
			}

			cout << ans;
		}
	}

	return 0;
}