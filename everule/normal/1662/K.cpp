#ifndef LOCAL
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

#include "bits/stdc++.h"

#ifdef DEBUG
    #include "includes/debug/debug.hpp"
#else
    #define debug(...) 0
#endif

using ll = int64_t;
using ull = uint64_t;
using ld = long double;

using namespace std;

template <typename T>
struct Point {
   public:
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x_, T y_) : x(x_), y(y_) {}
    template <typename U>
    explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
    Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
    Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
    explicit operator std::pair<T, T>() const { return std::pair<T, T>(x, y); }
    explicit operator std::complex<T>() const { return std::complex<T>(x, y); }

    friend std::ostream& operator<<(std::ostream& o, const Point& p) {
        return o << '(' << p.x << ',' << p.y << ')';
    }
    friend std::istream& operator>>(std::istream& i, Point& p) {
        return i >> p.x >> p.y;
    }
    friend bool operator==(const Point& a, const Point& b) {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator!=(const Point& a, const Point& b) { return !(a == b); }

    Point& operator+=(const Point& p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point& operator-=(const Point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    Point& operator*=(const T& t) {
        x *= t, y *= t;
        return *this;
    }
    Point& operator/=(const T& t) {
        x /= t, y /= t;
        return *this;
    }

    friend Point operator+(const Point& a, const Point& b) {
        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator-(const Point& a, const Point& b) {
        return Point(a.x - b.x, a.y - b.y);
    }
    friend Point operator*(const Point& a, const T& t) {
        return Point(a.x * t, a.y * t);
    }
    friend Point operator*(const T& t, const Point& a) {
        return Point(t * a.x, t * a.y);
    }
    friend Point operator/(const Point& a, const T& t) {
        return Point(a.x / t, a.y / t);
    }

    friend T norm(const Point& a) { return a.x * a.x + a.y * a.y; }
    friend auto abs(const Point& p) { return std::hypot(p.x, p.y); }
    friend T unit(const Point& a) {
        if (a == Point()) return a;
        return a / abs(a);
    }

    friend T int_norm(const Point& a) { return __gcd(a.x, a.y); }
    friend T int_unit(const Point& a) {
        if (a == Point()) return a;
        return a / int_norm(a);
    }

    friend T cross(const Point& a, const Point& b) {
        return a.x * b.y - a.y * b.x;
    }
    friend T dot(const Point& a, const Point& b) {
        return a.x * b.x + a.y * b.y;
    }
    friend T area(const Point& a, const Point& b, const Point& c) {
        return cross(b - a, c - a);
    }

    // Returns conj(a) * b
    friend Point rotation(const Point& a, const Point& b) {
        return Point(dot(a, b), cross(a, b));
    }

    Point conj() const { return {x, -y}; }

    friend Point rotate_by(const Point& a, const Point& b) {
        return rotation(a.conj(), b);
    }

    friend bool same_dir(const Point& a, const Point& b) {
        return cross(a, b) == 0 && dot(a, b) > 0;
    }

    // check if 180 <= s..t < 360
    friend bool is_reflex(const Point& a, const Point& b) {
        auto c = cross(a, b);
        return c ? (c < 0) : (dot(a, b) < 0);
    }

    // operator < (s,t) for angles in [base,base+2pi)
    friend bool angle_less(const Point& base, const Point& s, const Point& t) {
        int r = is_reflex(base, s) - is_reflex(base, t);
        return r ? (r < 0) : (0 < cross(s, t));
    }

    friend auto angle_cmp(const Point& base) {
        return [base](const Point& s, const Point& t) {
            return angle_less(base, s, t);
        };
    }
    friend auto angle_cmp_center(const Point& center, const Point& dir) {
        return [center, dir](const Point& s, const Point& t) -> bool {
            return angle_less(dir, s - center, t - center);
        };
    }

    // is p in [s,t] taken ccw? 1/0/-1 for in/border/out
    friend int angle_between(const Point& s, const Point& t, const Point& p) {
        if (same_dir(p, s) || same_dir(p, t)) return 0;
        return angle_less(s, p, t) ? 1 : -1;
    }

    friend ld costheta(const Point& a, const Point& b) {
        return dot(a, b) / (abs(a) * abs(b));
    }
};

// Assumes there exists p, q in [low, high] such that
// f is decreasing in [low, p],
// f is constant in [p, q]
// f is increasing in [q, high]
// Returns a point in [p , q]
// O(repeat) f() calls
template <class Compare = less<>>
ld golden_section_search(ld low, ld high, int repeat, auto f,
                         Compare cmp = less<>()) {
    using T = ld;
    assert(low < high);
    ld phi = (sqrtl(5) - 1) / 2;
    T mid1 = high - (high - low) * phi, mid2 = low + (high - low) * phi;
    auto val1 = f(mid1), val2 = f(mid2);
    while (repeat--) {
        if (cmp(val1, val2)) {
            high = mid2, mid2 = mid1, val2 = val1;
            mid1 = high - (high - low) * phi, val1 = f(mid1);
        } else {
            low = mid1, mid1 = mid2, val1 = val2;
            mid2 = low + (high - low) * phi, val2 = f(mid2);
        }
    }
    return (low + high) / 2;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int _tests = 1;
    // cin >> _tests;
    for (int _test = 1; _test <= _tests; ++_test) {
        // cout << "Case #" << _test << ": ";
        using point = Point<ld>;
        array<point, 3> points;
        for (auto& p : points) cin >> p;
        if (cross(points[1] - points[0], points[2] - points[0]) < 0)
            swap(points[1], points[2]);
        array<point, 3> fermat{};
        array<point, 3> fermat_2{};
        constexpr ld pi = numbers::pi_v<ld>;
        const point rot = {cos(-pi / 3), sin(-pi / 3)};
        for (int i = 0; i < 3; ++i) {
            fermat[i] =
                rotate_by(points[(i + 2) % 3] - points[(i + 1) % 3], rot) +
                points[(i + 1) % 3];
            fermat_2[i] = points[(i + 1) % 3] + points[(i + 2) % 3] - fermat[i];
        }
        ld ans = 1e18L;
        auto eval = [&](point p) {
            ld sum = 0;
            for (int i = 0; i < 3; ++i) {
                auto p1 = points[(i + 1) % 3];
                auto p2 = points[(i + 2) % 3];
                if (costheta(p1 - p, p2 - p) < -0.5)
                    sum = max(sum, abs(p1 - p) + abs(p2 - p));
                else if (costheta(p2 - p1, p - p1) < -0.5)
                    sum = max(sum, abs(p2 - p1) + abs(p - p1));
                else if (costheta(p1 - p2, p - p2) < -0.5)
                    sum = max(sum, abs(p1 - p2) + abs(p - p2));
                else
                    sum = max({sum, abs(fermat[i] - p), abs(fermat_2[i] - p)});
            }
            return sum;
        };

        auto solve = [&](point a, point b) {
            point mid = (a + b) / 2;
            point rot = rotate_by(a - mid, point{0, 1});
            auto cur =
                eval(mid + golden_section_search(-1e9, 1e9, 500, [&](ld x) {
                               return eval(mid + rot * x);
                           }) * rot);
            ans = min(ans, cur);
        };

        for (int i = 0; i < 3; ++i) solve(points[i], points[(i + 1) % 3]);
        for (int i = 0; i < 3; ++i) solve(fermat[i], fermat[i + 1]);
        cout << ans << '\n';
    }
}