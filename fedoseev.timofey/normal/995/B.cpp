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
	int n;
	cin >> n;
	vector <int> a(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int j = 0; j < 2 * n; j += 2) {
		if (a[j] == a[j + 1]) continue;
		int k = -1;
		for (int t = j + 1; t < 2 * n; ++t) {
			if (a[t] == a[j]) k = t;
		}
		while (k != j + 1) {
			++ans;
			swap(a[k], a[k - 1]);
			--k;
		}
	}
	cout << ans << '\n';
}