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
	int a = nxt(), b = nxt(), ab = nxt(), ba = nxt();
	string s;
	cin >> s;
	int n = s.length();
	assert(n == a + b + 2 * ab + 2 * ba);
	if (count(all(s), 'A') != a + ab + ba) {
		cout << "No\n";
		return;
	}
	vector<pair<int, char>> blocks;
	for (int i = 0; i < n;) {
		char c = s[i];
		int j = i;
		while (j + 1 < n && s[j] != s[j + 1]) {
			++j;
		}
		blocks.push_back({j - i + 1, c});
		i = j + 1;
	}
	// ab..ab -- k abs or x abs and y bas, where x + y <= k-1
	// ab..ba -- x abs and y bas, where x + y <= k
	// ba..ab -- same
	// ba..ba -- k bas or x bas and y abs, where x + y <= k-1
	vector<int> extra_ab, extra_ba;
	int surely = 0;
	for (auto [len, start] : blocks) {
		if (len % 2 == 0) {
			if (start == 'A') {
				extra_ab.push_back(len / 2 - 1);
			} else {
				extra_ba.push_back(len / 2 - 1);
			}
		}
		surely += (len - 1) / 2;
	}
	sort(all(extra_ab));
	sort(all(extra_ba));
	// cerr << surely << "\n";
	// for (auto x : extra_ab) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	// for (auto x : extra_ba) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";

	vector<int> pab(extra_ab.size() + 1);
	vector<int> pba(extra_ba.size() + 1);
	partial_sum(all(extra_ab), pab.begin() + 1);
	partial_sum(all(extra_ba), pba.begin() + 1);
	auto check = [&](int nab, int nba) {
		int reserved = surely - pab[nab] - pba[nba];
		return max(0, ab - pab[nab] - nab) + max(0, ba - pba[nba] - nba) <= reserved;
	};

	if (surely < ab + ba) {
		int need = ab + ba - surely;
		int current_ab = 0;
		int current_ba = surely;
		for (int borrow_ab = 0; borrow_ab <= need && borrow_ab <= (int)extra_ab.size(); ++borrow_ab) {
			int need_ba = need - borrow_ab;
			if (need_ba < 0) {
				break;
			}
			if (need_ba <= (int)extra_ba.size() && check(borrow_ab, need_ba)) {
				cout << "Yes\n";
				return;
			}
			if (borrow_ab < (int)extra_ab.size()) {
				current_ba -= extra_ab[borrow_ab];
				current_ab += extra_ab[borrow_ab] + 1;
			}
		}
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}