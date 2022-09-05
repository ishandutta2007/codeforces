#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <set>

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

struct PointLine {
    Point a, b;
};

int compare(Point p1, Point p2) {
    if (p1.x < p2.x) {
        return -1;
    }
    if (p1.x > p2.x) {
        return 1;
    }
    if (p1.y < p2.y) {
        return -1;
    }
    if (p1.y > p2.y) {
        return 1;
    }
    return 0;
}

struct PointCompare {
    bool operator()(const Point& p1, const Point& p2) const {
        return compare(p1, p2) < 0;
    }
};

template<class T>
T gcd(T x, T y) {
    x = std::abs(x);
    y = std::abs(y);
    while (y != T()) {
        T t = y;
        y = x % y;
        x = t;
    }
    return x;
}

struct Solution {
    size_t n;
    std::vector<PointLine> lines;

    bool intersect(const PointLine& l1, const PointLine& l2, Point& inter) {
        int64_t a1 = l1.b.y - l1.a.y;
        int64_t a2 = l1.a.x - l1.b.x;
        int64_t a3 = a1 * l1.a.x + a2 * l1.a.y;

        int64_t b1 = l2.b.y - l2.a.y;
        int64_t b2 = l2.a.x - l2.b.x;
        int64_t b3 = b1 * l2.a.x + b2 * l2.a.y;

        int64_t det = b2 * a1 - b1 * a2;
        if (det == 0) {
            return false;
        }
        int64_t x = b2 * a3 - b3 * a2;
        int64_t y = b3 * a1 - b1 * a3;
        if (det < 0) {
            det = -det;
            x = -x;
            y = -y;
        }
        if (x % det != 0 || y % det != 0) {
            return false;
        }
        x /= det;
        y /= det;
        if (x < std::min(l1.a.x, l1.b.x) || x > std::max(l1.a.x, l1.b.x)) {
            return false;
        }
        if (x < std::min(l2.a.x, l2.b.x) || x > std::max(l2.a.x, l2.b.x)) {
            return false;
        }
        if (y < std::min(l1.a.y, l1.b.y) || y > std::max(l1.a.y, l1.b.y)) {
            return false;
        }
        if (y < std::min(l2.a.y, l2.b.y) || y > std::max(l2.a.y, l2.b.y)) {
            return false;
        }
        inter.x = x;
        inter.y = y;
        return true;
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n;
        lines.resize(n);
        for (size_t i = 0; i < n; i++) {
            in >> lines[i].a.x >> lines[i].a.y >> lines[i].b.x >> lines[i].b.y;
        }
        std::set<Point, PointCompare> points;
        int64_t res = 0;
        for (int i = 0; i < n; i++) {
            int d1 = std::abs(lines[i].a.x - lines[i].b.x);
            int d2 = std::abs(lines[i].a.y - lines[i].b.y);
            int d = gcd(d1, d2);
            int all_points = d + 1;
            points.clear();
            Point inter;
            for (int j = i + 1; j < n; j++) {
                if (intersect(lines[i], lines[j], inter)) {
                    points.insert(inter);
                }
            }
            all_points -= points.size();
            res += all_points;
        }
        out << res << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}