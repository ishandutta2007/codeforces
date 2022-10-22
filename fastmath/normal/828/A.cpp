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
	int n, a, b;
	cin >> n >> a >> b;
	int one1, two1, two2 = 0;
	one1 = a;
	two1 = b;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			if (one1) {
				--one1;
			}
			else if (two1) {
				--two1;
				++two2;
			}
			else if (two2) {
				--two2;
			}
			else {
				++ans;
			}
		}
		else {
			if (two1) {
				--two1;
			}
			else {
				ans += 2;
			}
		}
	}

	cout << ans;
	return 0;
}