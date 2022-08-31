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

	int n = nxt();
	string s;
	cin >> s;
	int eights = 0;
	for (char c : s) {
		if (c == '8') {
			++eights;
		}
	}
	for (int i = (int)s.length(); i >= 0; --i) {
		if (eights >= i && 11 * i <= n) {
			cout << i << "\n";
			return 0;
		}
	}

	return 0;
}