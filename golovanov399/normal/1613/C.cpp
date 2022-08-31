#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	long long h;
	cin >> h;
	vector<int> a(n);
	generate(all(a), nxt);
	auto calc = [&](long long k) {
		long long last = -1;
		long long ans = 0;
		for (int x : a) {
			if (x > last) {
				last = x;
			}
			ans += x + k - last;
			last = x + k;
		}
		return ans;
	};
	long long l = 0, r = h;
	while (r > l + 1) {
		long long m = (l + r) / 2;
		((calc(m) >= h) ? r : l) = m;
	}
	cout << r << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}