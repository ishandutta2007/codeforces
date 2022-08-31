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
	int n = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	sort(all(a));
	int mex = 0;
	int i = 0;
	int old = k;
	while (i < n) {
		if (a[i] == mex) {
			while (i < n && a[i] == mex) {
				++i;
			}
		} else {
			if (k == 0) {
				break;
			} else {
				--k;
			}
		}
		++mex;
	}
	if (i == n) {
		cout << "0\n";
		return;
	}
	map<int, int> M;
	for (; i < n; ++i) {
		M[a[i]] += 1;
	}
	vector<int> cnts;
	for (auto p : M) {
		cnts.push_back(p.second);
	}
	sort(all(cnts));
	k = old;
	int ans = cnts.size();
	for (int x : cnts) {
		if (x <= k) {
			k -= x;
			--ans;
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