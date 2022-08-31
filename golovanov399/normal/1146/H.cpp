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

struct Point {
	long long x, y;

	pair<long long, long long> asPair() const {
		return {x, y};
	}

	bool operator <(const Point& p) const {
		return asPair() < p.asPair();
	}

	long long vprod(const Point& p) const {
		return x * p.y - y * p.x;
	}

	Point operator -(const Point& p) const {
		return {x - p.x, y - p.y};
	}
};

const int N = 303;

Point pts[N];
int cnt_under[N][N];

inline int getCntInside(int x, int y, int z) {
	return abs(cnt_under[x][z] - cnt_under[x][y] - cnt_under[y][z] - ((pts[y] - pts[x]).vprod(pts[z] - pts[x]) > 0));
}

long long C(int n, int k) {
	long long res = 1;
	for (int i = 0; i < k; ++i) {
		res = res * (n - i) / (i + 1);
	}
	return res;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		pts[i].x = nxt();
		pts[i].y = nxt();
	}
	sort(pts, pts + n);

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if ((pts[j] - pts[i]).vprod(pts[k] - pts[i]) > 0) {
					++cnt_under[i][k];
				}
			}
		}
	}

	long long ans = C(n, 5) * 2;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				// ans -= C(getCntInside(i, j, k), 2);
				int cn = getCntInside(i, j, k);
				// cerr << i << " " << j << " " << k << " " << cn << " " << n - 3 - cn << "\n";
				ans -= cn * (n - 3 - cn);
			}
		}
	}

	cout << ans / 2 << "\n";

	return 0;
}