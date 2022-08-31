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

const int N = 7077;
using Bs = bitset<N>;
vector<int> pos[N];
Bs masks[N];
Bs bitches[N];
bool bad[N];

const int M = 101111;
Bs a[M];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int i = 2; i < N; ++i) {
		for (int j = i * i; j < N; j += i * i) {
			bad[j] = true;
		}
	}

	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			masks[j].flip(i);
			if (bad[j / i]) {
				continue;
			}
			pos[i].push_back(j);
		}
	}
	for (int i = 1; i < N; ++i) {
		for (int j : pos[i]) {
			bitches[i].flip(j);
		}
	}

	[[maybe_unused]] int n = nxt(), q = nxt();
	string res;
	while (q--) {
		int t = nxt(), idx = nxt() - 1;
		if (t == 1) {
			int v = nxt();
			a[idx] = masks[v];
		} else if (t == 2) {
			int i1 = nxt() - 1, i2 = nxt() - 1;
			a[idx] = a[i1] ^ a[i2];
		} else if (t == 3) {
			int i1 = nxt() - 1, i2 = nxt() - 1;
			a[idx] = a[i1] & a[i2];
		} else {
			assert(t == 4);
			int v = nxt();
			char ans = (a[idx] & bitches[v]).count() % 2;
			res += (char)('0' + ans);
		}
	}

	cout << res << "\n";

	return 0;
}