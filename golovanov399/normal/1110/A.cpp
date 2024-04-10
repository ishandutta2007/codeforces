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

	int b = nxt(), k = nxt();
	vector<itn> a(k);
	for (int& x : a) {
		x = nxt();
	}

	if (b % 2) {
		cout << (accumulate(all(a), 0ll) % 2 ? "odd" : "even") << "\n";
	} else {
		cout << (a.back() % 2 ? "odd" : "even") << "\n";
	}

	return 0;
}