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

const int N = 21111111;
int erat[N];
int cnt[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	erat[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i]) continue;
		erat[i] = i;
		if (1.0 * i * i < N + N) {
			for (int j = i * i; j < N; j += i) {
				if (erat[j] == 0) {
					erat[j] = i;
				}
			}
		}
	}

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int g = 0;
	for (int x : a) {
		g = gcd(g, x);
	}
	for (int& x : a) {
		x /= g;
	}

	for (int i = 0; i < n; ++i) {
		int x = a[i];
		while (x > 1) {
			int p = erat[x];
			while (erat[x] == p) {
				x /= p;
			}
			cnt[p] += 1;
		}
	}

	int c = *max_element(cnt, cnt + N);
	int ans = c ? n - c : -1;

	cout << ans << "\n";

	return 0;
}