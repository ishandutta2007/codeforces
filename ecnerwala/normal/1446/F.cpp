#include <bits/stdc++.h>

template <typename T> struct Point {
public:
	T x, y;
	Point() : x(0), y(0) {}
	Point(T x_, T y_) : x(x_), y(y_) {}
	template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
	Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
	Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
	explicit operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }
	explicit operator std::complex<T> () const { return std::complex<T>(x, y); }

	friend std::ostream& operator << (std::ostream& o, const Point& p) { return o << '(' << p.x << ',' << p.y << ')'; }
	friend std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }
	friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator != (const Point& a, const Point& b) { return !(a==b); }

	Point& operator += (const Point& p) { x += p.x, y += p.y; return *this; }
	Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this; }
	Point& operator *= (const T& t) { x *= t, y *= t; return *this; }
	Point& operator /= (const T& t) { x /= t, y /= t; return *this; }

	friend Point operator + (const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y); }
	friend Point operator - (const Point& a, const Point& b) { return Point(a.x-b.x, a.y-b.y); }
	friend Point operator * (const Point& a, const T& t) { return Point(a.x*t, a.y*t); }
	friend Point operator * (const T& t ,const Point& a) { return Point(t*a.x, t*a.y); }
	friend Point operator / (const Point& a, const T& t) { return Point(a.x/t, a.y/t); }

	friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }
	friend auto abs(const Point& p) { return std::hypot(p.x, p.y); }
	friend T unit(const Point& a) { if (a == Point()) return a; return a / abs(a); }

	friend T int_norm(const Point& a) { return __gcd(a.x,a.y); }
	friend T int_unit(const Point& a) { if (a == Point()) return a; return a / int_norm(a); }

	friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
	friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
	friend T area(const Point& a, const Point& b, const Point& c) { return cross(b-a, c-a); }

	// Returns conj(a) * b
	friend Point rotation(const Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }

	friend bool same_dir(const Point& a, const Point& b) { return cross(a,b) == 0 && dot(a,b) > 0; }

	// check if 180 <= s..t < 360
	friend bool is_reflex(const Point& a, const Point& b) { auto c = cross(a,b); return c ? (c < 0) : (dot(a, b) < 0); }

	// operator < (s,t) for angles in [base,base+2pi)
	friend bool angle_less(const Point& base, const Point& s, const Point& t) {
		int r = is_reflex(base, s) - is_reflex(base, t);
		return r ? (r < 0) : (0 < cross(s, t));
	}

	friend auto angle_cmp(const Point& base) {
		return [base](const Point& s, const Point& t) { return angle_less(base, s, t); };
	}
	friend auto angle_cmp_center(const Point& center, const Point& dir) {
		return [center, dir](const Point& s, const Point& t) -> bool { return angle_less(dir, s-center, t-center); };
	}

	// is p in [s,t] taken ccw? 1/0/-1 for in/border/out
	friend int angle_between(const Point& s, const Point& t, const Point& p) {
		if (same_dir(p, s) || same_dir(p, t)) return 0;
		return angle_less(s, p, t) ? 1 : -1;
	}
};

const double PI = acos(-1.);

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	// Find the Kth largest
	int64_t N, K; cin >> N >> K; K = N * (N-1) / 2 + 1 - K;

	using pt_t = Point<double>;
	vector<pt_t> P(N);
	for (auto& pt : P) cin >> pt;

	auto num_bigger = [&](double R) -> int64_t {
		vector<pair<double, int>> evts; evts.reserve(2*N);
		for (int i = 0; i < N; i++) {
			auto pt = P[i];
			if (abs(pt) <= R) {
				continue;
			}
			double delta = acos(R / abs(pt));
			double center = atan2(pt.y, pt.x);
			for (double v : { center - delta, center + delta }) {
				if (v <= -PI) v += 2 * PI;
				if (v > PI) v -= 2 * PI;
				evts.push_back({v, i});
			}
		}
		sort(evts.begin(), evts.end());
		int M = int(evts.size());
		vector<int> seg(2*M);
		vector<int> last_coord(N, -1);
		int64_t ans = 0;
		for (int z = 0; z < M; z++) {
			int t = evts[z].second;
			if (last_coord[t] == -1) {
				last_coord[t] = z;
			} else {
				int y = last_coord[t];
				// y..z
				for (int a = M+y; a; a >>= 1) {
					ans += seg[a];
				}
				for (int a = M+y, b = M+z; a < b; a >>= 1, b >>= 1) {
					if (a & 1) seg[a++] ++;
					if (b & 1) seg[--b] ++;
				}
			}
		}
		return ans;
	};

	double mi = 0;
	double ma = 1e5;
	for (int z = 0; z < 60; z++) {
		double md = (mi + ma) / 2;
		if (num_bigger(md) >= K) {
			mi = md;
		} else {
			ma = md;
		}
	}

	cout << fixed << setprecision(20) << ma << '\n';

	return 0;
}