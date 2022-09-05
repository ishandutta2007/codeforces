#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

// using ll = long long;

/* 'const' can be added and for speed create += and similar
INFO 1
In methods 'below()' use '< eps' only if you HAVE TO avoid unnecessary objects,
e.g. if you need the exact size of CH. Using 'eps' may cause discarding
objects that only slightly improve the result, so try to avoid 'eps'.
INFO 2 -- In 'L3::fix()' uncomment scaling by gcd or sqrt, if needed.
INFO 3 -- How to find an upper envelope of lines Ax+By+C=0, where B > 0.
Sort lines by slope increasingly (ties: lower line first). Then a determinant
of three consecutive non-parallel lines is positive iff all three lines
are visible from the above, i.e. they form an upside down 'A' shape. */
template<typename T> T K(T a) { return a * a; }
#define K(a) K(1LL * (a))
typedef long double ll; // can be changed to 'long double'
typedef long double ld;
// const ld PI = 2 * acos(0);
const ld eps = 1e-12;
#pragma GCC diagnostic ignored "-Wnarrowing"
struct P {
	ll x, y; 
	P operator +(P he) {
		return P{x + he.x, y + he.y};
	}
	P operator -(P he) {
		return P{x - he.x, y - he.y};
	}
	ll operator *(P he) {
		return x * he.y - y * he.x;
	}
	P operator *(ll mul) {
		return P{x * mul, y * mul};
	}
	P operator /(ll mul) {
		return P{x / mul, y / mul};
	}
	// + ... (trivial operators)
	ll dot(P b) { return x * b.x + y * b.y; }
	ld len() { return sqrt(K(x) + K(y)); }
	P scaleTo(ld to) { return *this * (to / len()); }
	ld dist(P & b) { return (*this - b).len(); }
	P rotate90() { return P{-y, x}; }
	ld angle() { return atan2(y, x); }
	P rotate(ld ang) {
		ld c = cos(ang), s = sin(ang);
		return P{x * c - y * s, x * s + y * c};
	}
	// '<' and 'below()' needed for Convex Hull
	bool operator < (P he) { return make_pair(x, y) < make_pair(he.x, he.y); }
	bool below(P a, P b) { return (b - a) * (*this - a) <= 0/*eps*/; } //INFO 1
	// Internal/External Similitude Center
	P apol_in(P b, ld ratio) { // ratio = dist()/he.dist()
		return (*this + b * ratio) / (1 + ratio);
	}
	P apol_out(P b, ld ratio) {
		return (*this - b * ratio) / (1 - ratio);
	}
};
debug& operator <<(debug& dd, P p) {
	dd << "(" << p.x << ", " << p.y << ")";
	return dd;
}
struct L2 {
	P one, two;
	// P p[2]; P & operator [](int i) { return p[i]; }
	// const P & operator [](int i) const { return p[i]; }
	P dir() { return two - one; }
	P normal() { return dir().rotate90(); }
	ld dist(P he) {
		return abs((he - one) * (he - two)) / one.dist(two);
	}
	ld segDist(P he) { // epsilon not needed, but it would work too
		if((he - two) * normal() < 0 && normal() * (he - one) < 0)
			return dist(he);
		return min(one.dist(he), two.dist(he));
	}
	P inter(L2 he) {
		P A = dir(), B = he.dir();
		ll den = A * B;
		assert(abs(den) > eps); // parallel, maybe equal
		return (A * (he.one * he.two) - B * (one * two)) * (1.0 / den);
		// A = (x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4)
		// A'= (x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4)
		// B = (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)
		// return P{A / B, A' / B};
	}
	P project(P he) {
		P unit_normal = normal().scaleTo(1);
		return he + unit_normal * unit_normal.dot(one - he);
	}
	P reflect(P he) { return project(he) * 2 - he; }
// for CH: sort by slope; below() : change to L3 or compare 'x' of intersections
};
L2 toL2(ll a, ll b, ll c) {
	P first;
	if(abs(b) > eps) first = P{0, (ld) -c / b};
	else if(abs(a) > eps) first = P{(ld) -c / a, 0};
	else assert(false);
	return L2{first, first + P{b, -a}};
}
ll det(ll t[3][3]) { // for CH of lines Ax+By+C=0
	ll s = 0;
	for(int i = 0; i < 3; ++i)
		for(int j = i + 1, mul = 1; j != i + 3; ++j, mul -= 2)
			s += t[0][i] * t[1][j%3] * t[2][3-i-j%3] * mul;
	return s;
}
struct L3 {
	// a * x + b * y + c = 0, assert(b > 0 || (b == 0 && a > 0))
	ll a, b, c;
	L3 fix() { // <done>TODO, test it</done>
		assert(abs(b) > eps || abs(a) > eps);
		ll g = (b > eps || (abs(b) < eps && a > eps)) ? 1 : -1;
		// __gcd(x,0) is undef-beh, http://codeforces.com/blog/entry/13410
		// if(is_integral<ll>::value) g *= abs(__gcd(c, __gcd(a?b:a, a?a:b)));
		// if(is_floating_point<ll>::value) g *= sqrt(K(a) + K(b));
		return L3{a / g, b / g, c / g};
	}
	ld dist(P he) {
		return abs(a * he.x + b * he.y + c) / sqrt(K(a) + K(b));
	}
	P dir() { return P{b, -a}; }
	P normal() { return P{a, b}; } // equivalently: dir().rotate90()
	P project(P he) {
		ld den = K(a) + K(b); // non-integer because we need division
		return P{(b * (b * he.x - a * he.y) - a * c) / den,
				 (a * (a * he.y - b * he.x) - b * c) / den };
	}
	P reflect(P he) { return project(he) * 2 - he; }
	P inter(L3 he) {
		#define Q(i, j) (i * he.j - j * he.i)
		ll den = Q(a, b);
		assert(abs(den) > 1e-14); // parallel, maybe equal
		return P{Q(b, c), Q(c, a)} * (1.0 / den);
		#undef Q
	}
	bool operator < (L3 he) {
		// produces the order for finding an upper envelope
		// assert(b > 0 && he.b > 0);
		// a / b < he.a / he.b, ties: -c/b < ...
		if(abs(a * he.b - b * he.a) < eps) return b * he.c < c * he.b;
							// <done>test it</done>
		return a * he.b < b * he.a;
	}
	bool below(L3 A, L3 C) {
		ll t[3][3] = { {A.a,A.b,A.c}, {a,b,c}, {C.a,C.b,C.c} };
		return det(t) <= 0/*eps*/; // WARN1
	}
};
L3 toL3(P one, P two) {
	ll a = two.y - one.y;
	ll b = one.x - two.x;
	return L3{a, b, -(a * one.x + b * one.y)}.fix();
}




