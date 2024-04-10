#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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
	cin >> x;
	return x;
}

const double PI = acosl(-1);

int main() {
	cin.sync_with_stdio(0);
	int n = nxt();
	string s;
	cin >> s;
	vector<int> a(n);
	for (itn i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
	}

	vector<int> valid;
	for (int i = 1; i <= n; ++i) {
		if (__gcd(i, n) == 1) {
			valid.push_back(i);
		}
	}

	int tries = min(500, (int)valid.size());
	for (int i = 0; i < (int)valid.size(); ++i) {
		swap(valid[i], valid[rand() % ((int)valid.size() - i) + i]);
	}
	valid.resize(tries);

	vector<long double> re(n), im(n);
	for (int i = 0; i < n; ++i) {
		double phi = 2 * PI * i / n;
		re[i] = cosl(phi);
		im[i] = sinl(phi);
	}

	for (int x : valid) {
		double curx = 0, cury = 0;
		for (long long i = 0; i < n; ++i) {
			curx += re[i * x % n] * a[i];
			cury += im[i * x % n] * a[i];
		}
		if (fabsl(curx) > 1e-6 || fabsl(cury) > 1e-6) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");

	return 0;
}