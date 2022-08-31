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
	long long cur = 0;
	while (!a.empty() && a.back() == 0) {
		a.pop_back();
	}
	int cnt = 0;
	for (int x : a) {
		cur += x;
		if (cur < 0) {
			cout << "No\n";
			return;
		}
		cnt += cur == 0;
	}
	cout << ((cur || cnt > 1) ? "No" : "Yes") << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}