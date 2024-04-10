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
	// scanf("%d", &x);
	cin >> x;
	return x;
}

bool ask(int x) {
	cout << "? " << x + 1 << endl;
	char c;
	cin >> c;
	return c == 'Y';
}

void forget() {
	cout << "R" << endl;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	vector<char> is_unique(n, 1);
	for (int i = 0; i < n; ++i) {
		is_unique[i] = !ask(i);
		if ((i + 1) % k == 0) {
			forget();
		}
	}

	for (int d = 1; d < n / k; ++d) {
		for (int i = 0; i < d; ++i) {
			if (i + d >= n / k) {
				continue;
			}
			vector<int> not_unique;
			for (int j = i; j < n / k; j += d) {
				for (int c = 0; c < k; ++c) {
					if (is_unique[j * k + c]) {
						bool q = ask(j * k + c);
						is_unique[j * k + c] &= !q;
						if (q) {
							not_unique.push_back(j * k + c);
						}
					}
				}
			}
			forget();
			for (int j = i; j < n / k; j += d) {
				for (int c = k - 1; c >= 0; --c) {
					if (is_unique[j * k + c]) {
						bool q = ask(j * k + c);
						is_unique[j * k + c] &= !q;
						if (q) {
							not_unique.push_back(j * k + c);
						}
					}
				}
			}
			forget();
			for (int x : not_unique) {
				is_unique[x] = false;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += is_unique[i];
	}
	cout << "! " << ans << endl;

	return 0;
}