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
	n -= 2;
	a.erase(a.begin());
	a.pop_back();
	long long total = 0;
	int odd = 0;
	bool can = false;
	for (int x : a) {
		total += x;
		odd += x % 2;
		can |= x > 1;
	}

	if (odd != n) {
		cout << (total + odd) / 2 << "\n";
	} else if (n == 1 || !can) {
		cout << "-1\n";
	} else {
		cout << 1 + (total - 1 + odd - 1) / 2 << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}