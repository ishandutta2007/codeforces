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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;
	for (int i = 0; i < 5; ++i) {
		string t;
		cin >> t;
		if (s[0] == t[0] || s[1] == t[1]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}