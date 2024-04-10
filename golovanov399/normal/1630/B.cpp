#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	vector<int> cnt(n + 1);
	for (int x : a) {
		cnt[x] += 1;
	}
	partial_sum(all(cnt), cnt.begin());
	// cnt[i] = #{x <= i}
	pair<int, int> opt = {-100, n};
	// we need #in - #out >= k
	// that is, 2 * #in >= k + n
	// #in >= (k + n + 1) / 2
	{
		int l = 0, r = 0;
		for (; l < n; ++l) {
			while (r <= n && cnt[r] < cnt[l] + (k + n + 1) / 2) {
				++r;
			}
			if (r > n) {
				break;
			}
			if (r - l < opt.second - opt.first) {
				opt = {l, r};
			}
		}
	}
	auto [l, r] = opt;
	l += 1;
	cout << l << " " << r << "\n";
	vector<int> first(k + 1, -1);
	first[0] = 0;
	for (int i = 0, bal = 0; i < n; ++i) {
		bal += clamp(a[i], l, r) == a[i] ? 1 : -1;
		if (clamp(bal, 0, k) == bal && first[bal] == -1) {
			first[bal] = i + 1;
		}
	}
	first[k] = n;
	for (int i = 0; i < k; ++i) {
		cout << first[i] + 1 << " " << first[i + 1] << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}