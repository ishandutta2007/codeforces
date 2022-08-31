#include<bits/stdc++.h>
using namespace std;

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

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<998244353>;

template <typename T> int signum(T x) { return (x > 0) - (x < 0); }

template <typename T> struct Point {
public:
	T x, y;
	Point() : x(0), y(0) {}
	Point(T x_, T y_) : x(x_), y(y_) {}
	template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
	Point(const pair<T, T>& p) : x(p.first), y(p.second) {}
	Point(const complex<T>& p) : x(real(p)), y(imag(p)) {}
	explicit operator pair<T, T> () const { return pair<T, T>(x, y); }
	explicit operator complex<T> () const { return complex<T>(x, y); }

	friend std::ostream& operator << (std::ostream& o, const Point& p) { return o << '(' << p.x << ',' << p.y << ')'; }
	friend std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }
	friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator != (const Point& a, const Point& b) { return !(a==b); }

	Point& operator += (const Point& p) { x += p.x, y += p.y; }
	Point& operator -= (const Point& p) { x -= p.x, y -= p.y; }
	Point& operator *= (const T& t) { x *= t, y *= t; }
	Point& operator /= (const T& t) { x /= t, y /= t; }

	friend Point operator + (const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y); }
	friend Point operator - (const Point& a, const Point& b) { return Point(a.x-b.x, a.y-b.y); }
	friend Point operator * (const Point& a, const T& t) { return Point(a.x*t, a.y*t); }
	friend Point operator * (const T& t ,const Point& a) { return Point(t*a.x, t*a.y); }
	friend Point operator / (const Point& a, const T& t) { return Point(a.x/t, a.y/t); }

	friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }
	template <typename U=T> friend U abs(const Point& p) { return sqrt(U(norm(p))); }
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

	// is x in [s,t] taken ccw? 1/0/-1 for in/border/out
	friend int angle_between(const Point& s, const Point& t, const Point& x) {
		if (same_dir(x, s) || same_dir(x, t)) return 0;
		return angle_less(s, x, t) ? 1 : -1;
	}
};

