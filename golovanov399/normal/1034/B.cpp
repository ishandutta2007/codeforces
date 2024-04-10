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

int stupid(int a, int b) {
	int n = a * b;
	int N = 1 << n;
	vector<char> can(N);
	vector<int> cand;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			for (int x = -3; x <= 3; ++x) {
				for (int y = -3; y <= 3; ++y) {
					if (abs(x) + abs(y) != 3) continue;
					int nx = i + x, ny = j + y;
					if (nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
					cand.push_back((1 << (nx * b + ny)) | (1 << (i * b + j)));
				}
			}
		}
	}
	can[0] = 1;
	for (int i = 0; i < N; ++i) {
		if (!can[i]) continue;
		for (int c : cand) {
			if (i & c) continue;
			can[i | c] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (can[i]) {
			ans = max(ans, __builtin_popcount(i));
		}
	}
	return ans;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	/*for (int i = 1; i < 25; ++i) {
		cerr << i << ": ";
		for (int j = 1; i * j < 25; ++j) {
			cerr << stupid(i, j) << "/" << i * j << " ";
		}
		cerr << "\n";
	}*/

	int n = nxt(), m = nxt();
	if (1ll * n * m < 25) {
		cout << stupid(n, m) << "\n";
		return 0;
	}

	if (n > m) {
		swap(n, m);
	}
	if (n == 1) {
		cout << m - m % 6 + vector<int>{0, 0, 0, 0, 2, 4}[m % 6] << "\n";
	} else {
		cout << 1ll * n * m - n % 2 * m % 2 << "\n";
	}

	return 0;
}