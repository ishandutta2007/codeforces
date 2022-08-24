#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct TPoint {
    double x, y, z;
    TPoint()
        : x(0.0)
        , y(0.0)
        , z(0.0)
    {
    }

    TPoint(double _x, double _y, double _z)
        : x(_x)
        , y(_y)
        , z(_z)
    {
    }

    TPoint operator+(TPoint &r) const {
        return TPoint(x + r.x, y + r.y, z + r.z);
    }
    
    TPoint operator-(TPoint &r) const {
        return TPoint(x - r.x, y - r.y, z - r.z);
    }

    TPoint operator*(double a) const {
        return TPoint(x * a, y * a, z * a);
    }
};

double dist(TPoint a, TPoint b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

int main() {
    int n;
    cin >> n;
    vector< TPoint > a(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    double vp, vs;
    TPoint harry;
    cin >> vp >> vs >> harry.x >> harry.y >> harry.z;
    double maxtime = 0.0;
    vector< double > times(n + 1);
    times[0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        times[i] = times[i - 1] + dist(a[i - 1], a[i]) / vs;
    }
    double l = 0.0, r = times[n];
    bool ok = false;
    TPoint res;
    const double EPS = 1e-8;
    while (r - l > 1e-10) {
        double m = 0.5 * (l + r);
        TPoint pos;
        int l1 = 0, r1 = n;
        while (r1 - l1 > 1) {
            int m1 = (l1 + r1) / 2;
            if (times[m1] > m) {
                r1 = m1;
            } else {
                l1 = m1;
            }
        }
        double pr = (m - times[l1]) * vs / dist(a[l1], a[r1]);
        pos = a[l1] + (a[r1] - a[l1]) * pr;
        if (m * vp - dist(harry, pos) > -EPS) {
            r = m;
            res = pos;
            ok = true;
        } else {
            l = m;
        }
    }
    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    printf("YES\n%.10lf\n%.10lf %.10lf %.10lf\n", l, res.x, res.y, res.z);

    return 0;
}