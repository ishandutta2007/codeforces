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
	scanf("%d", &x);
	return x;
}

const int N = 222222;
int erat[N];
vector<int> primes;

int m2[N][2];
int cn[N];

void upd(int p, int d) {
	if (cn[p] < 2) {
		m2[p][cn[p]++] = d;
		if (cn[p] == 2 && m2[p][0] > m2[p][1]) {
			swap(m2[p][0], m2[p][1]);
		}
	} else {
		++cn[p];
		if (m2[p][0] > d) {
			m2[p][1] = m2[p][0];
			m2[p][0] = d;
		} else if (m2[p][1] > d) {
			m2[p][1] = d;
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || i * p >= N) {
				break;
			}
			erat[i * p] = p;
		}
	}

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		while (x > 1) {
			int p = erat[x];
			int cnt = 0;
			while (erat[x] == p) {
				x /= p;
				++cnt;
			}
			upd(p, cnt);
		}
	}

	long long ans = 1;
	for (int p : primes) {
		int deg = 0;
		if (cn[p] == n - 1) {
			deg = m2[p][0];
		} else if (cn[p] == n) {
			deg = m2[p][1];
		}
		for (int i = 0; i < deg; ++i) {
			ans *= p;
		}
	}
	cout << ans << "\n";

	return 0;
}