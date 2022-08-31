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
	int hx = 1, hy = 1, vx = 3, vy = 1;
	for (char c : s) {
		if (c == '0') {
			cout << vx << " " << vy << "\n";
			vy += 1;
			if (vy == 5) {
				vy = 1;
			}
		} else {
			cout << hx << " " << hy << "\n";
			hy += 2;
			if (hy == 5) {
				hy = 1;
			}
		}
	}

	return 0;
}