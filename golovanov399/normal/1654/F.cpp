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
	int n;
	cin >> n;
	const int nn = 1 << n;
	string s;
	cin >> s;

	vector<int> cur(nn);
	for (int i = 0; i < nn; ++i) {
		cur[i] = s[i] - 'a';
	}
	vector<pair<int, int>> tmp(nn);
	for (int len = 1; len < nn; len *= 2) {
		for (int start = 0; start < nn; start += 2 * len) {
			for (int i = 0; i < len; ++i) {
				tmp[start + i] = {cur[start + i], cur[start + len + i]};
				tmp[start + len + i] = {cur[start + len + i], cur[start + i]};
			}
		}
		auto tt = tmp;
		make_unique(tt);
		for (int i = 0; i < nn; ++i) {
			cur[i] = lower_bound(all(tt), tmp[i]) - tt.begin();
		}
	}
	int x = min_element(all(cur)) - cur.begin();
	string t;
	for (int i = 0; i < nn; ++i) {
		t += s[i ^ x];
	}
	cout << t << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}