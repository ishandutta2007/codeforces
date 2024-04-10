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

const int K = 60;

void remax(int& x, int y) {
	x = (x > y) ? x : y;
}

const int N = 101'111;
int last[N * 2];
int cnt[N * 2];
int timer = 0;

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);

	int ans = 0;
	auto check_step = [&](int step) {
		unordered_map<long long, int> M;
		for (int i = 0; i < n; ++i) {
			long long x = a[i] - 1ll * step * i;
			remax(ans, ++M[x]);
		}
	};

	auto add = [&](int pos) {
		pos += N;
		if (last[pos] != timer) {
			last[pos] = timer;
			cnt[pos] = 1;
		}
		remax(ans, ++cnt[pos]);
	};

	for (int i = -K; i <= K; ++i) {
		check_step(i);
		// cerr << "checked " << i << ", ";
	}
	const int len = 1e5 / K + 10;
	for (int i = 0; i < n; ++i) {
		++timer;
		for (int j = 1; j <= len && i + j < n; ++j) {
			if ((a[i + j] - a[i]) % j == 0) {
				add((a[i + j] - a[i]) / j);
			}
		}
	}

	cout << n - ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}