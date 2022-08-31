#include<bits/stdc++.h>
using namespace std;

template <typename T> struct Point {
	T x, y;
	Point() {}
	Point(T x_, T y_) : x(x_), y(y_) {}

	using pair = std::pair<T, T>;
	explicit operator pair() const { return pair(x, y); }
	friend bool operator == (const Point& a, const Point& b) { return pair(a) == pair(b); }
	friend bool operator != (const Point& a, const Point& b) { return pair(a) != pair(b); }
	friend bool operator < (const Point& a, const Point& b) { return pair(a) < pair(b); }
	friend bool operator <= (const Point& a, const Point& b) { return pair(a) <= pair(b); }
	friend bool operator > (const Point& a, const Point& b) { return pair(a) > pair(b); }
	friend bool operator >= (const Point& a, const Point& b) { return pair(a) >= pair(b); }

	friend std::ostream& operator << (std::ostream& o, const Point& p) {
		return o << "(" << p.x << "," << p.y << ")";
	}
	friend std::istream& operator >> (std::istream& i, Point& p) {
		return i >> p.x >> p.y;
	}

	Point& operator += (const Point& p) {
		x += p.x;
		y += p.y;
		return *this;
	}
	Point& operator -= (const Point& p) {
		x -= p.x;
		y -= p.y;
		return *this;
	}
	friend Point operator + (const Point& a, const Point& b) { return Point(a) += b; }
	friend Point operator - (const Point& a, const Point& b) { return Point(a) -= b; }

	T cross(const Point& p) const { return x * p.y - y * p.x; }
	T cross(const Point& p, const Point& q) const { return (p-*this).cross(q-*this); }
};

using Pt = Point<int>;

const int MAXN = 7000;
int A, B;
int N;
struct City {
	Pt pt;
	int id;
	int deg; // 0 is red, -1 is dead
	friend bool operator < (const City& a, const City& b) { return a.pt < b.pt; }
} pts[MAXN];

int hsz;
int hull[MAXN];

void solve(int st, int en) {
	if (st == en) return;
	if (pts[st].deg == -1) return solve(st+1, en);
	if (pts[en].deg == -1) return solve(st, en-1);

	int len = 0;
	int totdeg = 0;
	for (int i = st; i <= en; i++) {
		if (pts[i].deg == -1) continue;
		len++;
		totdeg += pts[i].deg;
	}
	assert(len);
	assert(totdeg == len-1);
	assert(len >= 2);

	{
		// case 1: do the hull
		hsz = 0;
		for (int i = 0; i <= (en - st) * 2; i++) {
			int cur = (i <= (en - st) ? (st + i) : (en + (en - st) - i));
			if (pts[cur].deg == -1) continue;
			while (hsz >= 2 && hull[hsz-1] != en) {
				if (pts[hull[hsz-2]].pt.cross(pts[hull[hsz-1]].pt, pts[cur].pt) < 0) {
					break;
				} else {
					hsz--;
				}
			}
			hull[hsz++] = cur;
		}
		hsz--;
		assert(hsz >= 2);
		assert(hull[hsz] == hull[0]);
		// hull includes start point twice
		for (int ind = 0; ind < hsz; ind++) {
			int a = hull[ind], b = hull[ind+1];
			assert(pts[a].deg != -1 && pts[b].deg != -1);
			if (pts[a].deg == 0 && pts[b].deg > 0) {
				cout << pts[b].id << ' ' << pts[a].id << '\n';
				pts[b].deg --;
				if (pts[b].deg == 0) {
					pts[b].deg = -1;
				} else {
					pts[a].deg = -1;
				}
				return solve(st, en);
			}
		}
	}

	int pref = 0;
	int lsz = 0;
	for (int i = st; i <= en; i++) {
		if (pts[i].deg == -1) continue;
		int suff = pref + (pts[i].deg - 1);
		lsz++;
		if (lsz > 1 && lsz < len && (pref >= 0) != (suff >= 0)) {
			int ldeg, rdeg;
			if (pts[i].deg > 0) {
				assert(pref < 0 && suff >= 0);
				ldeg = -pref;
				rdeg = suff+1;
				assert(ldeg + rdeg == pts[i].deg);
			} else {
				ldeg = 0;
				rdeg = 0;
			}
			pts[i].deg = ldeg;
			solve(st, i);
			pts[i].deg = rdeg;
			solve(i, en);
			return;
		}
		pref = suff;
	}
	assert(false);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> A >> B;
		N = A + B;
		for (int i = 0; i < A; i++) {
			pts[i].deg = 0;
			pts[i].id = i + 1;
		}
		for (int i = A; i < A + B; i++) {
			cin >> pts[i].deg;
			assert(pts[i].deg > 0);
			pts[i].id = i-A + 1;
		}
		for (int i = 0; i < N; i++) {
			cin >> pts[i].pt;
		}
		sort(pts, pts + N);
		cout << "YES" << '\n';
		solve(0, N-1);
	}

	return 0;
}