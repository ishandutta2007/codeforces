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

const int MAGIC = 178;
const int MM = 200022 * (MAGIC + 3);
int M[MM];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;
	int n = s.length();

	long long ans = 0;
	for (int k = 1; k <= MAGIC; ++k) {
		int cur = n;
		M[cur] = 1;
		for (int i = 0; i < n; ++i) {
			cur -= s[i] == '0' ? 1 : 1 - k;
			ans += (M[cur]++);
		}
		cur = n;
		for (int i = 0; i < n; ++i) {
			cur -= s[i] == '0' ? 1 : 1 - k;
			--M[cur];
		}
	}

	vector<int> positions;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			positions.push_back(i);
		}
	}

	int k = MAGIC;
	for (int c = 1; c <= (int)positions.size() && c * (k + 1) <= n; ++c) {
		for (int j = 0; j + c <= (int)positions.size(); ++j) {
			int l = positions[j];
			int r = positions[j + c - 1];
			int L = j ? positions[j - 1] : -1;
			int R = j + c < (int)positions.size() ? positions[j + c] : n;

			int d = r - l + 1;
			int d_l = l - L;
			int d_r = R - r;
			if (d_l > d_r) {
				swap(d_l, d_r);
			}

			// d + {0, 1, ..., d_l - 1} + {0, 1, ..., d_r - 1}
			// [d, d + d_l - 1] -> (x - d + 1)
			// [d + d_r, d + d_l + d_r - 2] -> (d + d_l + d_r - 1 - x)
			// [d + d_l, d + d_r - 1] -> d_l

			{
				int xl = d - d % c;
				if (xl < d) {
					xl += c;
				}
				if (xl < c * (k + 1)) {
					xl = c * (k + 1);
				}
				int xr = d + d_l - 1;
				xr -= xr % c;

				if (xl <= xr) {
					ans -= 1ll * (d - 1) * (xr - xl + c) / c;
					ans += 1ll * (xr - xl + c) / c * (xl + xr) / 2;
				}
			}

			{
				int xl = (d + d_r) - (d + d_r) % c;
				if (xl < (d + d_r)) {
					xl += c;
				}
				if (xl < c * (k + 1)) {
					xl = c * (k + 1);
				}
				int xr = d + d_l + d_r - 2;
				xr -= xr % c;

				if (xl <= xr) {
					ans += 1ll * (d + d_l + d_r - 1) * (xr - xl + c) / c;
					ans -= 1ll * (xr - xl + c) / c * (xl + xr) / 2;
				}
			}

			{
				int xl = (d + d_l) - (d + d_l) % c;
				if (xl < (d + d_l)) {
					xl += c;
				}
				if (xl < c * (k + 1)) {
					xl = c * (k + 1);
				}
				int xr = d + d_r - 1;
				xr -= xr % c;

				if (xl <= xr) {
					ans += 1ll * (xr - xl + c) / c * d_l;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}