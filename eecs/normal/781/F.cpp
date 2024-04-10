#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
const double EPS = 1e-9;
int n, m;
double diff;

struct P {
    double x, y;
    P(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    P operator + (const P &o) const { return P(x + o.x, y + o.y); }
    P operator - (const P &o) const { return P(x - o.x, y - o.y); }
    P operator * (const double &o) const { return P(x * o, y * o); }

    double operator * (const P &o) const { return x * o.x + y * o.y; }
    double operator / (const P &o) const { return abs(o.x) > EPS ? x / o.x : y / o.y; }
    bool operator == (const P &o) const { return abs(x - o.x) < EPS && abs(y - o.y) < EPS; }

    double dist() { return sqrt(x * x + y * y); }
    P norm() { double o = dist(); return P(x / o, y / o); }
} a[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &a[i].x, &a[i].y), a[i + n] = a[i];
    }
    for (int i = 0; i < n; i++) {
        diff += (a[i + 1] - a[i]).dist();
    }
    diff /= m;
    auto go = [&](int &x, P &p, double len) {
        if (p == a[x + 1]) x++;
        while (len > EPS) {
            double d = min(len, (a[x + 1] - p).dist());
            len -= d, p = p + (a[x + 1] - p).norm() * d;
            if (p == a[x + 1]) x++;
        }
    };
    auto chk = [&](double D) {
        vector<pair<double, int>> V;
        P px = a[0], py = a[0];
        int x = 0, y = 0;
        double rem = diff;
        for (go(y, py, diff); x ^ n; ) {
            double d = min({rem, (a[x + 1] - px).dist(), (a[y + 1] - py).dist()});
            P s = py - px;
            go(x, px, d), go(y, py, d);
            P t = py - px;
            double l = diff - rem, r = l + d;
            if ((rem -= d) < EPS) rem = diff;
            if (d < EPS) continue;
            if (s.dist() <= D && t.dist() <= D) {
                V.emplace_back(l, 1), V.emplace_back(r, -1); continue;
            }
            P v = t - s;
            swap(v.x, v.y), v.x *= -1;
            P foo = v.norm() * (s * v / v.dist());
            if (foo.dist() > D) continue;
            double bar = sqrt(D * D - foo.dist() * foo.dist());
            double L = (foo - (t - s).norm() * bar - s) / (t - s);
            double R = (foo + (t - s).norm() * bar - s) / (t - s);
            V.emplace_back(l + (r - l) * max(0.0, min(L, 1.0)), 1);
            V.emplace_back(l + (r - l) * max(0.0, min(R, 1.0)), -1);
        }
        sort(V.begin(), V.end());
        int cur = 0;
        for (auto p : V) {
            if ((cur += p.second) == m) return 1;
        }
        return 0;
    };
    double l = 0, r = diff;
    while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        chk(mid) ? r = mid : l = mid;
    }
    printf("%.9f\n", r);
    return 0;
}