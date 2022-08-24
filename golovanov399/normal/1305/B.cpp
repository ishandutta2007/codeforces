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
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;
	vector<int> open, close;
	int l = 0, r = (int)s.length() - 1;
	while (true) {
		while (l < (int)s.size() && s[l] == ')') {
			++l;
		}
		while (r >= 0 && s[r] == '(') {
			--r;
		}
		if (l <= r) {
			open.push_back(l++);
			close.push_back(r--);
		} else {
			break;
		}
	}
	if (open.empty()) {
		cout << "0\n";
		return 0;
	}
	cout << "1\n" << open.size() * 2 << "\n";
	reverse(all(close));
	for (int x : open) {
		cout << x + 1 << " ";
	}
	for (int x : close) {
		cout << x + 1 << " ";
	}
	cout << "\n";

	return 0;
}