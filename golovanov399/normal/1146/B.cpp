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

string f(const string& s) {
	string res = "";
	for (char c : s) {
		if (c != 'a') {
			res += c;
		}
	}
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string t;
	cin >> t;
	int cnt_a = 0;
	for (char c : t) {
		if (c == 'a') {
			++cnt_a;
		}
	}

	int n = (int)t.length();
	n += cnt_a;
	if (n % 2) {
		cout << ":(\n";
		return 0;
	}
	n /= 2;
	string s = t.substr(0, n);
	if (s + f(s) == t) {
		cout << s << "\n";
	} else {
		cout << ":(\n";
	}

	return 0;
}