using P = Point<long long>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<P> pts(N);
	for (int i = 0; i < N; i++) {
		cin >> pts[i].x >> pts[i].y;
	}

	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) { cerr << canAdj[i][j] << ' '; } cerr << '\n'; }

	vector<vector<int>> ch(N);
	vector<int> en(N);
	vector<int> par(N);
	vector<int> depth(N);
	{ // Build tree
		const int ROOT = 0; // you can muck with this
		vector<P> new_pts(N);
		int num_verts = 0;
		par[ROOT] = -1;
		std::y_combinator([&](auto self, int cur, int prv) -> void {
			int idx = num_verts++;
			new_pts[idx] = pts[cur];
			depth[idx] = par[idx] == -1 ? 0 : depth[par[idx]]+1;

			P prv_dir = prv == -1 ? P(-1, 0) : pts[prv] - pts[cur];
			sort(adj[cur].begin(), adj[cur].end(), [&,pt_cmp=angle_cmp_center(pts[cur], prv_dir)](int a, int b) -> bool {
				return pt_cmp(pts[a], pts[b]);
			});
			if (prv != -1) {
				assert(adj[cur][0] == prv);
				adj[cur].erase(adj[cur].begin());
			}
			ch[idx].reserve(adj[cur].size());
			//cerr << "children of " << cur << "; "; for (int nxt : adj[cur]) { cerr << nxt << ' '; } cerr << '\n';
			for (int nxt : adj[cur]) {
				assert(nxt != prv);
				ch[idx].push_back(num_verts);
				par[num_verts] = idx;
				self(nxt, cur);
			}
			en[idx] = num_verts;
		})(ROOT, -1);
		pts = new_pts;
		adj = {};
	}

	for (int i = 0; i < N; i++) {
		//cerr << i << ' ' << par[i] << ' ' << depth[i] << ' ' << en[i] << ' ' << pts[i] << ": ";
		//for (int j : ch[i]) cerr << j << ' ';
		//cerr << '\n';
	}

	vector<bool> canAdj(N*N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			bool isGood = true;
			for (int a = i, b = j; a != b; ) {
				if (depth[a] > depth[b]) swap(a,b);
				b = par[b];
				if (area(pts[i], pts[b], pts[j]) > 0) {
					isGood = false;
					break;
				}
			}
			canAdj[i*N+j] = isGood;
		}
	}
	//cerr << "canAdj" << '\n'; for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) { cerr << canAdj[i*N+j]; } cerr << '\n'; } cerr << '\n';

	vector<pair<P, pair<int, int>>> segments;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			segments.emplace_back(pts[j] - pts[i], pair<int,int>(i,j));
		}
	}
	sort(segments.begin(), segments.end(), [&](const auto& a, const auto& b) {
		return angle_less(P(-1, 0), a.first, b.first);
	});
	//cerr << "segments" << '\n'; for (auto seg : segments) { cerr << seg.second.first << ' ' << seg.second.second << '\n'; }

	vector<num> subtreeWays(N);
	vector<num> arcWays(N*N);
	vector<num> curDp(N*N);
	vector<num> prefWays(N, 1);
	vector<num> suffWays(N, 1);

	for (int cur = N-1; cur >= 0; cur--) {
		//cerr << "starting " << cur << '\n';
		// update arcWays for children going forwards
		// we need to use old pref/sufways
		for (int za = 0; za < int(ch[cur].size()); za++) {
			int ca = ch[cur][za];
			for (int i = ca; i < en[ca]; i++) {
				num topWays = 1;
				for (int zb = za+1; zb < int(ch[cur].size()); topWays *= subtreeWays[ch[cur][zb]], zb++) {
					int cb = ch[cur][zb];

					for (int j = cb; j < en[cb]; j++) {
						arcWays[i*N+j] = bool(canAdj[i*N+j]) * suffWays[i] * topWays * prefWays[j];
					}
				}
			}
		}

		// update prefWays and suffWays
		{
			num curPref = 1;
			for (int z = 0; z < int(ch[cur].size()); z++) {
				int c = ch[cur][z];
				for (int i = c; i < en[c]; i++) prefWays[i] *= curPref;
				curPref *= subtreeWays[c];
			}
			num curSuff = 1;
			for (int z = int(ch[cur].size())-1; z >= 0; z--) {
				int c = ch[cur][z];
				for (int i = c; i < en[c]; i++) suffWays[i] *= curSuff;
				curSuff *= subtreeWays[c];
			}
		}

		auto runDP = [&]() {
			/*
			cerr << "arcWays " << '\n';
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cerr << arcWays[i*N+j] << ' ';
				}
				cerr << '\n';
			}
			*/

			fill(curDp.begin(), curDp.end(), 0);
			for (int i = cur; i < en[cur]; i++) {
				curDp[i*N+i] = 1;
			}
			for (auto seg : segments) {
				int i,j; tie(i,j) = seg.second;
				for (int k = 0; k < N; k++) {
					curDp[j*N+k] += curDp[i*N+k] * arcWays[i*N+j];
				}
			}

			for (int i = cur; i < en[cur]; i++) {
				// -1 to exclude the self loop
				subtreeWays[cur] += curDp[i*N+i] - 1;
			}
		};

		for (int c : ch[cur]) {
			for (int i = c; i < en[c]; i++) {
				arcWays[cur*N+i] = bool(canAdj[cur*N+i]) * prefWays[i];
				arcWays[i*N+cur] = bool(canAdj[i*N+cur]) * suffWays[i];
			}
			runDP();
			for (int i = c; i < en[c]; i++) {
				arcWays[cur*N+i] = 0;
				arcWays[i*N+cur] = 0;
			}
		}

		// NOT A LEAF
		for (int ca : ch[cur]) {
			for (int cb : ch[cur]) {
				if (ca <= cb) continue;
				for (int i = ca; i < en[ca]; i++) {
					for (int j = cb; j < en[cb]; j++) {
						assert(i > j);
						arcWays[i*N+j] = bool(canAdj[i*N+j]) * suffWays[i] * prefWays[j];
					}
				}
			}
		}
		runDP();
		for (int i = cur+1; i < en[cur]; i++) {
			for (int j = cur+1; j < i; j++) {
				arcWays[i*N+j] = 0;
			}
		}

		// update suffWays with the children
		for (int c : ch[cur]) {
			suffWays[cur] *= subtreeWays[c];
		}

		subtreeWays[cur] += suffWays[cur];
		//cerr << "num polygons: " << subtreeWays[cur] << '\n';

		//cerr << "finishing " << cur << ' ' << subtreeWays[cur] << '\n';
	}
	cout << subtreeWays[0] << '\n';

	return 0;
}