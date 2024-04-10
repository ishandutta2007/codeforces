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

using ld = long double;
using li = long long;

struct Point {
	li x, y;

	pair<li, li> asPair() const {
		return {x, y};
	}

	bool operator <(const Point& p) const {
		return asPair() < p.asPair();
	}
};

bool isUp(const Point& p, const Point& q, const Point& r) {
	return q.y * (p.x - r.x) < (q.x - p.x) * (q.x - r.x) * (p.x - r.x) + q.x * p.y - q.x * r.y + p.x * r.y - p.y * r.x;
}

bool isOn(const Point& p, const Point& q, const Point& r) {
	return q.y * (p.x - r.x) == (q.x - p.x) * (q.x - r.x) * (p.x - r.x) + q.x * p.y - q.x * r.y + p.x * r.y - p.y * r.x;
}

ld getB(const Point& p, const Point& q) {
	return p.x + q.x - (ld)(p.y - q.y) / (p.x - q.x);
}

ostream& operator <<(ostream& ostr, const vector<int>& v) {
	ostr << "{";
	for (int i = 0; i < (int)v.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << v[i];
	}
	ostr << "}";
	return ostr;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<Point> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].x = nxt();
		a[i].y = nxt();
	}

	sort(all(a));
	{
		vector<Point> b;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || a[i].x != a[i - 1].x) {
				b.push_back(a[i]);
			} else {
				b.back() = a[i];
			}
		}
		a.swap(b);
		n = a.size();
	}

	if ((int)a.size() == 1) {
		cout << "0\n";
		return 0;
	}
	if ((int)a.size() == 2) {
		cout << "1\n";
		return 0;
	}


	function<vector<int>(int, int)> f = [&](int l, int r) {
		if (r <= l) {
			return vector<int>{};
		}
		if (r == l + 1) {
			return vector<int>{l, r};
		}
		int m = (l + r) / 2;
		auto left = f(l, m);
		auto right = f(m, r);
		reverse(all(right));
		right.pop_back();
		// cerr << "start " << l << " " << r << " " << left << " " << right << "\n";
		while (true) {
			if ((int)left.size() >= 2 && !isUp(a[left[left.size() - 2]], a[left.back()], a[right.back()])) {
				left.pop_back();
			} else if ((int)right.size() >= 2 && !isUp(a[left.back()], a[right.back()], a[right[right.size() - 2]])) {
				right.pop_back();
			} else {
				break;
			}
		}
		reverse(all(right));
		// cerr << l << " " << r << ": " << left << " " << right << "\n";
		left.insert(left.end(), all(right));
		return left;
	};


	cout << f(0, n - 1).size() - 1 << "\n";

	return 0;
}