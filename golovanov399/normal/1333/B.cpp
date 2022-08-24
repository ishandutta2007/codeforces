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
	int n = nxt();
	vector<int> a(n), b(n);
	generate(all(a), nxt);
	generate(all(b), nxt);
	bool can_inc = false, can_dec = false;
	for (int i = 0; i < n; ++i) {
		if (b[i] > a[i] && !can_inc) {
			cout << "No\n";
			return;
		}
		if (b[i] < a[i] && !can_dec) {
			cout << "No\n";
			return;
		}
		if (a[i] == 1) {
			can_inc = true;
		}
		if (a[i] == -1) {
			can_dec = true;
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