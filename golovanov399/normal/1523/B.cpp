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

using State = array<int, 4>;

ostream& operator <<(ostream& ostr, const State& st) {
	ostr << "{";
	for (int i =0 ; i < 4; ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << st[i];
	}
	return ostr << "}";
}

void solve() {
	int n = nxt();
	[[maybe_unused]] vector<int> a(n);
	generate(all(a), nxt);
	cout << 3 * n << "\n";
	for (int i = 1; i < n; i += 2) {
		cout << "1 " << i << " " << i + 1 << "\n";
		cout << "1 " << i << " " << i + 1 << "\n";
		cout << "2 " << i << " " << i + 1 << "\n";
		cout << "1 " << i << " " << i + 1 << "\n";
		cout << "1 " << i << " " << i + 1 << "\n";
		cout << "2 " << i << " " << i + 1 << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}