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
	vector <int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	vector <int> dp(n), p(n, -1);
	map <int, int> best;
	for (int i = 0; i < n; ++i) {
		if (best.count(a[i] - 1)) {
			dp[i] = dp[best[a[i] - 1]] + 1;
			p[i] = best[a[i] - 1];
		}
		if (!best.count(a[i])) {
			best[a[i]] = i;
		}
		else {
			if (dp[best[a[i]]] < dp[i]) {
				best[a[i]] = i;
			}
		}
	}
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if (dp[i] > dp[ind]) ind = i;
	}
	vector <int> ans;
	ans.push_back(ind);
	while (p[ind] != -1) {
		ind = p[ind];
		ans.push_back(ind);
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto e : ans) {
		cout << e + 1 << ' ';
	}
}