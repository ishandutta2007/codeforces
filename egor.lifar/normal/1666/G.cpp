#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using ld = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}
tcT> void output(T begin, T end) {
	while (begin != end) {
		cerr << *begin++ << ' ';
	}
	cerr << endl;
}

struct dsu {
	int n;
	vector<int> par, sz;
	vector<ld> coef[3];

	dsu(int _n): n(_n), par(n), sz(n, 1) {
		iota(all(par), 0);
		for (int i = 0; i < 3; ++i) {
			coef[i].resize(n);
		}
	}

	int get_root(int v) {
		return par[v] == v ? v : (par[v] = get_root(par[v]));
	}

	void join(int u, int v) {
		// cerr << "join " << u << ' ' << v << '\n';
		u = get_root(u);
		v = get_root(v);
		if (u == v) {
			return;
		}
		par[u] = v;
		sz[v] += sz[u];
		for (int i = 0; i < 3; ++i) {
			coef[i][v] += coef[i][u];
		}
	}

	void add_linear(int v, ld _k2, ld _k1, ld _k0) {
		// cerr << "add_linear " << v << ' ' << _k2 << ' ' << _k1 << ' ' << _k0 << '\n';
		// cerr << "value at 4 is " << _k2 * 4 * 4 + _k1 * 4 + _k0 << '\n';
		v = get_root(v);
		coef[2][v] += _k2;
		coef[1][v] += _k1;
		coef[0][v] += _k0;
	}

	ld get(int v, ld z) {
		v = get_root(v);
		// cerr << "get " << v << ' ' << z << '\n';
		// cerr << "subtree size = " << sz[v] << '\n';
		return coef[2][v] * z * z + coef[1][v] * z + coef[0][v];
	}
};

struct point {
	ld x, y, z;
};

point operator - (const point& a, const point& b) {
	return {a.x - b.x, a.y - b.y, a.z - b.z};
}

bool zcmp(const point &a, const point &b) {
	return a.z < b.z;
}

struct linear {
	ll l, r;
	ld k2, k1, k0;
};

// 0 - linear function
// 1 - point
// 2 - query
struct event {
	ll h;
	int type;
	int id, v;
	ld k2, k1, k0;
};

bool operator < (const event& a, const event& b) {
	return tie(a.h, a.type) < tie(b.h, b.type);
}

const int MAX_N = 1e5 + 228;
const int MAX_Q = 1e5 + 228;
int n, f, q;
vector<point> a;
vector<array<int, 3>> triangles;
vector<int> face_by_v[MAX_N];
ld ans[MAX_Q];
vector<event> events;

ld sq_det(ld a, ld b, ld c, ld d) {
	ld det = a * d - b * c;
	return det * det;
}

ld area(point v1, point v2) {
	return sqrtl(sq_det(v1.x, v1.y, v2.x, v2.y) +
		sq_det(v1.x, v1.z, v2.x, v2.z) +
		sq_det(v1.y, v1.z, v2.y, v2.z)) / 2;
}

ld area(point P, point Q1, point Q2) {
	return area(Q1 - P, Q2 - P);
}

array<ld, 3> find_coeffs1(ld C, ld S, ld z0, ld z1) {
	ld SQ = (z0 - z1) * (z0 - z1);
	return {{
		S / SQ,
		S * (-2 * z0) / SQ,
		C + S * z0 * z0 / SQ
	}};
}

