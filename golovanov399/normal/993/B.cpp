#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int getCommon(int x, int y) {
	int xx[2] = {x / 10, x % 10};
	int yy[2] = {y / 10, y % 10};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (xx[i] == yy[j]) {
				return xx[i];
			}
		}
	}
	return -1;
}

bool areOk(int x, int y) {
	int xx[2] = {x / 10, x % 10};
	int yy[2] = {y / 10, y % 10};
	int cnt = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			cnt += (xx[i] == yy[j]);
		}
	}
	return cnt == 1;
}

int main() {
	int n = nxt(), m = nxt();
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() * 10 + nxt();
	}
	for (int i = 0; i < m; ++i) {
		b[i] = nxt() * 10 + nxt();
	}

	bool can_guess = true;
	vector<int> potential;
	for (int x : a) {
		for (int y : b) {
			if (!areOk(x, y)) {
				continue;
			}
			potential.push_back(getCommon(x, y));

			vector<int> f_p, s_p;
			for (int xx : a) {
				if (areOk(xx, y)) {
					s_p.push_back(getCommon(xx, y));
				}
			}
			for (int yy : b) {
				if (areOk(x, yy)) {
					f_p.push_back(getCommon(x, yy));
				}
			}
			make_unique(f_p);
			make_unique(s_p);
			if ((int)f_p.size() != 1 || (int)s_p.size() != 1) {
				can_guess = false;
			}
		}
	}
	make_unique(potential);
	if ((int)potential.size() == 1) {
		cout << potential[0] << "\n";
	} else if (can_guess) {
		cout << "0\n";
	} else {
		cout << "-1\n";
	}

	return 0;
}