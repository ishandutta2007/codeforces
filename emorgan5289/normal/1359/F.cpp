#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

typedef long double ld;
const ld PI = acos(-1);
const ld EPS = 1e-12;

template<typename T>
struct point {

    T x, y;

    point(T _x, T _y) : x(_x), y(_y) {}
    point() : point(0, 0) {}
    template<typename U> point(point<U> a) : point(a.x, a.y) {}

    template<typename U> using c_t = decltype(T()+U());
    
    friend string to_string(const point a) { return "("+to_string(a.x)+", "+to_string(a.y)+")"; }
    friend istream& operator>>(istream& i, point& a) { return i >> a.x >> a.y; }
    friend ostream& operator<<(ostream& o, const point a) { return o << "(" << a.x << ", " << a.y << ")"; }

    template<typename U> point& operator*=(const U r) { x *= r, y *= r; return *this; }
    template<typename U> point& operator/=(const U r) { x /= r, y /= r; return *this; }
    point& operator+=(const point a) { x += a.x, y += a.y; return *this; }
    point& operator-=(const point a) { x -= a.x, y -= a.y; return *this; }
    point operator+() { return *this; }
    point operator-() { return *this * -1; }

    template<typename U> friend point<c_t<U>> operator+(point a, point<U> b) { return {a.x+b.x, a.y+b.y}; }
    template<typename U> friend point<c_t<U>> operator-(point a,  point<U> b) { return {a.x-b.x, a.y-b.y}; }
    template<typename U> friend point<c_t<U>> operator*(const point a, const U r) { return {a.x*r, a.y*r}; }
    template<typename U> friend point<c_t<U>> operator*(const U r, const point a) { return {a.x*r, a.y*r}; }
    template<typename U> friend point<c_t<U>> operator/(const point a, const U r) { return {a.x/r, a.y/r}; }
    
    template<size_t i> T get() { return i ? y : x; }

