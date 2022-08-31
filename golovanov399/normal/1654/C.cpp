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
	vector<long long> a(n);
	generate(all(a), nxt);
	long long s = accumulate(all(a), 0ll);
	multiset<long long> S(all(a));
	vector<long long> cur = {s};
	int rem = n - 1;
	while (!cur.empty()) {
		auto x = cur.back();
		cur.pop_back();
		if (auto it = S.find(x); it != S.end()) {
			S.erase(it);
		} else if (rem == 0 || x == 1) {
			cout << "No\n";
			return;
		} else {
			cur.push_back(x / 2);
			cur.push_back((x + 1) / 2);
			--rem;
		}
	}
	cout << "Yes\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}