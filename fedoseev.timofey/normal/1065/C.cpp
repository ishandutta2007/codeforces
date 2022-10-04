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

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    sort(h.begin(), h.end());
	vector <ll> suf(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = suf[i + 1] + h[i];
	}
	int mn = h[0];
	int mx = h[n - 1];
	int cur = mx;
	int cnt = 0;
	int ans = 0;
	for (int i = mx - 1; i >= mn; --i) {
		int it = upper_bound(h.begin(), h.end() - cnt, i) - h.begin();
		ll need = suf[it] - suf[n - cnt] - (ll)i * (n - cnt - it) + (ll)(cur - i) * cnt;
		if (need > k) {
			++ans;
			cur = i + 1;
			cnt = (n - it);
		}
	}
	if (cur > mn) ++ans;
	cout << ans << '\n';
}