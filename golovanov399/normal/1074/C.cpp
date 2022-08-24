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

	int n = nxt();
	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		x[i] = nxt(), y[i] = nxt();
	}

	int bb = 2 * (*max_element(all(x)) + *max_element(all(y)) - *min_element(all(x)) - *min_element(all(y)));

	vector<pair<int, int>> border_x, border_y;
	int mx = *min_element(all(x));
	int Mx = *max_element(all(x));
	int my = *min_element(all(y));
	int My = *max_element(all(y));

	for (int i = 0; i < n; ++i) {
		if (x[i] == mx || x[i] == Mx) {
			border_x.push_back({x[i], y[i]});
		}
		if (y[i] == my || y[i] == My) {
			border_y.push_back({x[i], y[i]});
		}
	}
	int ans_3 = 0;
	for (auto p : border_x) {
		for (auto q : border_y) {
			for (int i = 0; i < n; ++i) {
				ans_3 = max(ans_3, max({p.first, q.first, x[i]}) - min({p.first, q.first, x[i]}) + max({p.second, q.second, y[i]}) - min({p.second, q.second, y[i]}));
			}
		}
	}

	printf("%d", 2 * ans_3);
	for (int i = 4; i <= n; ++i) {
		printf(" %d", bb);
	}
	printf("\n");

	return 0;
}