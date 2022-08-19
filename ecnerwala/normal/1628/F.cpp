#include <bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

template <typename T> int signum(T a) { return (a > 0) - (a < 0); }

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

	Point operator + () const { return Point(+x, +y); }
	Point operator - () const { return Point(-x, -y); }

	Point& operator += (const Point& p) { x += p.x, y += p.y; return *this; }
	Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this; }
	Point& operator *= (const T& t) { x *= t, y *= t; return *this; }
	Point& operator /= (const T& t) { x /= t, y /= t; return *this; }

	friend Point operator + (const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y); }
	friend Point operator - (const Point& a, const Point& b) { return Point(a.x-b.x, a.y-b.y); }
	friend Point operator * (const Point& a, const T& t) { return Point(a.x*t, a.y*t); }
	friend Point operator * (const T& t ,const Point& a) { return Point(t*a.x, t*a.y); }
	friend Point operator / (const Point& a, const T& t) { return Point(a.x/t, a.y/t); }

	T dist2() const { return x * x + y * y; }
	auto dist() const { return std::sqrt(dist2()); }
	Point unit() const { return *this / this->dist(); }
	auto angle() const { return std::atan2(y, x); }

	T int_norm() const { return __gcd(x,y); }
	Point int_unit() const { if (!x && !y) return *this; return *this / this->int_norm(); }

	// Convenient free-functions, mostly for generic interop
	friend auto norm(const Point& a) { return a.dist2(); }
	friend auto abs(const Point& a) { return a.dist(); }
	friend auto unit(const Point& a) { return a.unit(); }
	friend auto arg(const Point& a) { return a.angle(); }
	friend auto int_norm(const Point& a) { return a.int_norm(); }
	friend auto int_unit(const Point& a) { return a.int_unit(); }

	Point perp_cw() const { return Point(y, -x); }
	Point perp_ccw() const { return Point(-y, x); }

	friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
	friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
	friend T cross3(const Point& a, const Point& b, const Point& c) { return cross(b-a, c-a); }

	// Complex numbers and rotation
	friend Point conj(const Point& a) { return Point(a.x, -a.y); }

	// Returns conj(a) * b
	friend Point dot_cross(const Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }
	friend Point cmul(const Point& a, const Point& b) { return dot_cross(conj(a), b); }
	friend Point cdiv(const Point& a, const Point& b) { return dot_cross(b, a) / b.norm(); }

	// Must be a unit vector; otherwise multiplies the result by abs(u)
	Point rotate(const Point& u) const { return dot_cross(conj(u), *this); }
	Point unrotate(const Point& u) const { return dot_cross(u, *this); }

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

using pt_t = Point<int>;

