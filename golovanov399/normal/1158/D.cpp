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
	int id;

	Point operator -(const Point& p) const {
		return {x - p.x, y - p.y, -1};
	}

	long long vprod(const Point& p) const {
		return x * p.y - y * p.x;
	}

	int half() const {
		if (y) {
			return y < 0;
		} else {
			return x < 0;
		}
	}

	pair<long long, long long> asPair() const {
		return {x, y};
	}

	bool operator <(const Point& p) const {
		return asPair() < p.asPair();
	}

	bool operator ==(const Point& p) const {
		return asPair() == p.asPair();
	}
};

vector<Point> getConvexHull(vector<Point> pts) {
	int idx = min_element(all(pts)) - pts.begin();
	if (idx) {
		swap(pts[0], pts[idx]);
	}
	Point o = pts[0];
	sort(pts.begin() + 1, pts.end(), [&](const Point& p, const Point& q) {
		return (p - o).vprod(q - o) > 0;
	});
	vector<Point> ch = {o};
	for (int i = 1; i < (int)pts.size(); ++i) {
		while ((int)ch.size() >= 2 && (ch.back() - ch[(int)ch.size() - 2]).vprod(pts[i] - ch.back()) <= 0) {
			ch.pop_back();
		}
		ch.push_back(pts[i]);
	}
	return ch;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<Point> pts(n);
	for (int i = 0; i < n; ++i) {
		pts[i].x = nxt();
		pts[i].y = nxt();
		pts[i].id = i;
	}
	string s;
	cin >> s;

	vector<Point> ans;
	auto ch = getConvexHull(pts);
	ans.push_back(ch[0]);
	for (char c : s) {
		int idx = find(all(ch), ans.back()) - ch.begin();
		if (c == 'L') {
			idx += 1;
		} else {
			idx -= 1;
		}
		idx %= (int)ch.size();
		if (idx < 0) {
			idx += (int)ch.size();
		}
		pts.erase(find(all(pts), ans.back()));
		ans.push_back(ch[idx]);
		ch = getConvexHull(pts);
	}
	for (const auto& p : pts) {
		if (p.id != ans.back().id) {
			ans.push_back(p);
			break;
		}
	}

	for (const auto& p : ans) {
		printf("%d ", p.id + 1);
	}
	printf("\n");

	return 0;
}