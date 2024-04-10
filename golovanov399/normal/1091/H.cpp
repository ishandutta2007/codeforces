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

const int N = 222222;
using Bs = bitset<N>;
const int MAGIC = 60;

Bs bs[MAGIC];

int erat[N];
int np[N];

int gr[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		}
		np[i] = np[i / erat[i]] + 1;
	}

	int n = nxt(), f = nxt();
	Bs b = {};
	for (int i = 1; i < N; ++i) {
		if (np[i] == 1 || np[i] == 2) {
			b[i] = 1;
		}
	}
	b[f] = 0;

	gr[0] = 0;
	bs[0] = b;

	for (int i = 1; i < N; ++i) {
		while (bs[gr[i]][i]) {
			++gr[i];
		}
		bs[gr[i]] |= b << i;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x = nxt(), y = nxt(), z = nxt();
		ans ^= gr[y - x - 1];
		ans ^= gr[z - y - 1];
	}

	cout << (ans ? "Alice\nBob" : "Bob\nAlice") << "\n";

	return 0;
}