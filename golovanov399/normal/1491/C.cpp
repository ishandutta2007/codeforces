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
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	long long ans = 0;
	vector<int> nx(n + 1, n);
	for (int i = n - 1; i >= 0; --i) {
		nx[i] = (a[i] > 1) ? i : nx[i + 1];
	}
	auto jump = [&](int pos) {
		++ans;
		while (pos < n) {
			int& val = a[pos];
			if (val > 1) {
				int from = pos;
				pos += val;
				--val;
				if (val == 1) {
					for (int i = from; i >= 0 && a[i] == 1; --i) {
						nx[i] = nx[i + 1];
					}
				}
			} else {
				pos = nx[pos];
			}
		}
	};
	for (int i = 0; i < n; ++i) {
		auto tmp = max(0, i + a[i] - n);
		ans += tmp;
		a[i] -= tmp;
		while (a[i] > 1) {
			jump(i);
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}