// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;

template<typename TI, typename TF>
class generic_point {
public:
    TI x, y;

    generic_point() = default;

    generic_point(TI _x, TI _y) : x(_x), y(_y) {}

    generic_point<TI, TF> operator+(const generic_point<TI, TF>& other) const {
        return generic_point<TI, TF>(x + other.x, y + other.y);
    }

    generic_point<TI, TF> operator-(const generic_point<TI, TF>& other) const {
        return generic_point<TI, TF>(x - other.x, y - other.y);
    }

    generic_point<TI, TF> operator+() const {
        return *this;
    }

    generic_point<TI, TF> operator-() const {
        return generic_point<TI, TF>(-x, -y);
    }

    generic_point<TI, TF> operator*(TI k) const {
        return generic_point<TI, TF>(x * k, y * k);
    }

    template<typename T = TI>
    typename std::enable_if<std::is_floating_point<T>::value, generic_point<TI, TF>>::type
    operator/(TF k) const {
        return generic_point<TI, TF>(x / k, y / k);
    }

    TI operator*(const generic_point<TI, TF>& other) const {
        return x * other.x + y * other.y;
    }

    TI operator%(const generic_point<TI, TF>& other) const {
        return x * other.y - y * other.x;
    }

    TI lenSqr() const {
        return x * x + y * y;
    }

    TF len() const {
        return sqrt(lenSqr());
    }

    TI distSqr(const generic_point<TI, TF>& other) const {
        return (other - *this).lenSqr();
    }

    TF dist(const generic_point<TI, TF>& other) const {
        return sqrt(distSqr(other));
    }

    generic_point<TI, TF> norm() const {
        return *this / len();
    }

    // Counterclockwise rotation by 90 degrees
    generic_point<TI, TF> ort() const {
        return generic_point<TI, TF>(-y, x);
    }

    // Counterclockwise rotation by c = cos(alpha), s = sin(alpha)
    template<typename T = TI>
    typename std::enable_if<std::is_floating_point<T>::value, generic_point<TI, TF>>::type
    rot(TF c, TF s) const {
        return *this * c + ort() * s;
    }

    // Counterclockwise rotation by alpha
    generic_point<TI, TF> rot(TF alpha) const {
        return rot(cos(alpha), sin(alpha));
    }

    TF arg() const {
        return atan2(y, x);
    }

    int quad() const {
        if (x >= 0 && y >= 0) {
            return 1;
        } else if (x < 0 && y >= 0) {
            return 2;
        } else if (x < 0 && y < 0) {
            return 3;
        } else if (x >= 0 && y < 0) {
            return 4;
        }
        throw;
    }

    template<typename T = TI>
    typename std::enable_if<std::is_floating_point<T>::value>::type
    scan() {
        double _x, _y;
        scanf("%lf%lf", &_x, &_y);
        x = _x;
        y = _y;
    }

    template<typename T = TI>
    typename std::enable_if<std::is_integral<T>::value>::type
    scan() {
        ll _x, _y;
        scanf("%lld%lld", &_x, &_y);
        x = _x;
        y = _y;
    }

    template<typename T = TI>
    typename std::enable_if<std::is_floating_point<T>::value>::type
    print() {
        printf("%.10lf %.10lf\n", (double)x, (double)y);
    }

    template<typename T = TI>
    typename std::enable_if<std::is_integral<T>::value>::type
    print() {
        printf("%lld %lld\n", (ll)x, (ll)y);
    }
};

using point = generic_point<double, double>;

const int IT = 45;

point a[3];

double solveXY(const point& p1, const point& p2, const point& p3, double x, double y) {
    point p(x, y);
    return p.dist(p1) + p.dist(p2) + p.dist(p3);
}

double solveY(const point& p1, const point& p2, const point& p3, double x) {
    double l = -1e4, r = 1e4;
    for (int it = 0; it < IT; ++it) {
        double m1 = (2 * l + r) / 3.0;
        double m2 = (l + 2 * r) / 3.0;

        if (solveXY(p1, p2, p3, x, m1) > solveXY(p1, p2, p3, x, m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }

    return solveXY(p1, p2, p3, x, (l + r) / 2.0);
}

double solve(const point& p1, const point& p2, const point& p3) {
    double l = -1e4, r = 1e4;
    for (int it = 0; it < IT; ++it) {
        double m1 = (2 * l + r) / 3.0;
        double m2 = (l + 2 * r) / 3.0;

        if (solveY(p1, p2, p3, m1) > solveY(p1, p2, p3, m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }

    return solveY(p1, p2, p3, (l + r) / 2.0);
}

double calc(double x, double y) {
    point p(x, y);
    
    double ans = 0.0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < i; ++j) {
            smax(ans, solve(p, a[i], a[j]));
        }
    }

    return ans;
}

double findY(double x) {
    double l = -1e4, r = 1e4;
    for (int it = 0; it < IT; ++it) {
        double m1 = (2 * l + r) / 3.0;
        double m2 = (l + 2 * r) / 3.0;

        if (calc(x, m1) > calc(x, m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }

    return calc(x, (l + r) / 2.0);
}

double findX() {
    double l = -1e4, r = 1e4;
    for (int it = 0; it < IT; ++it) {
        double m1 = (2 * l + r) / 3.0;
        double m2 = (l + 2 * r) / 3.0;

        double res1 = findY(m1);
        double res2 = findY(m2);

        if (res1 > res2) {
            l = m1;
        } else {
            r = m2;
        }
    }

    return findY((l + r) / 2.0);
}

void run() {
    for (int i = 0; i < 3; ++i) {
        a[i].scan();
    }

    printf("%.10lf\n", findX());
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}