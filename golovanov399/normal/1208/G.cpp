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
int phi[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt() + 2;

	if (k == 3) {
		cout << "3\n";
		return 0;
	}

	erat[1] = phi[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			if (1.0 * i * i < N + N) {
				for (int j = i * i; j < N; j += i) {
					if (erat[j] == 0) {
						erat[j] = i;
					}
				}
			}
		}
		int j = i, p = erat[i];
		while (erat[j] == p) {
			j /= p;
		}
		phi[i] = i / j / p * (p - 1) * phi[j];
	}

	sort(phi + 1, phi + n + 1);
	cout << accumulate(phi + 1, phi + k + 1, 0ll) << "\n";

	return 0;
}