#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>

using namespace std;

inline int64_t gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

struct Point {
	int x, y;
};

inline int cmp(const Point &a, const Point &b) {
	int64_t d = (int64_t)a.x*b.y - (int64_t)a.y*b.x;
	if (d == 0) {
		return 0;
	}
	if (!a.y || !b.y) {
		return a.y ? -1 : +1;
	}
	return (d < 0) ? -1 : +1;
}

inline bool operator<(const Point &a, const Point &b) {
	return cmp(a, b) < 0;
}

inline bool operator==(const Point &a, const Point &b) {
	return cmp(a, b) == 0;
}

inline bool operator!=(const Point &a, const Point &b) {
	return cmp(a, b) != 0;
}

int64_t dist(const Point &a) {
	return (int64_t)a.x*a.x + (int64_t)a.y*a.y;
}

inline Point symmetry(const Point &a, const Point &b) {
	return {a.x + b.x, a.y + b.y};
}

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	int q; cin >> q;
	vector< pair<int, Point> > v;
	vector<Point> lines;
	for (int i = 0; i < q; i++) {
		int x; Point p;
		cin >> x >> p.x >> p.y;
		v.emplace_back(x, p);
		lines.push_back(p);
	}
	sort(begin(lines), end(lines));
	lines.erase(unique(begin(lines), end(lines)), end(lines));
	
	vector<int> knt(size(lines));
	vector<int> onln(size(lines));
	map<int64_t, vector<Point> > byDist;
	int total = 0;
	
	auto idxPoint = [&](const Point &p) {
		int idx = lower_bound(begin(lines), end(lines), p) - begin(lines);
		if (idx == (int)size(lines) || lines[idx] != p) {
			return -1;
		}
		return idx;
	};
	
	auto modifyAll = [&](const vector<Point> &vec, const Point &p, int delta) {
		for (Point q: vec) {
			Point s = symmetry(p, q);
			int idx = idxPoint(s);
			if (idx >= 0) {
				knt[idx] += delta;
			}
		}
		int idx = idxPoint(p);
		if (idx >= 0) {
			onln[idx] += delta;
		}
	};
	
	for (int i = 0; i < q; i++) {
		int t = v[i].first;
		Point p = v[i].second;
		int64_t d = dist(p);
		if (t == 1) {
			auto &vec = byDist[d];
			modifyAll(vec, p, +1);
			vec.push_back(p);
			total++;
		} else if (t == 2) {
			auto &vec = byDist[d];
			int pid = -1;
			for (int j = 0; j < (int)size(vec); j++) {
				if (vec[j] == p) {
					pid = j;
					break;
				}
			}
			assert(pid >= 0);
			swap(vec.back(), vec[pid]);
			vec.pop_back();
			modifyAll(vec, p, -1);
			total--;
		} else if (t == 3) {
			int idx = idxPoint(p);
			cout << total - onln[idx] - 2*knt[idx] << "\n";
		} else {
			assert(false);
		}
	}
	
	return 0;
}