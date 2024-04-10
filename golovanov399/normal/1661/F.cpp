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

long long sqr(long long x) {
	return x * x;
}

long long f(int l, int n) {
	return n * sqr(l / n) + (l % n) * (1 + 2 * (l / n));
}

void add(map<long long, long long>& M, int l) {
	int n = 1;
	while (n <= l) {
		int k = l / n;
		int nn = l / k + 1;
		if (n < nn - 1) {
			M[1ll * k * (k + 1)] += nn - n - 1;
		}
		// assert(f(l, nn - 1) == f(l, n) - (nn - n - 1) * 1ll * k * (k + 1));
		if (nn <= l) {
			M[f(l, nn - 1) - f(l, nn)] += 1;
		}
		n = nn;
	}
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int last = 0, i = 0; i < n; ++i) {
		a[i] -= last;
		last += a[i];
	}
	long long cur = 0;
	for (int x : a) {
		cur += sqr(x);
	}
	long long m;
	cin >> m;
	long long need = cur - m;
	if (need <= 0) {
		cout << "0\n";
		return;
	}

	map<long long, long long> diffs;
	for (int x : a) {
		add(diffs, x);
	}

	int ans = 0;
	for (auto it = diffs.end(); it != diffs.begin();) {
		--it;
		// cerr << it->first << " " << it->second << "\n";
		if (it->first * it->second < need) {
			need -= it->first * it->second;
			ans += it->second;
		} else {
			ans += (need + it->first - 1) / it->first;
			break;
		}
	}
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