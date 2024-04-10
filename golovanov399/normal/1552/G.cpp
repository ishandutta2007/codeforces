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
	vector<vector<int>> ops(k);
	for (int i = 0; i < k; ++i) {
		ops[i].resize(nxt());
		for (auto& x : ops[i]) {
			x = nxt() - 1;
		}
		sort(all(ops[i]));
	}
	vector<vector<int>> already(k);
	vector<int> cnt(k, 0);
	vector<char> used(n);
	for (int i = 0; i < k; ++i) {
		for (int j : ops[i]) {
			if (!used[j]) {
				used[j] = 1;
				cnt[i] += 1;
			} else {
				already[i].push_back(j);
			}
		}
	}

	if (accumulate(all(cnt), 0) < n && n > 1) {
		cout << "REJECTED\n";
		return;
	}

	vector<vector<int>> buf(k);
	for (int i = 0; i < k; ++i) {
		buf[i].resize(already[i].size());
	}

	// vector<int> curcnt(k);

	vector<char> vec(n);
	function<void(int)> rec = [&](int i) {
		if (i == k) {
			if (!is_sorted(all(vec))) {
				cout << "REJECTED\n";
				exit(0);
			}
			return;
		}
		for (int j = 0; j < (int)already[i].size(); ++j) {
			buf[i][j] = vec[already[i][j]];
		}
		int cur = 0;
		for (int j : already[i]) {
			cur += vec[j];
		}
		for (int j = 0; j < (int)ops[i].size(); ++j) {
			vec[ops[i][j]] = j >= (int)ops[i].size() - cur;
		}
		for (int cn = 0; cn <= cnt[i]; ++cn) {
			// for (int j = 0; j < (int)ops[i].size(); ++j) {
			// 	vec[ops[i][j]] = j >= (int)ops[i].size() - cur - cn;
			// }
			if (cn) {
				vec[ops[i][(int)ops[i].size() - cur - cn]] = 1;
			}
			rec(i + 1);
		}
		for (int j = 0; j < (int)already[i].size(); ++j) {
			vec[already[i][j]] = buf[i][j];
		}
	};
	rec(0);
	cout << "ACCEPTED\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}