int cur_x;
struct my_cmp {
	bool operator() (std::array<pt_t, 2> a, std::array<pt_t, 2> b) const {
		assert(a[0].x <= cur_x && cur_x <= a[1].x);
		assert(a[0].x < a[1].x);
		assert(b[0].x <= cur_x && cur_x <= b[1].x);
		assert(b[0].x < b[1].x);

		int64_t a_num = int64_t(a[1].y) * int64_t(cur_x - a[0].x) + int64_t(a[0].y) * int64_t(a[1].x - cur_x);
		int a_den = a[1].x - a[0].x;
		int64_t b_num = int64_t(b[1].y) * int64_t(cur_x - b[0].x) + int64_t(b[0].y) * int64_t(b[1].x - cur_x);
		int b_den = b[1].x - b[0].x;
		assert(a_den > 0 && b_den > 0);
		return a_num * b_den < b_num * a_den;
	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<std::array<pt_t, 2>> segs(N);
	for (auto& [x, y] : segs) { cin >> x >> y; }

	int Q; cin >> Q;
	std::vector<pt_t> queries(Q);
	for (auto& q : queries) cin >> q;

	std::vector<bool> ans(Q);
	for (int z = 0; z < Q; z++) {
		auto q = queries[z];
		bool crosses = false;
		for (int i = 0; i < N; i++) {
			if (signum(cross3(segs[i][0], segs[i][1], pt_t(0,0))) * signum(cross3(segs[i][0], segs[i][1], q)) == -1
					&& signum(cross3(pt_t(0, 0), q, segs[i][0])) * signum(cross3(pt_t(0, 0), q, segs[i][1])) <= 0) {
				crosses = true;
				break;
			}
		}
		ans[z] = !crosses;
	}

	auto solve_angle = [&](pt_t last_pt) {
		pt_t dir = -last_pt; // we travel upwards
		pt_t x_axis = dir.perp_cw();
		std::map<std::array<pt_t, 2>, int, my_cmp> live_segs;
		std::vector<decltype(live_segs)::iterator> its(N+1);

		std::vector<std::tuple<int, int, int>> evts; evts.reserve(2*N+Q);
		for (int i = 0; i < N; i++) {
			pt_t a = segs[i][0].unrotate(x_axis);
			pt_t b = segs[i][1].unrotate(x_axis);
			if (a.x == b.x) continue;
			if (a.x > b.x) std::swap(a, b);
			assert(a.x < b.x);
			evts.push_back({a.x, 1, i});
			evts.push_back({b.x, 2, i});
		}

		std::vector<int> nxt(N, -1);
		evts.push_back({0, 3, -1});

		std::vector<int> q_nxt(Q, -1);

		for (int q = 0; q < Q; q++) {
			if (ans[q]) continue;
			pt_t a = queries[q].unrotate(x_axis);
			evts.push_back({a.x, 0, q});
		}

		std::sort(evts.begin(), evts.end());
		for (int st = 0, en = 0; st < int(evts.size()); st = en) {
			cur_x = std::get<0>(evts[st]);
			while (en < int(evts.size()) && std::get<0>(evts[en]) == cur_x) en++;
			// first, do all inserts
			for (int z = st; z < en; z++) {
				auto [x, op, i] = evts[z];
				assert(x == cur_x);
				if (op == 1) {
					pt_t a = segs[i][0].unrotate(x_axis);
					pt_t b = segs[i][1].unrotate(x_axis);
					if (a.x > b.x) std::swap(a, b);
					assert(a.x <= cur_x && cur_x <= b.x);
					its[i] = live_segs.insert({{a, b}, i}).first;
				} else if (op == 3) {
					its[N] = live_segs.insert({{pt_t(cur_x-1, 0), pt_t(cur_x+1, 0)}, N}).first;
				}
			}

			// now, do all queries
			//
			for (int z = st; z < en; z++) {
				auto [x, op, i] = evts[z];
				assert(x == cur_x);
				if (op == 1) {
					pt_t a = segs[i][0].unrotate(x_axis);
					pt_t b = segs[i][1].unrotate(x_axis);
					if (a.x > b.x) std::swap(a, b);
					if ((a.y - b.y) > (b.x - a.x)) {
						auto it = live_segs.upper_bound({a, b});
						if (it != live_segs.end()) nxt[i] = it->second;
					}
				} else if (op == 2) {
					pt_t a = segs[i][0].unrotate(x_axis);
					pt_t b = segs[i][1].unrotate(x_axis);
					if (a.x > b.x) std::swap(a, b);
					if ((b.y - a.y) > (b.x - a.x)) {
						auto it = live_segs.upper_bound({a, b});
						if (it != live_segs.end()) nxt[i] = it->second;
					}
				} else if (op == 0) {
					int q = i;
					pt_t a = queries[q].unrotate(x_axis);
					auto it = live_segs.upper_bound({pt_t(cur_x-1, a.y), pt_t(cur_x+1, a.y)});
					if (it != live_segs.end()) q_nxt[q] = it->second;
				}
			}

			// last, do all deletes
			for (int z = st; z < en; z++) {
				auto [x, op, i] = evts[z];
				assert(x == cur_x);
				if (op == 2) {
					live_segs.erase(its[i]);
				} else if (op == 3) {
					live_segs.erase(its[N]);
				}
			}
		}

		std::vector<int> mem_dest(N);
		auto trace = std::y_combinator([&](auto self, int a) -> int {
			if (a == -1 || a == N) return a;
			if (mem_dest[a]) return mem_dest[a];
			return mem_dest[a] = self(nxt[a]);
		});
		for (int q = 0; q < Q; q++) {
			ans[q] = ans[q] || trace(q_nxt[q]) == N;
		}
	};
	std::vector<pt_t> angs; angs.reserve(2*N+Q);
	for (auto [x, y] : segs) {
		solve_angle(x);
		solve_angle(y);
	}

	for (int q = 0; q < Q; q++) {
		cout << (ans[q] ? "YES" : "NO") << '\n';
	}

	return 0;
}