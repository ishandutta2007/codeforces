#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    Point(T x=0, T y=0) : x(x), y(y) {}
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
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

#define sz size
typedef Point<double> P;
vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p : pts) {
            while (t >= h.size() || t >= s + 2 && h[t-2].cross(h[t-1], p) < 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

double segDist(P& s, P& e, P& p) {
    if (s==e) return (p-s).dist();
    auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}

vector<P> w, v;
ll n, S;

bool chk2(int i, int j, int k) {
    int k1 = k == 0 ? n-1 : k-1;
    int k2 = k == n-1 ? 0 : k+1;
    return v[k1].cross(v[k], v[k]+v[i]-v[j]) >= 0 
    && (v[k]+v[j]-v[i]).cross(v[k], v[k2]) >= 0;
}

void pr(P a) {cout << ll(a.x) << " " << ll(a.y) << "\n";}

void chk(int i, int j, int k) {
    if (chk2(j, k, i) && chk2(i, j, k) && chk2(k, i, j)) {
        pr(v[i]+v[j]-v[k]);
        pr(v[j]+v[k]-v[i]);
        pr(v[k]+v[i]-v[j]);
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> S;
    w.resize(n);
    for (auto& p : w) {
        ll x, y; cin >> x >> y;
        p.x = x, p.y = y;
    }
    v = convexHull(w); n = v.size();
    for (int i = 0; i < n; i++) {
        int k = (i+2)%n;
        for (int j = (i+1)%n; j != (i+n-1)%n; j = (j+1)%n) {
            while (k != i && segDist(v[i], v[j], v[(k+1)%n]) > segDist(v[i], v[j], v[k]))
                k = (k+1)%n;
            chk(i, j, k);
        }
    }
}