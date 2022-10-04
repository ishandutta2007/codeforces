#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	if (k == 0) {
		if (a[0] != 1) {
			cout << 1 << '\n';
		}
		else {
			cout << -1 << '\n';
		}
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (i == n - 1 || a[i] != a[i + 1]) {
			if (i + 1 == k) {
				cout << a[i] << '\n';
				return 0;
			}
		}
	}
	cout << -1 << '\n';
}