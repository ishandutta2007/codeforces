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
	int id;

	void scan() {
		x = nxt();
		y = nxt();
		z = nxt();
	}

	array<int, 3> asArray() const {
		return {{x, y, z}};
	}

	bool operator <(const Point& ot) const {
		return asArray() < ot.asArray();
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
		a[i].id = i;
	}

	sort(all(a));
	vector<char> used(n);

	for (int i = 0; i < (int)a.size() - 1; ++i) {
		if (used[a[i].id]) {
			continue;
		}
		if (a[i].x == a[i + 1].x && a[i].y == a[i + 1].y) {
			printf("%d %d\n", a[i].id + 1, a[i + 1].id + 1);
			used[a[i].id] = used[a[i + 1].id] = 1;
		}
	}
	{
		vector<Point> tmp;
		for (const auto& p : a) {
			if (!used[p.id]) {
				tmp.push_back(p);
			}
		}
		a.swap(tmp);
	}

	for (int i = 0; i < (int)a.size() - 1; ++i) {
		if (used[a[i].id]) {
			continue;
		}
		if (a[i].x == a[i + 1].x) {
			printf("%d %d\n", a[i].id + 1, a[i + 1].id + 1);
			used[a[i].id] = used[a[i + 1].id] = 1;
		}
	}
	{
		vector<Point> tmp;
		for (const auto& p : a) {
			if (!used[p.id]) {
				tmp.push_back(p);
			}
		}
		a.swap(tmp);
	}

	for (int i = 0; i < (int)a.size() - 1; ++i) {
		if (used[a[i].id]) {
			continue;
		}
		if (true) {
			printf("%d %d\n", a[i].id + 1, a[i + 1].id + 1);
			used[a[i].id] = used[a[i + 1].id] = 1;
		}
	}
	{
		vector<Point> tmp;
		for (const auto& p : a) {
			if (!used[p.id]) {
				tmp.push_back(p);
			}
		}
		a.swap(tmp);
	}

	return 0;
}