const int INF = 1e6 + 5;

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	vector<P> poly(n);
	for(P& p : poly) {
		int x, y;
		scanf("%d%d", &x, &y);
		p = P{x, y};
	}
	ll area = 0;
	for(int i = 0; i < n; ++i) {
		area += poly[i] * poly[(i+1)%n];
	}
	if(area > 0) {
		debug() << "REVERSE";
		reverse(poly.begin(), poly.end());
		// area *= -1;
	}
	area = abs(area) / 2;
	vector<P> left, right;
	int lowest = 0;
	for(int i = 1; i < n; ++i) {
		if(poly[i].y < poly[lowest].y) {
			lowest = i;
		}
	}
	debug() << imie(lowest);
	for(int i = lowest; ; ) {
		left.push_back(poly[i]);
		int j = (i + 1) % n;
		if(poly[j].y < poly[i].y) {
			break;
		}
		i = j;
	}
	debug() << imie(left);
	for(int i = lowest; ; ) {
		right.push_back(poly[i]);
		int j = (i + n - 1) % n;
		if(poly[j].y < poly[i].y) {
			break;
		}
		i = j;
	}
	
	debug() << imie(right);
	
	vector<vector<P>> triples;
	triples.push_back({left[0], left[0], left[0]});
	{
	int j = 1;
	for(int i = 1; i < (int) left.size(); ++i) {
		while(j < (int) right.size() - 1 && right[j].y < left[i].y) {
			L2 one{left[i], left[i-1]};
			L2 two{right[j], right[j] - P{INF, 0}};
			P inter = one.inter(two);
			triples.push_back({inter, (inter + right[j]) / 2, right[j]});
			j++;
		}
		if(i == (int) left.size() - 1) {
			break;
		}
		L2 one{right[j], right[j-1]};
		L2 two{left[i], left[i] + P{INF, 0}};
		P inter = one.inter(two);
		triples.push_back({left[i], (left[i] + inter) / 2, inter});
	}
	triples.push_back({left.back(), left.back(), left.back()});
	}
	
	debug() << imie(triples);
	
	vector<pair<ld, pair<int,int>>> events;
	for(int i = 0; i < (int) triples.size(); ++i) {
		for(int j = 0; j < 3; ++j) {
			events.emplace_back(triples[i][j].x, make_pair(i, j));
		}
	}
	
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		events.emplace_back(x, make_pair(-1, i));
	}
	sort(events.begin(), events.end());
	vector<ld> answer(q);
	vector<vector<bool>> on(triples.size(), vector<bool>(3));
	// vector<vector<ld>> brute;
	// vector<vector<ld>> linear;
	ld a1 = 0, b1 = 0, c1 = 0;
	// ld constant = 0;
	for(pair<ld, pair<int,int>> event : events) {
		ld x = event.first;
		pair<int,int> para = event.second;
		if(para.first == -1) {
			// query
			ld s = a1 * x * x + b1 * x + c1;
			// for(auto v : brute) {
				// s += v[2] * v[0] * (x - v[1]) * (x - v[1]);
			// }
			// for(auto v : linear) {
				// s += (x - v[0]) * v[1];
			// }
			// debug() << "=";
			// debug() << imie(brute);
			// debug() << imie(linear);
			debug() << "query" imie(x) imie(s) imie(para.second);
			// debug() << "=";
			answer[para.second] = s;
		}
		else {
			int i = para.first;
			int j = para.second;
			// if(j == 2) {
				// continue;
			// }
			debug() << imie(i) imie(j);
			ld mul = 1;
			if(j == 1) {
				mul = -2;
			}
			if(j == 2) {
				mul = 1;
			}
			for(int i2 : {i - 1, i + 1}) {
				if(0 <= i2 && i2 < (int) triples.size()) {
					P A = triples[i][j];
					P B = triples[i2][j];
					// debug() << imie(i) imie(i2) imie(A) imie(B);
					if(abs(A.x - B.x) >= 1e-7) {
						ld a = abs(A.y - B.y) / abs(A.x - B.x);
						if(!on[i2][j]) {
							ld tmp = a * mul / 2;
							a1 += tmp;
							b1 -= 2 * tmp * x;
							c1 += tmp * x * x;
							// brute.push_back({a, x, mul / 2});
						}
						else {
							ld tmp = a * -mul / 2;
							a1 += tmp;
							b1 -= 2 * tmp * B.x;
							c1 += tmp * B.x * B.x;
							// brute.push_back({a, B.x, -mul / 2});
						}
					}
					if(!on[i2][j]) {
						
					}
					else {
						c1 += mul * abs(A.y - B.y) * abs(A.x - B.x) / 2;
						b1 += mul * abs(A.y - B.y);
						c1 -= x * mul * abs(A.y - B.y);
						// linear.push_back({x, mul * abs(A.y - B.y)});
					}
				}
			}
			on[i][j] = true;
		}
	}
	for(ld x : answer) {
		printf("%.10lf\n", (double) (area - x));
	}
}