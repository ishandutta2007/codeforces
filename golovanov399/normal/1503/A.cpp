#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

bool is_good(const string& s) {
	int bal = 0;
	for (char c : s) {
		bal += (c == '(') ? 1 : -1;
		if (bal < 0) {
			return false;
		}
	}
	return bal == 0;
}

void solve() {
	[[maybe_unused]] int n = nxt();
	string s;
	cin >> s;
	int coinc = count(all(s), '1'), diff = count(all(s), '0');
	if (coinc % 2 || diff % 2) {
		cout << "NO\n";
		return;
	}
	string fst, snd;
	int c_so_far = 0, d_so_far = 0;
	for (char c : s) {
		if (c == '1') {
			if (c_so_far * 2 < coinc) {
				fst += '(';
				snd += '(';
			} else {
				fst += ')';
				snd += ')';
			}
			c_so_far += 1;
		} else {
			if (d_so_far % 2 == 0) {
				fst += '(';
				snd += ')';
			} else {
				fst += ')';
				snd += '(';
			}
			d_so_far += 1;
		}
	}
	if (is_good(fst) && is_good(snd)) {
		cout << "YES\n" << fst << "\n" << snd << "\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}