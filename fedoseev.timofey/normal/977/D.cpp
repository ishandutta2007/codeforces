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
	vector <ll> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		vector <ll> ans;
		ll cur = a[i];
		ans.push_back(a[i]);
		for (int j = 0; j < n - 1; ++j) {
			bool done = 0;
			for (int k = 0; k < n; ++k) {
				if (cur % 3 == 0 && a[k] == cur / 3) {
					ans.push_back(a[k]);
					done = 1;
					cur = a[k];
					break;
				}
				if (a[k] == cur * 2) {
					ans.push_back(a[k]);
					done = 1;
					cur = a[k];
					break;
				}
			}
			if (!done) break;
		}
		if (ans.size() == n) {
			for (auto e : ans) {
				cout << e << ' ';
			}
			return 0;
		}
	}
}