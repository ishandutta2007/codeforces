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

const int N = 1111111;
int erat[N];
vector<int> primes;

void solve() {
	int n = nxt();
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		int odd = 1;
		while (x > 1) {
			int p = erat[x];
			x /= p;
			if (odd % p) {
				odd *= p;
			} else {
				odd /= p;
			}
		}
		M[odd] += 1;
	}
	int q = nxt();
	int a0 = 0;
	for (auto p : M) {
		a0 = max(a0, p.second);
	}
	{
		map<int, int> tmp;
		for (auto p : M) {
			if (p.second % 2) {
				tmp[p.first] = p.second;
			} else {
				tmp[1] += p.second;
			}
		}
		M.swap(tmp);
	}
	int a1 = 0;
	for (auto p : M) {
		a1 = max(a1, p.second);
	}
	while (q--) {
		long long w;
		scanf("%lld", &w);
		cout << (w ? a1 : a0) << "\n";
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

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}