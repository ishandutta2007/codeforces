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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	ll ans = 2e18;
	int cnt1 = 0, cnt0 = 0;
	if (s[0] == '0') ++cnt0;
	else ++cnt1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) {
			if (s[i] == '1') ++cnt1;
			else ++cnt0;
		}
	}
	if (cnt0 != 0) ans = min(ans, (ll)(cnt0 - 1) * x + y);
	ans = min(ans, (ll)cnt0 * y);
	ans = min(ans, (ll)(cnt1 + 1) * y);
	cout << ans << '\n';
}