vector<linear> get_linear_functions(vector<point> p) {
	sort(rall(p), zcmp);
	ll z0 = (ll)(p[0].z + 0.5);
	ll z1 = (ll)(p[1].z + 0.5);
	ll z2 = (ll)(p[2].z + 0.5);
	if (z0 == z2) {
		return {{z0, -1, 0, 0, area(p[0], p[1], p[2])}};
	}
	ld frac = (p[0].z - p[1].z) / (p[0].z - p[2].z);
	point p4 = {p[0].x + (p[2].x - p[0].x) * frac,
		p[0].y + (p[2].y - p[0].y) * frac,
		p[1].z};
	ld S1 = area(p[1], p[0], p4);
	ld S2 = area(p[1], p4, p[2]);
	vector<linear> result;
	if (z1 < z0) {
		auto coefs = find_coeffs1(0, S1, z0, z1);
		result.push_back({z0, z1, coefs[0], coefs[1], coefs[2]});
		// assert(fabsl(coefs[0] * z0 * z0 + coefs[1] * z0 + coefs[2] - 0) < 1e-9);
		// assert(fabsl(coefs[0] * z1 * z1 + coefs[1] * z1 + coefs[2] - S1) < 1e-9);
		// ld z = z0 + 0.42 * (z1 - z0);
		// assert(fabsl(coefs[0] * z * z + coefs[1] * z + coefs[2] - S1 * 0.42 * 0.42) < 1e-9);
	}
	if (z2 < z1) {
		auto coefs = find_coeffs1(S1 + S2, -S2, z2, z1);
		result.push_back({z1, z2, coefs[0], coefs[1], coefs[2]});
		// assert(fabsl(coefs[0] * z1 * z1 + coefs[1] * z1 + coefs[2] - S1) < 1e-9);
		// assert(fabsl(coefs[0] * z2 * z2 + coefs[1] * z2 + coefs[2] - S1 - S2) < 1e-9);
		// ld z = z1 + 0.42 * (z2 - z1);
		// assert(fabsl(coefs[0] * z * z + coefs[1] * z + coefs[2] - S1 - S2 * 0.42 * 0.42) < 1e-9);
	}
	result.push_back({z2, -1, 0, 0, S1 + S2});
	// cerr << "linear functions\n";
	// cerr << "zs " << z0 << ' ' << z1 << ' ' << z2 << '\n';
	// cerr << "frac " << frac << '\n';
	// cerr << "S1, S2 " << S1 << ' ' << S2 << '\n';
	// for (auto lf : result) {
	// 	cerr << lf.l << ' ' << lf.r << ' ' << lf.k << ' ' << lf.b << '\n';
	// }
	return result;
}

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll x, y, z;
		cin >> x >> y >> z;
		a.push_back({(ld)x, (ld)y, (ld)z});
		events.push_back({z, 1, i, 0, 0, 0, 0});
	}
	cin >> f;
	for (int i = 0; i < f; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		triangles.push_back({{a, b, c}});
		for (auto v : triangles.back()) {
			face_by_v[v].push_back(i);
		}
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll h;
		int v;
		cin >> h >> v;
		v--;
		events.push_back({h, 2, i, v, 0, 0, 0});
	}
}

void solve() {
	vector<point> triangle;
	for (int i = 0; i < f; ++i) {
		triangle.clear();
		for (auto v : triangles[i]) {
			triangle.push_back(a[v]);
		}
		vector<linear> lf = get_linear_functions(triangle);
		for (auto func : lf) {
			events.push_back({func.l, 0, -1, i, func.k2, func.k1, func.k0});
			events.push_back({func.r, 0, -1, i, -func.k2, -func.k1, -func.k0});
		}
	}
	sort(rall(events));
	dsu T(f);
	for (auto [h, type, id, v, k2, k1, k0] : events) {
		if (type == 0) {
			T.add_linear(v, k2, k1, k0);
		} else if (type == 1) {
			for (int i = 0; i < (int)face_by_v[id].size() - 1; ++i) {
				T.join(face_by_v[id][i], face_by_v[id][i + 1]);
			}
		} else {
			if ((ll)(a[v].z + 0.5) <= h) {
				ans[id] = -1;
			} else {
				ans[id] = T.get(face_by_v[v][0], h);
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		if (ans[i] < -0.5) {
			cout << -1 << '\n';
		} else {
			cout << ans[i] << '\n';
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout << setprecision(10) << fixed;
	read();
	solve();
}