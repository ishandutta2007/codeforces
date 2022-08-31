#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	vector<int> b(k);
	generate(all(b), nxt);
	sort(all(b));
	reverse(all(b));
	long long ans = 0;
	while (!b.empty() && b.back() == 1) {
		ans += 2 * a.back();
		a.pop_back();
		b.pop_back();
	}
	k = b.size();
	for (int i = 0, j = 0; j < k; ++j) {
		ans += a[i];
		i += b[j] - 1;
	}
	ans += accumulate(a.end() - k, a.end(), 0ll);
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}