#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	string s;
	cin >> s;

	vector<char> ok_beg(10), ok_end(10);
	vector<int> last_occ(10, -1), first_occ(10, -1);
	for (int i = 0; i < n; ++i) {
		int d = s[i] - '0';
		last_occ[d] = i;
		if (first_occ[d] == -1) {
			first_occ[d] = i;
		}
	}

	ok_beg[0] = 1;
	{
		int lo = last_occ[0];
		for (int i = 1; i < 10; ++i) {
			if (ok_beg[i - 1] && (first_occ[i] == -1 || first_occ[i] > lo)) {
				ok_beg[i] = 1;
				lo = max(lo, last_occ[i]);
			} else {
				break;
			}
		}
	}
	ok_end[9] = 1;
	{
		int lo = first_occ[9];
		for (int i = 8; i >= 0; --i) {
			if (ok_end[i + 1] && (lo == -1 || last_occ[i] < lo)) {
				ok_end[i] = 1;
				if (first_occ[i] > -1) {
					lo = first_occ[i];
				}
			} else {
				break;
			}
		}
	}

	if (ok_beg[9]) {
		cout << string(n, '1') << "\n";
		return;
	}
	for (int i = 1; i < 10; ++i) {
		if (ok_beg[i - 1] && ok_end[i]) {
			string ans(n, '1');
			for (int j = 0; j < n; ++j) {
				if (s[j] >= '0' + i) {
					ans[j] = '2';
				}
			}
			cout << ans << "\n";
			return;
		}
	}
	for (int d = 0; d < 10; ++d) {
		if (d > 0 && !ok_beg[d - 1]) {
			continue;
		}
		if (d < 9 && !ok_end[d + 1]) {
			continue;
		}
		
		string ans(n, '0');
		int last_one = -1, first_two = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] < '0' + d) {
				ans[i] = '1';
				last_one = i;
			} else if (s[i] > '0' + d) {
				ans[i] = '2';
				if (first_two == -1) {
					first_two = i;
				}
			}
		}
		if (first_two > -1) {
			for (int i = 0; i < first_two; ++i) {
				if (s[i] == '0' + d) {
					ans[i] = '2';
				}
			}
		}
		if (last_one > -1) {
			for (int i = last_one + 1; i < n; ++i) {
				if (s[i] == '0' + d) {
					ans[i] = '1';
				}
			}
		}
		if (ans.find('0') == string::npos) {
			cout << ans << "\n";
			return;
		}
	}
	cout << "-\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}