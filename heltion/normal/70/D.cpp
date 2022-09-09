#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int sgn(LL x) {
    return x ? (x > 0 ? 1 : -1) : 0;
}
struct Point{
    LL x, y;
    bool operator < (const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
    bool operator == (const Point& p) const {
        return x == p.x and y == p.y;
    }
    Point operator - (const Point& p) const {
        return {x - p.x, y - p.y};
    }
    Point operator - () const {
        return {-x, -y};
    }
    LL cross(const Point& p) const {
        return x * p.y - y * p.x;
    }
    LL dot(const Point& p) const {
        return x * p.x + y * p.y;
    }
    bool turnRight(const Point& p) const{
        return cross(p) < 0 or (cross(p) == 0 and dot(p) < 0);
    };
};
struct Line{
    static int cmp;
    mutable Point A, K;
    bool operator < (const Line& line) const {
        return cmp ? A < line.A : K.turnRight(line.K);
    }
};
int Line::cmp = 1;
struct UpperConvexHull : set<Line>{
    bool contains(const Point& p) const {
        auto it = lower_bound({p, 0});
        if (it != end() and it->A == p) return true;
        if (it != begin() and it != end() and prev(it)->K.cross(p - prev(it)->A) <= 0) return true;
        return false;
    }
    void add(const Point& p) {
        if (contains(p)) return;
        auto it = lower_bound({p, 0});
        for (; it != end(); it = erase(it))
            if ((it->A - p).turnRight(it->K)) break;
        for (; it != begin() and prev(it) != begin(); erase(prev(it)))
            if (prev(prev(it))->K.turnRight(p - prev(prev(it))->A)) break;
        if (it != begin()) prev(it)->K = p - prev(it)->A;
        if (it == end()) insert({p, {0, -1}});
        else insert({p, it->A - p});
    }
};
struct ConvexHull{
    UpperConvexHull up, low;
    bool empty() const {
        return up.empty();
    }
    bool contains(const Point& p) const {
        Line::cmp = 1;
        return up.contains(p) and low.contains(-p);
    }
    void add(const Point& p) {
        Line::cmp = 1;
        up.add(p);
        low.add(-p);
    }
    bool isIntersect(LL A, LL B, LL C) const {
        Line::cmp = 0;
        if (empty()) return false;
        Point k = {-B, A};
        if (k.x < 0) k = -k;
        if (k.x == 0 and k.y < 0) k.y = -k.y;
        Point P = up.upper_bound({{0, 0}, k})->A, Q = -low.upper_bound({{0, 0}, k})->A;
        return sgn(A * P.x + B * P.y - C) * sgn(A * Q.x + B * Q.y - C) > 0;
    }
    friend ostream& operator << (ostream& out, const ConvexHull& ch) {
        for (const auto& line : ch.up) out << "(" << line.A.x << "," << line.A.y << ")"; cout << "/";
        for (const auto& line : ch.low) out << "(" << -line.A.x << "," << -line.A.y << ")";
        return out;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int q;
    cin >> q;
    ConvexHull ch;
    for (int i = 0, op, x, y; i < q; i += 1) {
        cin >> op >> x >> y;
        if (op == 1) ch.add({x, y});
        else cout << (ch.contains({x, y}) ? "YES\n" : "NO\n");
    }
}