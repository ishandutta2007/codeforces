#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

ostream& operator <<(ostream& ostr, const vector<int>& a) {
	ostr << "{";
	for (int i = 0; i < (int)a.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << a[i];
	}
	return ostr << "}";
}

void solve() {
	int n = nxt(), m = nxt();
	vector<int> a(n), b(m);
	generate(all(a), nxt);
	generate(all(b), nxt);
	vector<int> sufmin = b;
	for (int i = m - 2; i >= 0; --i) {
		sufmin[i] = min(sufmin[i], sufmin[i + 1]);
	}
	vector<int> min_ge(m + 1, n);
	int j = m - 1;
	for (int i = n - 1; i >= 0; --i) {
		while (j >= 0 && a[i] < b[j]) {
			--j;
			if (j >= 0) {
				min_ge[j] = min_ge[j + 1];
			}
		}
		if (j < 0) {
			cout << "0\n";
			return;
		}
		min_ge[j] = i;
	}
	while (j) {
		j -= 1;
		min_ge[j] = min_ge[j + 1];
	}
	for (int j = 0; j < m; ++j) {
		int x = INT_MAX;
		for (int i = min_ge[j]; i < min_ge[j + 1]; ++i) {
			x = min(x, a[i]);
		}
		if (x != b[j]) {
			cout << "0\n";
			return;
		}
	}
	vector<int> last_occ(m, -1);
	for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
		if (a[i] == b[j]) {
			last_occ[j] = i;
			--j;
		}
	}
	if (last_occ[0] == -1) {
		cout << "0\n";
		return;
	}
	const int mod = 998244353;
	long long ans = 1;
	for (int i = 1; i < m; ++i) {
		ans = ans * (last_occ[i] - min_ge[i] + 1) % mod;
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}