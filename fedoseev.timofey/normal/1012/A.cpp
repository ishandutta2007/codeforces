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
	int n;
	cin >> n;
	vector <int> a(2 * n);
	for (int i = 0; i < 2 * n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = (ll)(a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	for (int i = 1; i < n; ++i) {
		ans = min(ans, (ll)(a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
	}
	cout << ans << '\n';
}