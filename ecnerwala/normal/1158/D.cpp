#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x_=0, T y_=0) : x(x_), y(y_) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

using ll = long long;
using P = Point<ll>;
template <class P>
bool sameDir(P s, P t) {
	return s.cross(t) == 0 && s.dot(t) > 0;
}
// checks 180 <= s..t < 360?
template <class P>
bool isReflex(P s, P t) {
	auto c = s.cross(t);
	return c ? (c < 0) : (s.dot(t) < 0);
}
// operator < (s,t) for angles in [base,base+2pi)
template <class P>
bool angleCmp(P base, P s, P t) {
	int r = isReflex(base, s) - isReflex(base, t);
	return r ? (r < 0) : (0 < s.cross(t));
}
// is x in [s,t] taken ccw? 1/0/-1 for in/border/out
template <class P>
int angleBetween(P s, P t, P x) {
	if (sameDir(x, s) || sameDir(x, t)) return 0;
	return angleCmp(s, x, t) ? 1 : -1;
}

using vi = vector<int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for (auto& a : x)
pair<vi, vi> ulHull(const vector<P>& S) {
	vi Q(sz(S)), U, L;
	iota(all(Q), 0);                                                                                                                                                                         
	sort(all(Q), [&S](int a, int b){ return S[a] < S[b]; }); 
	trav(it, Q) {
#define ADDP(C, cmp) while (sz(C) > 1 && S[C[sz(C)-2]].cross(\
	S[it], S[C.back()]) cmp 0) C.pop_back(); C.push_back(it);
		ADDP(U, <=); ADDP(L, >=);
#undef ADDP
	}   
	return {U, L}; 
}

vi convexHull(const vector<P>& S) {
	vi u, l; tie(u, l) = ulHull(S);
	if (sz(S) <= 1) return u;
	if (S[u[0]] == S[u[1]]) return {0};
	l.insert(l.end(), u.rbegin()+1, u.rend()-1);
	return l;
}

const int MAXN = 3000;
int N;
P pts[MAXN];
char S[MAXN];
bool used[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> pts[i].x >> pts[i].y;
	cin >> S;

	vector<int> hull = convexHull(vector<P>(pts, pts + N));
	int i = hull[0], j = hull[1];
	if (S[0] == 'R') {
		swap(i, j);
	}
	vector<int> res;
	res.push_back(i);
	res.push_back(j);
	used[i] = true;
	used[j] = true;
	for (int z = 1; z <= N-2; z++) {
		vector<int> cnds;
		for (int k = 0; k < N; k++) if (!used[k]) cnds.push_back(k);
		int k = cnds.back(); cnds.pop_back();
		for (int cnd : cnds) {
			bool cndCmpK = angleCmp(pts[i] - pts[j], pts[cnd] - pts[j], pts[k] - pts[j]);
			assert(z < N-2);
			if (S[z] == 'R') {
				// take the leftmost
				if (!cndCmpK) {
					k = cnd;
				}
			} else if (S[z] == 'L') {
				// take the rightmost
				if (cndCmpK) {
					k = cnd;
				}
			} else assert(false);
		}
		res.push_back(k);
		used[k] = true;
		i = j;
		j = k;
	}
	for (int z = 0; z < N; z++) {
		cout << res[z]+1 << " \n"[z+1==N];
	}

	return 0;
}