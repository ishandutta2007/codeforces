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
	vector <string> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	vector <bool> useda(n), usedb(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = 1e9;
		int ii = -1, jj = -1;
		for (int j = 0; j < n; ++j) {
			for (int t = 0; t < n; ++t) {
				if (useda[j] || usedb[t]) continue;
				if (a[j].size() != b[t].size()) continue;
				int res = 0;
				for (int k = 0; k < a[j].size(); ++k) {
					if (a[j][k] != b[t][k]) ++res;
				}
				if (res < cur) {
					ii = j;
					jj = t;
					cur = res;
				}
			}
		}
		useda[ii] = 1;
		usedb[jj] = 1;
		ans += cur;
	}
	cout << ans << '\n';
 }