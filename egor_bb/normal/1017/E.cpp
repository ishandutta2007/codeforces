#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long LL;
typedef unsigned long long ull;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const dbl EPS = 1e-9;
const int PREC = 20;
inline bool eq(dbl a, dbl b){ return abs(a-b)<=EPS; }
inline bool gr(dbl a, dbl b){ return a>b+EPS; }
inline bool geq(dbl a, dbl b){ return a>=b-EPS; }
inline bool ls(dbl a, dbl b){ return a<b-EPS; }
inline bool leq(dbl a, dbl b){ return a<=b+EPS; }

struct Pnt{
    dbl x,y;
    Pnt():x(0),y(0){}
    Pnt(dbl _x,dbl _y):x(_x),y(_y){}

    inline Pnt operator +(const Pnt &B) const{ return Pnt(x+B.x, y+B.y); }
    inline Pnt operator -(const Pnt &B) const{ return Pnt(x-B.x, y-B.y); }
    inline dbl operator *(const Pnt &B) const{ return x*B.x + y*B.y; } // LL
    inline dbl operator %(const Pnt &B) const{ return x*B.y - y*B.x; } // LL

    inline Pnt operator *(dbl k) const{ return Pnt(x*k, y*k); }
    inline Pnt operator /(dbl k) const{ return Pnt(x/k, y/k); }
    inline Pnt operator -() const{ return Pnt(-x, -y); }

    inline void operator +=(const Pnt &B){ x+=B.x, y+=B.y; }
    inline void operator -=(const Pnt &B){ x-=B.x, y-=B.y; }
    inline void operator *=(dbl k){ x*=k, y*=k; }

    inline bool operator ==(const Pnt &B){ return abs(x-B.x)<=EPS && abs(y-B.y)<=EPS; }
    inline bool operator !=(const Pnt &B){ return abs(x-B.x)>EPS || abs(y-B.y)>EPS; }
    inline bool operator <(const Pnt &B){ return abs(x-B.x)<=EPS ? y<B.y-EPS : x<B.x; }

    inline dbl angle() const{ return atan2(y, x); } // LD
    inline dbl len2() const{ return x*x+y*y; } // LL
    inline dbl len() const{ return sqrt(x*x+y*y); } // LL, LD
    inline Pnt getNorm() const{
        auto l = len();
        return Pnt(x/l, y/l);
    }
    inline void normalize(){
        auto l = len();
        x/=l, y/=l;
    }

    inline Pnt getRot90() const{ //counter-clockwise
        return Pnt(-y, x);
    }
    inline Pnt getRot(dbl a) const{ // LD
        dbl si = sin(a), co = cos(a);
        return Pnt(x*co - y*si, x*si + y*co);
    }

    inline void read(){
        int _x,_y;
        scanf("%d%d",&_x,&_y);
        x=_x, y=_y;
    }
    inline void write() const{
        printf("%.*f %.*f ", PREC, (double)x, PREC, (double)y);
    }
};

struct Line{
    dbl a, b, c;
    Line():a(0),b(0),c(0){}
    Line(dbl _a, dbl _b, dbl _c):a(_a),b(_b),c(_c){}

    Line(const Pnt &A, const Pnt &B){ // it normalizes (a,b), important in d(), normalToP()
        Pnt n = (B-A).getRot90().getNorm();
        a = n.x, b = n.y, c = -(a*A.x + b*A.y);
    }

    inline dbl d(const Pnt &p) const{ return a*p.x + b*p.y + c; }
    inline Pnt no() const {return Pnt(a, b);}
    inline Pnt normalToP(const Pnt &p) const{ return Pnt(a,b) * (a*p.x + b*p.y + c); }

    inline void write() const{
        printf("%.*f %.*f %.*f ", PREC, (double)a, PREC, (double)b, PREC, (double)c);
    }
};

typedef vector<Pnt> vpnt;

inline bool byAngle(const Pnt &a, const Pnt &b){
	dbl x = a % b;
	return eq(x, 0) ? a.len2() < b.len2() : x < 0;
}

vpnt convexHull(vpnt p){
	int n = sz(p);
	assert(n > 0);
	swap(p[0], *min_element(all(p)));
	forab(i, 1, n)
	p[i] = p[i] - p[0];
	sort(p.begin() + 1, p.end(), byAngle);

/*	    ,  (1)  (2)
	(1):
	int k = p.size() - 1;
	while(k > 0 && eq((p[k - 1] - p.back()) % p.back(), 0))
		--k;
	reverse(pi.begin() + k, pi.end());*/

	int rn = 0;
	vpnt r(n);
	r[rn++] = p[0];
	forab(i, 1, n){
		Pnt q = p[i] + p[0];
		while(rn >= 2 && geq((r[rn - 1] - r[rn - 2]) % (q - r[rn - 2]), 0)) // (2) ge
			--rn;
		r[rn++] = q;
	}
	r.resize(rn);
	return r;
}

vpnt s1, s2;
vector<pair<dbl, pair<dbl, dbl>>> sh1, sh2, sh;

void finish() {
	puts("NO");
	exit(0);
}


const int N = 1e5  +100;

int pr[4 * N];

bool eqeq(pair<dbl, pair<dbl, dbl>> a, pair<dbl, pair<dbl, dbl>> b) {
	return eq(a.fst, b.fst) && eq(a.snd.fst, b.snd.fst) && eq(a.snd.snd, b.snd.snd);
}

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	s1.resize(n);
	s2.resize(m);
	forn(i, n) s1[i].read();
	forn(i, m) s2[i].read();
	vpnt c1 = convexHull(s1);
	vpnt c2 = convexHull(s2);
	if (sz(c1) != sz(c2)) finish();
	forn(i, sz(c1)) {
		int nxt = (i + 1) % sz(c1);
		int lst = i - 1;
		if (lst < 0) lst += sz(c1);
		Pnt diff1 = c1[nxt] - c1[i];
		Pnt diff2 = c1[i] - c1[lst];
		sh1.pb(mp(diff1.len2(), mp((diff1 % diff2), diff1 * diff2))); 
	}
	forn(i, sz(c2)) {
		int nxt = (i + 1) % sz(c2);
		int lst = i - 1;
		if (lst < 0) lst += sz(c2);
		Pnt diff1 = c2[nxt] - c2[i];
		Pnt diff2 = c2[i] - c2[lst];
		sh2.pb(mp(diff1.len2(), mp((diff1 % diff2), diff1 * diff2))); 
	}
	forn(i, sz(c1)) sh.pb(sh1[i]);
	sh.pb(mp(0, mp(0, 0)));
	forn(i, sz(c2)) sh.pb(sh2[i]);
	forn(i, sz(c2)) sh.pb(sh2[i]);
	int k = 0;
	pr[0] = pr[1] = 0;
	for (int i = 2; i <= sz(c1) * 3 + 1; i++) {
		k = pr[i - 1];
		while (k && !eqeq(sh[k], sh[i - 1]))
			k = pr[k];
		if (eqeq(sh[k], sh[i - 1]))
			k++;
		pr[i] = k;
	}
	forn(i, sz(c1) * 3 + 2) {
		if (pr[i] == sz(c1)) {
			puts("YES");
			return 0;
		}
	}
	finish();
	return 0;
}