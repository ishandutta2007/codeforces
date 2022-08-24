#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	vector<long long> linear(n + 1);
	vector<long long> constant(n + 1);
	long long curl = 0, curc = 0;
	for (int i = n - 1; i >= k; --i) {
		curl += linear[i];
		curc += constant[i];
		a[i] -= curl * i + curc;
		if (a[i] > 0) {
			long long tmp = (a[i] + k - 1) / k;
			// we add (idx - i + k) tmp times
			linear[i - k] -= tmp;
			constant[i - k] += (i - k) * tmp;
			curl += tmp;
			curc -= (i - k) * tmp;
			ans += tmp;
		}
	}
	long long mx = 0;
	for (int i = k - 1; i >= 0; --i) {
		curl += linear[i];
		curc += constant[i];
		a[i] -= curl * i + curc;
		if (a[i] > 0) {
			mx = max(mx, (a[i] + i) / (i + 1));
		}
	}
	ans += mx;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}