    template<typename U> friend bool operator==(const point a, const point<U> b) { return a.x == b.x && a.y == b.y; }
    template<typename U> friend bool operator!=(const point a, const point<U> b) { return a.x != b.x || a.y != b.y; }
    template<typename U> friend bool operator<(const point a, const point<U> b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    template<typename U> friend bool operator<=(const point a, const point<U> b) { return a.x == b.x ? a.y <= b.y : a.x < b.x; }
    template<typename U> friend bool operator>(const point a, const point<U> b) { return b < a; }
    template<typename U> friend bool operator>=(const point a, const point<U> b) { return b <= a; }
};

template<typename T>
T sqdist(point<T> a) { return a.x*a.x + a.y*a.y; }
template<typename T, typename U>
auto sqdist(point<T> a, point<U> b) { return sqdist(a-b); }
ld dist(point<ld> a) { return hypot(a.x, a.y); }
ld dist(point<ld> a, point<ld> b) { return dist(a-b); }
ld atan2(point<ld> a) { return atan2(a.y, a.x); }

template<typename T, typename U>
auto dot(point<T> a, point<U> b) { return a.x*b.x + a.y*b.y; }
template<typename T, typename U>
auto cross(point<T> a, point<U> b) { return a.x*b.y - a.y*b.x; }

// returns positive if ABC turns left, negative if turns right, 0 if collinear
template<typename T, typename U, typename V>
auto cross(point<T> a, point<U> b, point<V> c) { return cross(b-a, c-a); }

// returns the projection of A to line BC
point<ld> proj(point<ld> a, point<ld> b, point<ld> c) {
    return dot(a-b, c-b)/sqdist(c-b)*(c-b)+b;
}

// returns A rotated about the origin by t radians CCW
point<ld> rot(point<ld> a, ld t) {
    return {a.x*cos(t)-a.y*sin(t), a.y*cos(t)+a.x*sin(t)};
}

// returns A rotated about B by t radians CCW
point<ld> rot(point<ld> a, point<ld> b, ld t) {
    return rot(a-b, t)+b;
}

// returns the point of intersection of lines AB and CD
point<ld> intersection(point<ld> a, point<ld> b, point<ld> c, point<ld> d) {
    return cross(a-c, b-a)/cross(d-c, b-a)*(d-c)+c;
}

// returns true if segments AB and CD intersect
// works for integers only, up to 10^9 for ll
template<typename T, bool endpoints_ok = true>
bool intersects(point<T> a, point<T> b, point<T> c, point<T> d) {
    auto s_n = cross(a-c, b-a), s_d = cross(d-c, b-a);
    auto t_n = cross(c-a, d-c), t_d = cross(b-a, d-c);
    if constexpr (endpoints_ok)
        return (s_n <= 0 && s_d < 0 || s_n >= 0 && s_d > 0) && abs(s_n) <= abs(s_d) 
            && (t_n <= 0 && t_d < 0 || t_n >= 0 && t_d > 0) && abs(t_n) <= abs(t_d);
    else
        return (s_n < 0 && s_d < 0 || s_n > 0 && s_d > 0) && abs(s_n) < abs(s_d) 
            && (t_n < 0 && t_d < 0 || t_n > 0 && t_d > 0) && abs(t_n) < abs(t_d);
}

// helper for intersects below
int _vec(const point<ld>& a, const point<ld>& b, const point<ld>& c) {
    ld s = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    return abs(s) < EPS ? 0 : s > 0 ? 1 : -1;
}

// returns true if segments AB and CD intersect
// works for floats only, with EPS defined above
bool intersects(point<ld> a, point<ld> b, point<ld> c, point<ld> d) {
    debug(a, b, c, d);
    debug(_vec(a, b, c), _vec(a, b, d));
    debug(_vec(c, d, a), _vec(c, d, b));
    return min(a.x, b.x) <= max(c.x, d.x)+EPS && min(c.x, d.x) <= max(a.x, b.x)+EPS
        && min(a.y, b.y) <= max(c.y, d.y)+EPS && min(c.y, d.y) <= max(a.y, b.y)+EPS
        && _vec(a, b, c)*_vec(a, b, d) <= 0
        && _vec(c, d, a)*_vec(c, d, b) <= 0;
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

// returns the circumcenter of triangle ABC
point<ld> circumcenter(point<ld> a, point<ld> b, point<ld> c) {
    point<ld> x = (a+b)/2, y = (a+c)/2;
    return intersection(x, x+rot(b-a, PI/2), y, y+rot(c-a, PI/2));
}

// returns double the signed area of a simple polygon (positive if CCW, negative if CW)
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

// #include "../../../geodeb/lib/geodeb.h"

bool has_intersection(vector<array<point<ld>, 2>> a) {
    // GD_LAYER();
    // for (auto& [p, q] : a)
    //     GD_SEGMENT(p.x, p.y, q.x, q.y, "black");
    // GD_PAUSE();
    auto get_y = [&](int i, ld x) {
        if (abs(a[i][0].x-a[i][1].x) < EPS)
            return a[i][0].y;
        return a[i][0].y + (a[i][1].y-a[i][0].y) * (x-a[i][0].x) / (a[i][1].x-a[i][0].x);
    };
    auto cmp = [&](int i, int j) {
        ld x = max(min(a[i][0].x, a[i][1].x), min(a[j][0].x, a[j][1].x));
        return get_y(i, x) < get_y(j, x)-EPS;
    };
    multiset<int, decltype(cmp)> s(cmp);
    multiset<tuple<point<ld>, int, bool>> m;
    for (int i = 0; i < a.size(); i++) {
        if (a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
        m.insert({a[i][0], i, 0});
        m.insert({a[i][1], i, 1});
    }
    for (auto& [_, i, t] : m) {
        if (t) {
            // GD_SEGMENT(a[i][0].x, a[i][0].y, a[i][1].x, a[i][1].y, "black");
            auto it = s.find(i);
            if (it == s.begin() || it == --s.end()) {
                s.erase(it);
                continue;
            }
            auto l = it; l--;
            auto r = it; r++;
            // GD_LAYER();
            // GD_SEGMENT(a[*r][0].x, a[*r][0].y, a[*r][1].x, a[*r][1].y, "red");
            // GD_SEGMENT(a[*l][0].x, a[*l][0].y, a[*l][1].x, a[*l][1].y, "red");
            if (intersects(a[*l][0], a[*l][1], a[*r][0], a[*r][1]))
                return 1;
            s.erase(it);
        } else {
            // GD_SEGMENT(a[i][0].x, a[i][0].y, a[i][1].x, a[i][1].y, "blue");
            auto it = s.insert(i);
            debug(i, s);
            if (it != s.begin()) {
                auto l = it; l--;
                int j = *l;
                // GD_LAYER();
                // GD_SEGMENT(a[i][0].x, a[i][0].y, a[i][1].x, a[i][1].y, "red");
                // GD_SEGMENT(a[j][0].x, a[j][0].y, a[j][1].x, a[j][1].y, "red");
                if (intersects(a[j][0], a[j][1], a[i][0], a[i][1]))
                    return 1;
            }
            if (it != --s.end()) {
                auto r = it; r++;
                int j = *r;
                // GD_LAYER();
                // GD_SEGMENT(a[i][0].x, a[i][0].y, a[i][1].x, a[i][1].y, "red");
                // GD_SEGMENT(a[j][0].x, a[j][0].y, a[j][1].x, a[j][1].y, "red");
                if (intersects(a[j][0], a[j][1], a[i][0], a[i][1]))
                    return 1;
            }
        }
    }
    // for (auto& [p, q] : a)
    //     GD_SEGMENT(p.x, p.y, q.x, q.y, "green");
    // GD_PAUSE();
    return 0;
}

int main() {
    // GD_INIT("../../output.html");
    cerr << setprecision(30) << fixed;
    cout << setprecision(30) << fixed;
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<point<ld>> a(n), d(n);
    for (int i = 0; i < n; i++) {
        ll s;
        cin >> a[i] >> d[i] >> s;
        d[i] *= s/dist(d[i]);
    }
    ld ans = 1e10;
    for (ld x = 1e10; x > 1e-8; x /= 2) {
        if (ans-x < 1e-7) continue;
        vector<array<point<ld>, 2>> b;
        for (int i = 0; i < n; i++)
            b.pb({a[i], a[i]+d[i]*(ans-x)});
        if (has_intersection(b)) {
            debug(x, ans);
            ans -= x;
        } else {
            debug(x);
        }
    }
    vector<array<point<ld>, 2>> b;
    for (int i = 0; i < n; i++)
        b.pb({a[i], a[i]+d[i]*(ans)});
    if (!has_intersection(b)) {
        cout << "No show :(\n";
        return 0;
    }
    cout << ans << "\n";
}