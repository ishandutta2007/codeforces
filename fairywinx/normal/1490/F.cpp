#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> cnt;
	map<int, int> z;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		z[a]++;
	}
	int now_open = 0;
	int ans = n;
	int now = n;
	vector<int> c(n + 1);
	for (auto i : z) {
		++now_open;
		++c[i.second];
	}
	for (int i = 0; i <= n; ++i) {
		now += c[i] * i;
		now_open -= c[i];
		now -= now_open;
		ans = min(ans, now);
	}
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}