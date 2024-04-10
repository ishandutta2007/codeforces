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

typedef long double ld;
template<typename T, typename U> using c_t = decltype(T()+U());

template<typename T>
struct point {

    T x, y;

    point(T _x, T _y) : x(_x), y(_y) {}
    point() : point(0, 0) {}
    template<typename U> point(point<U> a) : point(a.x, a.y) {}
    
    friend string to_string(const point a) { return "("+to_string(a.x)+", "+to_string(a.y)+")"; }
    friend istream& operator>>(istream& i, point& a) { return i >> a.x >> a.y; }
    friend ostream& operator<<(ostream& o, const point a) { return o << "(" << a.x << ", " << a.y << ")"; }

    point& operator+=(const point a) { x += a.x, y += a.y; return *this; }
    point& operator-=(const point a) { x -= a.x, y -= a.y; return *this; }
    template<typename U> point& operator*=(const U r) { x *= r, y *= r; return *this; }
    template<typename U> point& operator/=(const U r) { x /= r, y /= r; return *this; }

    template<typename U> friend point<c_t<T, U>> operator+(point a, point<U> b) { return {a.x+b.x, a.y+b.y}; }
    template<typename U> friend point<c_t<T, U>> operator-(point a,  point<U> b) { return {a.x-b.x, a.y-b.y}; }
    template<typename U> friend point<c_t<T, U>> operator*(const point a, const U r) { return {a.x*r, a.y*r}; }
    template<typename U> friend point<c_t<T, U>> operator*(const U r, const point a) { return {a.x*r, a.y*r}; }
    template<typename U> friend point<c_t<T, U>> operator/(const point a, const U r) { return {a.x/r, a.y/r}; }
    
    template<size_t i> T get() { return i ? y : x; }

    template<typename U> friend bool operator==(const point a, const point b) { return a.x == b.x && a.y == b.y; }
    template<typename U> friend bool operator<(const point a, const point<U> b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    template<typename U> friend bool operator<=(const point a, const point<U> b) { return a.x == b.x ? a.y <= b.y : a.x < b.x; }
    template<typename U> friend bool operator>(const point a, const point<U> b) { return b < a; }
    template<typename U> friend bool operator>=(const point a, const point<U> b) { return b <= a; }
};

template<typename T> T sqdist(point<T> a) { return a.x*a.x + a.y*a.y; }
template<typename T, typename U>
c_t<T, U> sqdist(point<T> a, point<U> b) { return sqdist(a-b); }
ld dist(point<ld> a) { return hypot(a.x, a.y); }
ld dist(point<ld> a, point<ld> b) { return dist(a-b); }
template<typename T, typename U>
c_t<T, U> dot(point<T> a, point<U> b) { return a.x*b.x + a.y*b.y; }
template<typename T, typename U>
c_t<T, U> cross(point<T> a, point<U> b) { return a.x*b.y - a.y*b.x; }

// returns the projection of A to line BC
point<ld> proj(point<ld> a, point<ld> b, point<ld> c) {
    return dot(a-b, c-b)/sqdist(c-b)*(c-b)+b;
}

// returns the point of intersection of lines AB and CD
point<ld> intersection(point<ld> a, point<ld> b, point<ld> c, point<ld> d) {
    ld s = cross(a-c, b-a)/ld(cross(d-c, b-a));
    return s*d + (1-s)*c;
}

// returns true if lines AB and CD intersect
bool intersects(point<ld> a, point<ld> b, point<ld> c, point<ld> d) {
    ld s = cross(a-c, b-a)/ld(cross(d-c, b-a)), t = cross(c-a, d-c)/ld(cross(b-a, d-c));
    return t >= 0 && t <= 1 && s >= 0 && s <= 1;
}

// returns the distance from A to *segment* BC
ld dist(point<ld> a, point<ld> b, point<ld> c) {
    return dist(min(ld(1), max(ld(0), dot(a-b, c-b)/sqdist(c-b)))*(c-b)+b-a);
}

// returns the distance from *segment* AB to *segment* CD
ld dist(point<ld> a, point<ld> b, point<ld> c, point<ld> d) {
    if (intersects(a, b, c, d)) return 0;
    return min(min(dist(a, c, d), dist(b, c, d)), min(dist(c, a, b), dist(d, a, c)));
}

// returns double the signed area of a simple polygon (positive if CW, negative if CCW)
template<typename T>
T area(vector<point<T>> v) {
    T out = cross(v.back(), v[0]);
    for (int i = 0; i < v.size()-1; i++) out += cross(v[i], v[i+1]);
    return out;
}

// returns whether A is contained within a simple polygon
template<typename T>
bool contains(vector<point<T>> v, point<T> a) {
    bool out = 0;
    for (int i = 0; i < v.size(); i++) {
        auto b = v[i], c = v[(i+1)%v.size()];
        if (b.y > c.y) swap(b, c);
        if (b.y <= a.y && a.y < c.y && cross(b-a, c-a) > 0) out ^= 1;
    }
    return out;
}

const int N = 4e5+5;
ld l[N], r[N], p[N];
point<ld> x[N];

ld interval(ld left, ld right, int u) {
    return max(ld(0), min(right, r[u])-max(left, l[u]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    point<ld> a, b;
    ll s, n; cin >> s >> a.x >> b.x >> n;
    a.y = b.y = s;
    for (int i = 0; i < n; i++) {
        int _l, _r; cin >> _l >> _r;
        l[i] = _l, r[i] = _r;
        p[i] = (i == 0 ? 0 : p[i-1]) + r[i]-l[i];
    }
    ll q; cin >> q;
    cout << setprecision(25) << fixed;
    for (int i = 0; i < q; i++) {
        cin >> x[i];
        ld left = intersection(a, x[i], {-2e9, 0}, {2e9, 0}).x;
        ld right = intersection(b, x[i], {-2e9, 0}, {2e9, 0}).x;
        int u = lower_bound(r, r+n, left)-r;
        int v = upper_bound(l, l+n, right)-l-1;
        if (u == v)
            cout << interval(left, right, u)/ld(right-left)*(b.x-a.x) << "\n";
        else if (u < v)
            cout << (p[v-1]-p[u]+interval(left, right, u)+interval(left, right, v))/ld(right-left)*(b.x-a.x) << "\n";
        else
            cout << 0. << "\n";
    }
}