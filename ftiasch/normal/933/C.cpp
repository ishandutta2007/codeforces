#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

template<typename T>
struct Point
{
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    template<typename TT>
    Point<TT> to() const {
        return Point<TT>(x, y);
    }

    Point& operator -= (const Point& o)
    {
        x -= o.x;
        y -= o.y;
        return *this;
    }

    T norm2() const
    {
        return x * x + y * y;
    }

    double norm() const
    {
        return sqrt(static_cast<double>(norm2()));
    }

    Point<double> normalize() const
    {
        auto d = norm();
        return Point<double>(x / d, y / d);
    }

    Point rot() const
    {
        return Point(-y, x);
    }

    T x, y;
};

template<typename T>
Point<T> operator - (Point<T> a, const Point<T>& b)
{
    return a -= b;
}

template<typename T>
Point<T> operator * (const Point<T> &a, double k)
{
    return Point<T>(a.x * k, a.y * k);
}

const int N = 3;
const double EPS = 1e-9;

int n, r[N], parent[N];
Point<int> p[N];

template<typename T>
T sqr(T x)
{
    return x * x;
}

int find(int u)
{
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

int count(const std::vector<Point<double>>& ps)
{
    int result = 0;
    for (size_t i = 0; i < ps.size(); ++ i) {
        size_t j = 0;
        while (std::abs(ps[i].x - ps[j].x) > EPS || std::abs(ps[i].y - ps[j].y) > EPS) {
            j ++;
        }
        result += i == j;
    }
    return result;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d", &p[i].x, &p[i].y, r + i);
        parent[i] = i;
    }
    int result = n + 1;
    std::vector<Point<double>> ps;
    for (int i = 0; i < n; ++ i) {
        std::vector<Point<double>> cps;
        for (int j = 0; j < n; ++ j) {
            if (i == j) {
                continue;
            }
            int d2 = (p[j] - p[i]).norm2();
            if (d2 < sqr(r[i] - r[j]) || sqr(r[i] + r[j]) < d2) {
                continue;
            }
            if (find(i) != find(j)) {
                result --;
                parent[find(i)] = find(j);
            }
            // r[i]^2 - r[j]^2 + d^2 = 2 * d * x
            double x = 0.5 * (d2 + sqr(r[i]) - sqr(r[j])) / sqrt(d2);
            double h = sqrt(std::max(sqr(r[i]) - sqr(x), 0.0));
            Point<double> nv = (p[j] - p[i]).normalize() * -1;
            Point<double> q = p[i].to<double>() - nv * x;
            cps.push_back(q - nv.rot() * h);
            if (d2 < sqr(r[i] + r[j])) {
                cps.push_back(q - nv.rot() * -h);
            }
        }
        result += count(cps);
        for (auto&& p : cps) {
            ps.push_back(p);
        }
    }
    result -= count(ps);
    printf("%d\n", result);
}