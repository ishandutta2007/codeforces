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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> b(m);
	for (int i = 0; i < m; ++i) cin >> b[i];
	int x;
	cin >> x;
	vector <pair <int, int>> have;
	for (int l = 0; l < m; ++l) {
		int sum = 0;
		for (int r = l; r < m; ++r) {
			sum += b[r];
			have.push_back({sum, r - l + 1});
		}
	}
	sort(have.begin(), have.end());
	for (int i = 1; i < have.size(); ++i) {
		have[i].second = max(have[i].second, have[i - 1].second);
	}
	int ans = 0;
	for (int l = 0; l < n; ++l) {
		int sum = 0;
		for (int r = l; r < n; ++r) {
			sum += a[r];
			int id = upper_bound(have.begin(), have.end(), make_pair(x / sum, (int)1e9)) - have.begin();
			if (id != 0) {
				ans = max(ans, (r - l + 1) * (have[id - 1].second));
			}
		}
	}
	cout << ans << '\n';
}