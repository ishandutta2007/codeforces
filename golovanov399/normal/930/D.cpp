#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

using Point = pair<int, int>;
#define x first
#define y second

int mydiv(int x, int y) {
	if (x % y == 0) {
		return x / y;
	} else {
		return x / y - (x < 0);
	}
}

Point convert(int x, int y) {
	x += y;
	y = x - 2 * y;
	return {mydiv(x, 2), mydiv(y, 2)};
}

const int N = 111111;

int up_y[N + N], down_y[N + N];
int left_y[N + N], right_y[N + N];

int main() {
	int n = nxt();
	vector<Point> ppts[2];
	for (int i = 0; i < n; ++i) {
		int x = nxt(), y = nxt();
		ppts[(abs(x) + abs(y)) % 2].push_back(convert(x, y));
	}

	for (int i = 0; i < 2; ++i) {
		sort(all(ppts[i]));
	}

	long long ans = 0;

	for (auto pts : ppts) {
		for (int i = 0; i < N + N; ++i) {
			left_y[i] = right_y[i] = -N;
		}
		for (auto pt : pts) {
			left_y[pt.x + N] = max(left_y[pt.x + N], pt.y);
			right_y[pt.x + N] = max(right_y[pt.x + N], pt.y);
		}

		for (int i = 1; i < N + N; ++i) {
			left_y[i] = max(left_y[i], left_y[i - 1]);
		}
		for (int i = N + N - 2; i >= 0; --i) {
			right_y[i] = max(right_y[i], right_y[i + 1]);
		}

		for (int i = 0; i < N + N; ++i) {
			up_y[i] = min(left_y[i], right_y[i]);
		}


		for (int i = 0; i < N + N; ++i) {
			left_y[i] = right_y[i] = N;
		}
		for (auto pt : pts) {
			left_y[pt.x + N] = min(left_y[pt.x + N], pt.y);
			right_y[pt.x + N] = min(right_y[pt.x + N], pt.y);
		}

		for (int i = 1; i < N + N; ++i) {
			left_y[i] = min(left_y[i], left_y[i - 1]);
		}
		for (int i = N + N - 2; i >= 0; --i) {
			right_y[i] = min(right_y[i], right_y[i + 1]);
		}

		for (int i = 0; i < N + N; ++i) {
			down_y[i] = max(left_y[i], right_y[i]);
		}

		for (int i = 1; i < N + N; ++i) {
			int l = max(down_y[i - 1], down_y[i]);
			int r = min(up_y[i - 1], up_y[i]);

			if (l >= r) {
				continue;
			}
			ans += r - l;
		}
	}

	cout << ans << "\n";

	return 0;
}