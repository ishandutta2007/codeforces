#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using dbl = long double;

const dbl EPS = 1e-9;
const dbl PI = acos(-1.);
const int PREC = 20;
inline bool eq(dbl a, dbl b) { return abs(a-b)<=EPS; }
inline bool gr(dbl a, dbl b) { return a>b+EPS; }
inline bool geq(dbl a, dbl b) { return a>=b-EPS; }
inline bool ls(dbl a, dbl b) { return a<b-EPS; }
inline bool leq(dbl a, dbl b) { return a<=b+EPS; }

struct Pnt {
    dbl x,y;
    Pnt(): x(0), y(0) {}
    Pnt(dbl xx, dbl yy): x(xx), y(yy) {}

    inline Pnt operator +(const Pnt &p) const { return Pnt(x + p.x, y + p.y); }
    inline Pnt operator -(const Pnt &p) const { return Pnt(x - p.x, y - p.y); }
    inline dbl operator *(const Pnt &p) const { return x * p.x + y * p.y; } // ll
    inline dbl operator %(const Pnt &p) const { return x * p.y - y * p.x; } // ll

    inline Pnt operator *(dbl k) const { return Pnt(x * k, y * k); }
    inline Pnt operator /(dbl k) const { return Pnt(x / k, y / k); }
    inline Pnt operator -() const { return Pnt(-x, -y); }

    inline void operator +=(const Pnt &p) { x += p.x, y += p.y; }
    inline void operator -=(const Pnt &p) { x -= p.x, y -= p.y; }
    inline void operator *=(dbl k) { x*=k, y*=k; }

    inline bool operator ==(const Pnt &p) const { return abs(x-p.x)<=EPS && abs(y-p.y)<=EPS; }
    inline bool operator !=(const Pnt &p) const { return abs(x-p.x)>EPS || abs(y-p.y)>EPS; }
    inline bool operator <(const Pnt &p) const { return abs(x-p.x)<=EPS ? y<p.y-EPS : x<p.x; }

    inline dbl angle() const { return atan2(y, x); } // ld
    inline dbl len2() const { return x*x+y*y; } // ll
    inline dbl len() const { return sqrt(x*x+y*y); } // ll, ld
    inline Pnt getNorm() const {
        auto l = len();
        return Pnt(x/l, y/l);
    }
    inline void normalize() {
        auto l = len();
        x/=l, y/=l;
    }

    inline Pnt getRot90() const { //counter-clockwise
        return Pnt(-y, x);
    }
    inline Pnt getRot(dbl a) const { // ld
        dbl si = sin(a), co = cos(a);
        return Pnt(x*co - y*si, x*si + y*co);
    }

    inline void read() {
        int xx, yy;
		cin >> xx >> yy;
        x = xx, y = yy;
    }
    inline void write() const{
        cout << fixed << (double)x << " " << (double)y << '\n';
    }
};

struct Circle {
    Pnt p;
    dbl r;
};

dbl circle_isect_area(const Circle &x, const Circle &y) {
	dbl d = (x.p-y.p).len(), a = x.r, b = y.r; if (a < b) swap(a,b);
	if (geq(d, a+b)) return 0;
	if (leq(d, a-b)) return PI*b*b;
	dbl ca = acosl((a*a+d*d-b*b)/(2*a*d)), cb = acosl((b*b+d*d-a*a)/(2*b*d));
	return (ca*a*a-0.5*a*a*sin(ca*2))+(cb*b*b-0.5*b*b*sin(cb*2));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.precision(20);
	Circle x, y;
	x.p.read();
	cin >> x.r;
	y.p.read();
	cin >> y.r;
	cout << fixed << circle_isect_area(x, y) << '\n';
	return 0;
}