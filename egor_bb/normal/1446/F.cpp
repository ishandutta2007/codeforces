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
using dbl = double;
 
const int N = 1e5 + 100;
const int REPS = 80;
 
const dbl PI = acos(-1.);
const dbl EPS = 1e-9;
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
    
  	inline Pnt unit() const {
  		dbl l = len();
  		return Pnt(x / l, y / l);
  	}
};
 
struct Line{
    dbl a, b, c;
    Line(): a(0), b(0), c(0) {}
    // normalizes
    Line(dbl aa, dbl bb, dbl cc) {
    	dbl norm = sqrt(aa * aa + bb * bb);
    	aa /= norm, bb /= norm, cc /= norm;
    	a = aa, b = bb, c = cc;
    }
 
    Line(const Pnt &A, const Pnt &p){ // it normalizes (a,b), important in d(), normalToP()
        Pnt n = (p-A).getRot90().getNorm();
        a = n.x, b = n.y, c = -(a * A.x + b * A.y);
    }
 
    inline dbl d(const Pnt &p) const { return a*p.x + b*p.y + c; }
    inline Pnt no() const {return Pnt(a, b);}
    inline Pnt normalToP(const Pnt &p) const { return Pnt(a,b) * (a*p.x + b*p.y + c); }
 
    inline void write() const{
    	cout << fixed << (double)a << " " << (double)b << " " << (double)c << '\n';
    }
};
  
inline dbl sqr(dbl x) { return x * x; }
 
 
struct Circle {
    Pnt p;
    dbl r;
};
 
Pnt multBenq(const Pnt& l, const Pnt& r) { return Pnt(l.x * r.x - l.y * r.y, l.y * r.x + l.x * r.y); }
 
Pnt tangent(Pnt x, Circle y, int t = 0) {
	y.r = abs(y.r); // abs needed because internal calls y.s < 0
	if (y.r == 0) return y.p;
	dbl d = (x - y.p).len();
	Pnt a = (x - y.p) * pow(y.r / d, 2)  + y.p;
	Pnt b = multBenq((x - y.p).unit() * sqrtl(d * d - y.r * y.r) / d * y.r, Pnt(0, 1)); 
	return t == 0 ? a+b : a-b;
}
 
 
#define ADD 1
#define DEL 2
 
 
Pnt p[N];
int lastPos[3 * N], tree[12 * N], tSize = 1;
 
void setPos(int pos, int val) {
	pos += tSize;
	tree[pos] = val;
	while(pos) {
		pos /= 2;
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
	}
}
 
int getSum(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return tree[v];
	}
	return getSum(2 * v, vl, (vl + vr) / 2, l, r) + getSum(2 * v + 1, (vl + vr) / 2, vr, l, r);
}
  
ll cnt(dbl r, int n) {
	Circle c;
	c.p = Pnt(0, 0);
	c.r = r;
	
	vector<pair<dbl, pii>> events;
	
	forn(i, n) {
		if (p[i].len() < r) {
			continue;
		}
		dbl angle1 = tangent(p[i], c, 0).angle();
		dbl angle2 = tangent(p[i], c, 1).angle();
		if (angle1 > angle2) {
			swap(angle1, angle2);
		}
		if (p[i].x < 0 && angle1 < 0 && angle2 > 0) {
			angle2 -= 2 * PI;
			swap(angle1, angle2);
			events.pb(mp(angle1, mp(ADD, i)));
			events.pb(mp(angle2, mp(DEL, i)));
			events.pb(mp(angle1 + 2 * PI, mp(ADD, i)));
		} else {
			events.pb(mp(angle1, mp(ADD, i)));
			events.pb(mp(angle2, mp(DEL, i)));
		}
	}
	sort(all(events));
	int m = sz(events);
	tSize = 1;
	while(tSize < m) {
		tSize *= 2;
	}
	forn(i, 2 * tSize) tree[i] = 0;
	ll res = 0;
	forn(i, m) {
	//	cout << events[i].fst << " " << events[i].snd.fst << " " << events[i].snd.snd << '\n';
		int ind = events[i].snd.snd;
		int t = events[i].snd.fst;
		if (t == ADD) {
			setPos(i, 1);
			lastPos[ind] = i;
		} else {
			setPos(lastPos[ind], 0);
			res += getSum(1, 0, tSize, lastPos[ind], i);
	//		cout << "res = " << res << '\n';
		}
	}
	ll total = n * 1ll * (n - 1) / 2;
	return total - res;
}
  
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
 
/*	Pnt p(-4, 0);
	c.r = 3.;
	Pnt res = tangent(p, c, 1);
	cout << res.angle() << '\n';*/
 
	int n;
	ll k;
	cin >> n >> k;
	forn(i, n) {
		p[i].read();
	}
	
	dbl l = 0, r = 1e5;
	forn(i, REPS) {
		dbl R = (l + r) / 2;
		if (cnt(R, n) < k) {
			l = R;
		} else {
			r = R;
		}
	}
	cout.precision(20);
	cout << fixed << l << '\n';
	return 0;
}