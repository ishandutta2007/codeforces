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
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	if (n == 1) {
		cout << a[0] << '\n';
		return 0;
	}
	sort(a.begin(), a.end());
	ll ans = -a[0];
	for (int i = 1; i < n; ++i) {
		if (i != n - 1) ans += abs(a[i]);
		else ans += a[i];
	}
	cout << ans << '\n';
}