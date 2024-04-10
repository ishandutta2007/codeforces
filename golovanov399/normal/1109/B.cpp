#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool isPal(const string& s) {
	for (int i = 0; i < (int)s.length() / 2; ++i) {
		if (s[i] != s[(int)s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;

	string t = s.substr(0, (int)s.length() / 2);
	if (min_element(all(t)) == max_element(all(t))) {
		cout << "Impossible\n";
		return 0;
	}

	int n = s.length();
	for (int i = 1; i < n; ++i) {
		string t = s.substr(i) + s.substr(0, i);
		if (t != s && isPal(t)) {
			cout << "1\n";
			return 0;
		}
	}

	cout << "2\n";

	return 0;
}