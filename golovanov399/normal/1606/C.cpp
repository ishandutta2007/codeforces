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

const vector<int> tp = []() { vector<int> res(10, 1); for (int i = 1; i < 10; ++i) res[i] = res[i - 1] * 10; return res; }();

void solve() {
	int n = nxt(), k = nxt() + 1;
	vector<int> a(n);
	generate(all(a), nxt);
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int tmp = min(k, tp[a[i + 1] - a[i]] - 1);
		ans += tmp * tp[a[i]];
		k -= tmp;
	}
	ans += 1ll * tp[a[n - 1]] * k;
	cout << ans << "\n";
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