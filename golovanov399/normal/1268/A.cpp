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

	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	string t = s;
	for (int i = k; i < n; ++i) {
		t[i] = t[i - k];
	}
	if (t >= s) {
		cout << n << "\n" << t << "\n";
		return 0;
	}
	if (s.substr(0, k) == string(k, '9')) {
		t = string(n + 1, '0');
		for (int i = 0; i <= n; i += k) {
			t[i] = '1';
		}
		cout << n + 1 << "\n" << t << "\n";
	} else {
		int i = k - 1;
		s[i] += 1;
		while (s[i] > '9') {
			s[i] = '0';
			--i;
			s[i] += 1;
		}
		for (int i = k; i < n; ++i) {
			s[i] = s[i - k];
		}
		cout << n << "\n" << s << "\n";
	}

	return 0;
}