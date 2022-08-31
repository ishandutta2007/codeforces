#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// #define TEST

#ifdef TEST
int rem = 0;
int g_x = 0;
int att = 100;
#endif

char ask(int x, int y) {
#ifdef TEST
	if (rem == 0) {
		assert(false);
	}
	// cerr << x % g_x << " " << y % g_x << "\n";
	return (x % g_x >= y % g_x) ? 'x' : 'y';
#else
	cout << "? " << x << " " << y << endl;
	string s;
	cin >> s;
	assert(s == "x" || s == "y");
	return s[0];
#endif
}

bool check_if_on_lr(int l, int r) {
	// cerr << "[" << l << ", " << r << "]\n";
	int x = r, y = l - 1;
	return ask(x, y) == 'y';
}

void guess(int x) {
	cout << "! " << x << endl;
#ifdef TEST
	if (x != g_x) {
		cout << x << " " << g_x << "\n";
		exit(0);
	}
#endif
}

int main() {
	string s;
	while (true) {
#ifdef TEST
		s = (att-- > 0) ? "start" : "end";
		g_x = rng() % 1000000000 + 1;
		rem = 60;
#else
		cin >> s;
#endif
		if (s == "start") {
			if (ask(0, 1) == 'x') {
				guess(1);
				continue;
			}
			int l = 1, r = 2;
			while (ask(r, l) == 'x') {
				l *= 2;
				r *= 2;
			}
			l += 1;
			while (r > l) {
				int m = (l + r) / 2;
				if (check_if_on_lr(m + 1, r)) {
					l = m + 1;
				} else {
					r = m;
				}
			}
			guess(l);
		} else if (s == "mistake") {
			while (true) {}
		} else if (s == "end") {
			break;
		} else {
			assert(false);
		}
	}

	return 0;
}