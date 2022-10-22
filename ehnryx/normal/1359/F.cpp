#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>
using namespace std;

#pragma GCC poison abs

typedef double ld;

const char nl = '\n';
//const ld INF = 1e36;
const ld INF = 1/0.L;
const ld EPS = 1e-9;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define CUSTOM
#ifdef CUSTOM

struct pt {
	ld x, y;
	pt(const ld& _x=0, const ld& _y=0): x(_x), y(_y) {}
	pt operator + (const pt& o) const { return pt(x+o.x, y+o.y); }
	pt operator - (const pt& o) const { return pt(x-o.x, y-o.y); }
};
pt operator * (const ld& c, const pt& v) {
	return pt(c * v.x, c * v.y);
}
inline ld cp(const pt& a, const pt& b) {
	return a.x*b.y - a.y*b.x;
}
inline ld dp(const pt& a, const pt& b) {
	return a.x*b.x + a.y*b.y;
}

#else

typedef complex<ld> pt;
inline ld cp(const pt& a, const pt& b) {
	return a.real()*b.imag() - b.real()*a.imag();
}
inline ld dp(const pt& a, const pt& b) {
	return a.real()*b.real() + a.imag()*b.imag();
}

#endif

inline ld sqr(int x) {
	return x*x;
}

int sgn(const ld& x) {
	return x < -EPS ? -1 : x <= EPS ? 0 : 1;
}

inline pt line_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
	return a + cp(c-a, d-c) / cp(b-a, d-c) * (b-a);
}

struct Car {
	pt v, d; int s;
	Car(int x, int y, int dx, int dy, int _s): v(x, y), d(dx, dy), s(_s) {}
	ld hit(const pt& it) const {
		pt len = it - v;
		return sgn(dp(len, d)) >= 0 ? dp(len,len) / sqr(s) : INF;
	}
};

ld parallel(const Car&a, const Car& b) {
	pt len = b.v - a.v; // a -> b
	if(sgn(cp(len, a.d)) != 0) return INF;
	int da = sgn(dp(len, a.d)), db = sgn(dp(len, b.d));
	if(da >= 0 && db <= 0) return dp(len,len) / sqr(a.s+b.s);
	if(da >= 0 && db >= 0) return dp(len,len) / sqr(a.s);
	if(da <= 0 && db <= 0) return dp(len,len) / sqr(b.s);
	return INF;
}

ld collide(const Car& a, const Car& b) {
	if(sgn(cp(a.d, b.d)) == 0)  return parallel(a, b);
	pt it = line_inter(a.v, a.v + a.d, b.v, b.v + b.d);
	return max(a.hit(it), b.hit(it));
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<Car> v;
	for(int i=0; i<n; i++) {
		int x, y, dx, dy, s;
		cin >> x >> y >> dx >> dy >> s;
		v.emplace_back(x, y, dx, dy, s);
	}

	ld ans = INF;
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			ans = min(ans, collide(v[i], v[j]));
		}
	}

	if(ans < INF) {
		cout << sqrt(ans) << nl;
	} else {
		cout << "No show :(" << nl;
	}

	return 0;
}