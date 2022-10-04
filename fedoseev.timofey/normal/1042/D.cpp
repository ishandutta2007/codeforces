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

const int N = 2e5 + 7;

int t[N];

void modify(int x, int y) {
	for (int i = x; i < N; i |= (i + 1)) t[i] += y;
}

int get(int x) {
	int res = 0;
	for (int i = x; i >= 0; i &= (i + 1), --i) {
		res += t[i];
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; ll t;
    cin >> n >> t;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <ll> pref(n + 1);
	vector <ll> c;
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + a[i - 1];
	}
	for (int i = 0; i <= n; ++i) c.push_back(pref[i]);
	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int it = lower_bound(c.begin(), c.end(), pref[i]) - c.begin();
		modify(it, 1);
		ll cur = pref[i + 1] - t;
		it = upper_bound(c.begin(), c.end(), cur) - c.begin();
		if (it != 0) ans += get(--it);
	}
	cout << (ll)n * (n + 1) / 2 - ans << '\n';
}