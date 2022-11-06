#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> rc(n);
	LL len = 0, mx = 0;
	for (auto &[x, y] : rc) {
		cin >> x >> y;
		if (x < y) {
			swap(x, y);
		}
		len += y, mx = max(mx, (LL)x);
	}
	printf("%lld\n", (len + mx) * 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}