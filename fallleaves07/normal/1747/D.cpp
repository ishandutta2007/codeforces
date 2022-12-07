#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), sr(n + 1);
	map<int, array<vector<int>, 2>> loc;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] ^= a[i - 1];
		loc[a[i]][i & 1].emplace_back(i);
	}
	sr[n] = n;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i + 1] == a[i]) {
			sr[i] = sr[i + 1];
		} else {
			sr[i] = i;
		}
	}
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r, --l;
		if (a[l] != a[r]) {
			puts("-1");
			continue;
		}
		if (sr[l] >= r) {
			puts("0");
		} else if ((r - l) % 2 == 1) {
			puts("1");
		} else {
			if (a[l + 1] == a[l] || a[r - 1] == a[r]) {
				puts("1");
				continue;
			}
			auto &lc = loc[a[l]][(l & 1) ^ 1];
			int x = lower_bound(lc.begin(), lc.end(), l) - lc.begin();
			if (x >= (int)lc.size() || lc[x] > r) {
				puts("-1");
			} else {
				puts("2");
			}
		}
	}
	return 0;
}