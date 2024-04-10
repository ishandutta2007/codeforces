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

vector<int> zFunction(const string& s) {
	int n = s.length();

	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = max(min(z[i - l], r - i), 0);

		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			++z[i];
		}

		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	
	if (n) {
		z[0] = n;
	}

	return z;
}

string g(const string& s) {
	auto t = s;
	reverse(all(t));
	auto z = zFunction(s + "#" + t);
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (z[n + 1 + i] + n + i + 1 == 2 * n + 1) {
			return s.substr(0, n - i);
		}
	}
	assert(false);
}

string f(string s) {
	if ((int)s.size() <= 1) {
		return s;
	}
	auto res_1 = g(s);
	reverse(all(s));
	auto res_2 = g(s);
	if (res_1.size() < res_2.size()) {
		return res_2;
	} else {
		return res_1;
	}
}

void solve() {
	string s;
	cin >> s;

	int n = s.size();
	int l = 0, r = n - 1;
	while (l < r && s[l] == s[r]) {
		++l, --r;
	}
	string t = s.substr(l, r - l + 1);
	cout << s.substr(0, l) << f(t) << s.substr(r + 1) << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}