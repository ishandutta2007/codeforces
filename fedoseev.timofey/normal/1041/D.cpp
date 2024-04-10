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
    int n, h;
    cin >> n >> h;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    int cur = 0;
	int r = 0;
	int ans = 0;
	for (int l = 0; l < n; ++l) {
		if (l) {
			cur -= a[l].first - a[l - 1].second;
			cur = max(cur, 0ll);
		}
		r = max(r, l);
		while (r + 1 < n && cur + a[r + 1].first - a[r].second < h) {
			cur += a[r + 1].first - a[r].second;
			++r;
		}
		ans = max(ans, a[r].second - a[l].first + h - cur);
	}
	cout << ans << '\n';
}