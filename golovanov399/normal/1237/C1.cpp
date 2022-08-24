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

struct Point {
	int x, y, z;

	void scan() {
		x = nxt();
		y = nxt();
		z = nxt();
	}
};

int dist(const Point& p, const Point& q) {
	return abs(p.x - q.x) + abs(p.y - q.y) + abs(p.z - q.z);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<Point> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].scan();
	}

	vector<array<int, 3>> ed;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			ed.push_back({dist(a[i], a[j]), i, j});
		}
	}
	sort(all(ed));
	vector<char> used(n);
	for (const auto& [_, u, v] : ed) {
		if (used[u] || used[v]) {
			continue;
		}
		printf("%d %d\n", u + 1, v + 1);
		used[u] = used[v] = 1;
	}

	return 0;
}