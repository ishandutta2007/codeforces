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
	cin >> x;
	return x;
}

bool ask(long long l, long long r) {
	cout << l << " " << r << endl;
	string s;
	cin >> s;
	assert(s != "Bad");
	if (s == "Yes") {
		if (l == r) {
			exit(0);
		} else {
			return true;
		}
	} else {
		return false;
	}
}

int main() {
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long n, k;
	cin >> n >> k;
	long long l = 1, r = n;
	while (true) {
		long long m = (l + r) / 2;
		long long len = r - l + 1;
		if (ask(l, m)) {
			r = m;
		} else {
			l = m + 1;
		}
		l = max<long long>(l - k, 1);
		r = min<long long>(r + k, n);

		if (r - l + 1 >= len) {
			long long pos = rand() % (r - l + 1) + l;
			if (!ask(pos, pos)) {
				l = max<long long>(l - k, 1);
				r = min<long long>(r + k, n);
			}
		}
	}

	return 0;
}