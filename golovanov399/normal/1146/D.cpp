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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), a = nxt(), b = nxt();
	n += 1;

	vector<char> can(a + b, 0);
	can[0] = 1;
	vector<int> ans(a + b, 0);
	ans[0] = 1;
	vector<vector<int>> to(a + b);
	int cur = 1;

	for (int i = 1; i < a + b; ++i) {
		if (i >= a) {
			to[i - a].push_back(i);
		}
		if (i >= b) {
			to[i].push_back(i - b);
		}
		if (i >= a && can[i - a]) {
			vector<int> st = {i};
			while (!st.empty()) {
				int v = st.back();
				st.pop_back();
				if (can[v]) {
					continue;
				}
				can[v] = 1;
				++cur;
				for (int x : to[v]) {
					st.push_back(x);
				}
			}
		}
		ans[i] = cur;
	}

	long long sum = 0;
	for (int i = 0; i < n && i < a + b; ++i) {
		sum += ans[i];
	}
	int g = gcd(a, b);
	for (int i = 0; i < g; ++i) {
		int l = a + b;
		int r = n - 1;
		if (l % g <= i) {
			l = l - l % g + i;
		} else {
			l = l - l % g + g + i;
		}
		if (r % g >= i) {
			r = r - r % g + i;
		} else {
			r = r - r % g - g + i;
		}
		if (l > r) {
			continue;
		}
		l /= g;
		r /= g;
		l += 1;
		r += 1;
		sum += 1ll * (l + r) * (r - l + 1) / 2;
	}

	cout << sum << "\n";

	return 0;
}